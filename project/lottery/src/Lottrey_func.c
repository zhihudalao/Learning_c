#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>
#include "lotLink.h"
#include "userLink.h"
#include "Lottrey_func.h"
#include "LotRecord.h"

/*
函数名：adminLogin
函数功能：管理员登录用
返回值：void
*/
void adminLogin(){
	char name[50]="admin123";
	char pswd[50]="123456";
	char _name[50];
	char _pswd[50];
	int flag=0;
	while(1){
		printf("************************\n");
		printf("请输入账号:");
		scanf("%s",_name);
		while(getchar()!='\n');
		printf("请输入密码:");

		shadow_pswd(_pswd);
		if(strcmp(name,_name)==0 && strcmp(pswd,_pswd)==0){
			flag=1;
		}
		if(flag==1){
      printf("************************\n");
      printf("\n登陆成功\n");
			break;
		}else{printf("\n账号或密码错误\n");}

	}
}
/*
函数名：userLogin
函数功能：用户登录用
返回值：成功0 失败1
*/
int userLogin(User*head){
	if(head==NULL){return 1;}
	int name=0;
	int flag=0;
	int flag_=0;
	int count=0;
	int count_=0;
	int count1=0;
	char pswd[20]={'\0'};
	while(1){
				printf("************************\n");
				printf("请输入账号\n");
				scanf("%d",&name);
				while(getchar()!='\n');
				flag=ifname(head,name);
				if(flag==0){
					break;
				}
				printf("************************\n");
				printf("用户名不存在\n");
				printf("请重新输入\n");
				count1++;
				if(count1==3){return 1;}
			}
	User*p=find_link(head,name);
	while(1){
			printf("************************\n");
			printf("请输入密码\n");
			shadow_pswd(pswd);
			if(strcmp(p->data.pswd,pswd)==0){
				return name;
			}
			printf("************************\n");
			printf("密码错误\n");
			count++;
			if(count==3){
				flag_=ver_code();
				count_++;
			}
			if(count_==3){
				return 1;
			}
		}

		return 0;
}
/*
函数名：insertLot
函数功能：插入彩票
返回值：void
*/
void  insertLot(Lot* head){
	assert(head);
	lty data;
	data.name = 0;//期号
	data.prize = 0;//单价
	data.run = 0;//是否已经开奖
	data.lotNum[20]=0;//中奖号码
	data.numLot = 0;//本期售出总数
	data.money = 0;//本期奖池总额
	int name=19001;//期号
	Lot*p= head;
	if(head == NULL){
		printf("彩票发行头节点为空\n");
		return ;
	}
	while(p->next!=NULL)//寻找最新一期
	{
		p = p->next;
		name++;
	}
	if(head->next == NULL){//第一次发布区别
		printf("请输入彩票单价\n");
		scanf("%d",&data.prize);
		data.name=name;
		data.run = 0;//开奖状态
		data.numLot = 0;//本期售出总数
		data.money = 1000000;//奖池
		insert_after_lty(head,data);//发行链表操作
	}else{
		if(!p->data.run){//判断上一期开奖状态
				printf("上期彩票未开奖,您无权发行新一期彩票\n");
				printf("按ENTER返回\n");
				while(getchar()!='\n');
				return ;
			}else
		{
			printf("请输入彩票单价(1-10元)\n");
			scanf("%d",&data.prize);
			if(data.prize<1||data.prize>10)//单价
			{
				printf("输入价格错误");
				printf("按ENTER返回\n");
				getchar();
				while(getchar()!='\n');
				return ;
			}
			data.name = name;
			data.numLot = 0;//注
			data.run = 0;//开奖状态
			data.money = p->data.money;//奖池
			Lot*p=insertNewLot();
			appendLotlink(head,p);
			p->data=data;
		}
	}
	printf("本次发行的彩票信息:\n");
	printf("期号:%d  单价:%d\t",data.name,data.prize);
	printf("奖池总额:%d\n",data.money);

	printf("彩票发行成功\n");
	printf("按ENTER返回\n");
	getchar();
	while(getchar()!='\n');
	return ;
}
/*
函数名：findUser
函数功能：找到用户账号
返回值：
*/
int findUser(User*head,int id ){

	User*p=find_link(head,id);
	if(head==NULL||p==NULL){
		printf("用户不存在，ENTER返回\n");
		while(getchar()!='\n');
		return 1;}
	printf("%s ",p->data.name);
	printf("%d ",p->data.id);
	printf("%g\n",p->data.account);
	return 0;
}
/*
函数名：insterUser
函数功能：彩民注册
返回值：成功 0,失败1
*/
int insterUser(User*head){
	User* p= insertNewUser();

	User* q=head->next;
	int id=180701;
	User* pp=head->next;
	while (pp!=NULL) {
		pp=pp->next;
		id++;
	}
	char name[20];
	char pswd[20];
	char pswd_[20];
	printf("请输入用户名");
	scanf("%s",name);
	while (getchar()!='\n');
	while(q!=NULL){
		if(strcmp(q->data.name,name)==0){
			printf("该用户已注册\n");
			free(p);
			return 1;
		}
		q=q->next;
	}
	printf("请输入密码\n");
	shadow_pswd(pswd);
	printf("\n请再次输入密码\n");
	shadow_pswd(pswd_);
	if(strcmp(pswd,pswd_)!=0){
		printf("\n两次输入不一致\n");
		free(p);
		return 1;
	}
	printf("\n注册成功\n");
	append_link(head,p);
	strcpy(p->data.name,name);
	strcpy(p->data.pswd,pswd);

	p->data.id=id;
	printf("登陆id:%d\n",p->data.id);
	return 0;
}
/*
函数名：altPswd
函数功能：更改密码
返回值：成功 0 失败 1
*/
int altPswd(User* head,int id ){
	User*p=find_link(head,id);
	char old_pswd[20];
	char pswd[20];
	char pswd_[20];
	printf("请输入旧密码\n");
	shadow_pswd(old_pswd);
	if(strcmp(p->data.pswd,old_pswd)!=0){
		printf("\n旧密码不正确\n");
		printf("按Enter返回");
		while(getchar()!='\n');
		return 0;
	}
	printf("\n密码正确请输入新密码\n");
	printf("请输入修改密码\n");
	shadow_pswd(pswd);
	printf("\n请再次输入密码\n");
	shadow_pswd(pswd_);
	if(strcmp(pswd,pswd_)!=0){
		printf("\n两次输入密码不同\n");
		printf("按Enter返回");
		while(getchar()!='\n');
		return 0;
	}
	strcpy(p->data.pswd,pswd);
	printf("\n修改成功\n");
	sleep(2);
	return 1;
}
/*
函数名：payAccount
函数功能：充值
返回值：
*/
int payAccount(User*head){
	int id;
	printf("请输入id \n");
	scanf("%d",&id);
	User*p=find_link(head,id);
	if(p == NULL){
		printf("用户不存在，ENTER返回\n");
		while(getchar()!='\n');
		return 1;
	}else{
		float mny = 0;
		printf("当前余额:%g\n",p->data.account);
		while(1){
			printf("请输入要充值的金额(最小金额:1元):\n");
			scanf("%f",&mny);
			if(getchar()!='\n'){
				printf("输入错误\n");
				while(getchar()!='\n');
				continue;
			}
			if(mny<1){
				printf("请重新输入充值金额(至少1元)\n");
				continue;
			}
			else{
				p->data.account += mny;
				printf("充值成功\n");
				printf("账户余额为：%g 元\n",p->data.account);
				sleep(2);
				return 0;
			}
		}
	}
}

void buy_ticket(Lot*lty_head,LotRec*blty_head,User* personal){
	buy_lty blty_data_temp;
	buy_lty*bdata = &blty_data_temp;
	Lot*pre = lty_head;
	char NowTime[30] = "";
	int buy_num_err = 0;
	int i = 0,j = 0;
	if(lty_head == NULL){
		printf("彩票发行头节点为空\n");
		return;
	}
	if(blty_head == NULL)	{
		printf("购彩头节点为空\n");
		return ;
	}

	while(lty_head->next != NULL)//找到最新发行的彩票
	{
		lty_head = lty_head->next;
	}


	if(lty_head->data.run || (pre->next == NULL))//判断新一期彩票是否开奖，是否为第一次发行彩票
	{
		printf("本期已开奖,不能购买彩票，请等待下一期发行\n");
		printf("按ENTER返回");
		while(getchar()!='\n');
		return;
	}else{
		while(1){
			printf("本期彩票期号:%d\t本期彩票单价:%d\t",lty_head->data.name,lty_head->data.prize);
			printf("账户余额:%.2f\n",personal->data.account);
			printf("请输入需要购买本期彩票的注数(1-5):");
			scanf("%d",&blty_data_temp.buy_num);/******购买注数***********/
			if(blty_data_temp.buy_num < 1 || blty_data_temp.buy_num>5||getchar()!='\n'){
				while(getchar()!='\n');
				printf("输入错误,请重新输入:\n");
				if((buy_num_err++)>=4)
{
					printf("输入错误已达5次，将退出购买彩票");
					sleep(2);
					return;
				}
			}else{break;}
		}
		while(1){
			printf("请输入投注倍数:");
			scanf("%d",&blty_data_temp.multiple);
			if(blty_data_temp.multiple<=0||getchar()!='\n'){
				printf("请正确输入倍数!");
			}else{break;}
		}
		if(personal->data.account-(blty_data_temp.buy_num)*(lty_head->data.prize)*(blty_data_temp.multiple)<0)//计算余额
		{
			printf("您的余额不足,请充值");
			return;
		}else{
		bet_now(bdata);//下注-----传指针
		now_time(NowTime);//购买时间
		blty_data_temp.tkt_code = lty_head->data.name;//彩票期号
		create_lty_ID(blty_head,bdata);//彩票ID
		blty_data_temp.is_win = 0;//中奖状态
		blty_data_temp.win_amount = 0;//中奖金额
		blty_data_temp.userId=personal->data.id;//购买者帐号
		strcpy(blty_data_temp.buy_time,NowTime);//购买时间复制

		lty_head->data.numLot += blty_data_temp.buy_num;//本期售出总数增加now_time(NowTime);//购买时间

		lty_head->data.money += (blty_data_temp.buy_num)*(lty_head->data.prize)*(blty_data_temp.multiple);//奖池更新
		/*奖池 += 注数 * 单价 * 倍数	*/
		personal->data.account -= (blty_data_temp.buy_num)*(lty_head->data.prize)*(blty_data_temp.multiple);//用户余额更新
		/*余额 -= 注数 * 单价 * 倍数	*/
		}
	}
	insert_after_blty(blty_head,blty_data_temp);//新节点
	/**********购买信息显示***********/
	printf("\n\n\n\n———————————————————————————————————————————————————\n");
	printf("您本次购买彩票的信息为:\n");
	printf("期号:%d\t购买日期:%s",blty_data_temp.tkt_code,blty_data_temp.buy_time);
	printf("投注金额:%d\t",(blty_data_temp.buy_num)*(lty_head->data.prize)*(blty_data_temp.multiple));
	printf("投注倍数:%d\n",blty_data_temp.multiple);
	printf("彩票投注号:\n");
	for(i=0;i<blty_data_temp.buy_num;i++)
	{
		printf("%c>\t",'A'+i);
		for(j=0;j<3;j++){
			printf("%d ",blty_data_temp.own_ticket[i][j]);
		}
		printf("\n");
	}
	printf("———————————————————————————————————————————————————\n");
	printf("购买成功\n");
	printf("按ENTER返回");
	while(getchar()!='\n');
}
void bet_now(buy_lty*bdata)
{
	int i = 0;
	int choose = -1;
	for(i=0;i<bdata->buy_num;i++)//购买注数
	{
		choose = -1;
		printf("第%d注\n",i+1);
		printf("1.机选一注\t2.自选一注\n");
		scanf("%d",&choose);
		if(getchar()!='\n')
		{
			while(getchar()!='\n');
			printf("输入错误,请重新输入\n");
			i--;

		}else
		{
			switch(choose)
			{

			case 1:
				automatic(bdata,i);//机选一注
				break;
			case 2:
				manual(bdata,i);//自选一注
				break;
			default:
				printf("输入错误,请重新选择");
				i--;
				break;
			}
		}

	}
}
/**************************机选彩票号码********************/
void automatic(buy_lty*bdata,int n)
{
	int i = 0;
	srand(time(NULL));
	printf("第%d注号码:",n+1);
	for(i=0;i<3;i++)
	{
		bdata->own_ticket[n][i] = random()%5;//随机值

		printf("%d ",bdata->own_ticket[n][i]);
	}
	printf("\n");
	printf("按ENTER继续\n");
	while(getchar()!='\n');
}
/******************************手动自选彩票号码***********************/
void manual(buy_lty*bdata,int n){
	int i = 0;
	printf("请在0-4数字中选择三个数字:\n");
	for(i=0;i<3;i++){
		scanf("%d",&bdata->own_ticket[n][i]);//不能为负数，不大与范围上限，不能为其他字母等字符
		if(bdata->own_ticket[n][i]<0 || bdata->own_ticket[n][i]>4 || getchar()!='\n'){
			printf("输入错误,请重新输入第%d个号码:\n",i+1);
			while(getchar()!='\n');
			i--;

		}
	}
	printf("\n");
}
/****************************彩票的ID**********************************/
void create_lty_ID(LotRec*blty_head,buy_lty*bdata){
	int id= 201901;
	srand(time(NULL));
	blty_head = blty_head->next;
	while(1){

		while(blty_head != NULL)//标识唯一
		{
			if(id==blty_head->data.tkt_ID){
				break;
			}
			blty_head = blty_head->next;
			id++;
		}
		if(blty_head == NULL)
			{break;}
	}

	bdata->tkt_ID=id;

}
/***********************************开奖**************************/
void run_lottery(User*user_head,Lot*lty_head,LotRec*blty_head){
	char ch = 0;
	Lot*pre = lty_head;
	if(lty_head == NULL){
		printf("发行彩票链表头节点为空\n");
		exit(1);
	}
	while(lty_head->next != NULL){
		lty_head = lty_head->next;//最新的一期

	}
		/********上一期已开奖，第一期还未发行********/
	if((lty_head->data.run) || (pre->next == NULL)){
		printf("最新一期彩票已经开奖,请等待下一期彩票发行\n");
		printf("按ENTER返回");
		while(getchar()!='\n');
		return;
	}else{
		printf("按y进行开奖,其他键退出\n");
		ch = getchar();
		if(ch == 'y' || ch == 'Y'){
			lty_head->data.run = 1;//已开奖标志置1
			greate_luky_num(lty_head);//生成幸运号码
			winner(user_head,lty_head,blty_head);//奖金派发,奖池更新
		}else{
			return;
		}
	}
	printf("开奖成功\n");
	printf("按ENTER返回");
	while(getchar()!='\n');
}

/********************生成幸运号码***********************/
/*void greate_luky_num(Lot*lty_head){
	int i = 0;
	int n = 0;
	int ch[20] = {};
	srand(time(NULL));
	while(getchar()!='\n');
	for(i=0;i<3;i++){

		printf("按ENTER生成第%d个幸运数字\n",i+1);
		while(getchar()!='\n');
		while(n<100000){
			ch[i] = random()%5;
			printf("\033[01;31m\r%d\033[0m",ch[i]);//随机生成的数字覆盖
			n++;
		}
		n = 0;
		printf("\n");
	}
	printf("本次开奖结果为:");
	for(i=0;i<3;i++){
		printf("\033[01;33;41m%d \033[0m",ch[i]);
		lty_head->data.lotNum[i] = ch[i];
	}
}
*/
void greate_luky_num(Lot*lty_head){
	int i = 0;
	int n = 0;
	int ch[20] = {};
	for(i=0;i<3;i++){
			ch[i] =1;
			printf("\033[01;31m\r%d\033[0m",ch[i]);//随机生成的数字覆盖
			n++;
		}
		n = 0;
		printf("\n");

	printf("本次开奖结果为:");
	for(i=0;i<3;i++){
		printf("\033[01;33;41m%d \033[0m",ch[i]);
		lty_head->data.lotNum[i] = ch[i];
	}
}
