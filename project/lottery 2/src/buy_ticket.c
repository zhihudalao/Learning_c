#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include"buy_ticket.h"
#include"user.h"
#include"issue_lottery.h"


void bet_now(buy_lty*bdata);//下注
void automatic(buy_lty*bdata,int n);//自动生成投注号码
void manual(buy_lty*,int);//手动输入投注号码
void create_lty_ID(blty_lk*,buy_lty*);//彩票ID
/**************************购买彩票**************/
void buy_ticket(ulink*personal,lty_lk*lty_head,blty_lk*blty_head)
{
	buy_lty blty_data_temp;
	buy_lty*bdata = &blty_data_temp;
	lty_lk*pre = lty_head;
	char NowTime[30] = "";
	int buy_num_err = 0;
	int i = 0,j = 0;
	if(lty_head == NULL)
	{
		printf("彩票发行头节点为空\n");
		exit(1);
	}
	if(blty_head == NULL)
	{
		printf("购彩头节点为空\n");
		exit(1);
	}

	while(lty_head->lty_next != NULL)//找到最新发行的彩票
	{
		lty_head = lty_head->lty_next;
	}


	if(lty_head->lty_data.is_run || (pre->lty_next == NULL))//判断新一期彩票是否开奖，是否为第一次发行彩票
	{
		printf("本期已开奖,不能购买彩票，请等待下一期发行\n");
		printf("按ENTER返回");
		while(getchar()!='\n');
		return;
	}else
	{	while(1)
		{
			printf("本期彩票期号:%d\t本期彩票单价:%d\t",lty_head->lty_data.code,lty_head->lty_data.unit_price);
			printf("账户余额:%.2f\n",personal->data.money);
			printf("请输入需要购买本期彩票的注数(1-5):");

			scanf("%d",&blty_data_temp.buy_num);/******购买注数***********/

			if(blty_data_temp.buy_num < 1 || blty_data_temp.buy_num>5||getchar()!='\n')
			{
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
		while(1)
		{
			printf("请输入投注倍数:");
			scanf("%d",&blty_data_temp.multiple);
			if(blty_data_temp.multiple<=0||getchar()!='\n')
			{
				printf("请正确输入倍数!");
				while(getchar()!='\n');
			}else
			{

				break;
			}
		}
		if(personal->data.money-(blty_data_temp.buy_num)*(lty_head->lty_data.unit_price)*(blty_data_temp.multiple)<0)//计算余额
		{
			printf("您的余额不足,请充值");
			getchar();
			while(getchar()!='\n');
			return;
		}else
		{
		bet_now(bdata);//下注-----传指针
		now_time(NowTime);//购买时间
		blty_data_temp.tkt_code = lty_head->lty_data.code;//彩票期号
		create_lty_ID(blty_head,bdata);//彩票ID
		blty_data_temp.is_win = 0;//中奖状态
		blty_data_temp.win_amount = 0;//中奖金额
		strcpy(blty_data_temp.user_name,personal->data.name);//购买者帐号
		strcpy(blty_data_temp.buy_time,NowTime);//购买时间复制

		lty_head->lty_data.num_of_lty += blty_data_temp.buy_num;//本期售出总数增加now_time(NowTime);//购买时间

		lty_head->lty_data.sum_lty += (blty_data_temp.buy_num)*(lty_head->lty_data.unit_price)*(blty_data_temp.multiple);//奖池更新
		/*奖池 += 注数 * 单价 * 倍数	*/
		personal->data.money -= (blty_data_temp.buy_num)*(lty_head->lty_data.unit_price)*(blty_data_temp.multiple);//用户余额更新
		/*余额 -= 注数 * 单价 * 倍数	*/

		}
	}
	insert_after_blty(blty_head,blty_data_temp);//新节点
	/**********购买信息显示***********/
	system("clear");
	printf("\n\n\n\n———————————————————————————————————————————————————\n");
	printf("您本次购买彩票的信息为:\n");
	printf("期号:%d\t购买日期:%s",blty_data_temp.tkt_code,blty_data_temp.buy_time);
	printf("投注金额:%d\t",(blty_data_temp.buy_num)*(lty_head->lty_data.unit_price)*(blty_data_temp.multiple));
	printf("投注倍数:%d\n",blty_data_temp.multiple);
	printf("彩票投注号:\n");
	for(i=0;i<blty_data_temp.buy_num;i++)
	{
		printf("%c>\t",'A'+i);
		for(j=0;j<3;j++)
		{

			printf("%d ",blty_data_temp.own_ticket[i][j]);
		}
		printf("\n");

	}
	printf("———————————————————————————————————————————————————\n");
	printf("购买成功\n");
	printf("按ENTER返回");
	while(getchar()!='\n');
}
/********************************下注*********************************/
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
		bdata->own_ticket[n][i] = random()%SCOPE;//随机值
		printf("%d ",bdata->own_ticket[n][i]);
	}
	printf("\n");
	printf("按ENTER继续\n");
	while(getchar()!='\n');
}
/******************************手动自选彩票号码***********************/
void manual(buy_lty*bdata,int n)
{
	int i = 0;
	printf("请在0-%d数字中选择三个数字:\n",SCOPE-1);
	for(i=0;i<3;i++)
	{
		scanf("%d",&bdata->own_ticket[n][i]);//不能为负数，不大与范围上限，不能为其他字母等字符
		if(bdata->own_ticket[n][i]<0 || bdata->own_ticket[n][i]>SCOPE-1 || getchar()!='\n')
		{
			printf("\033[01;31m输入错误,请重新输入第\033[45m%d\033[0m\033[01;31m个号码:\033[0m\n",i+1);
			while(getchar()!='\n');
			i--;

		}
	}
	printf("\n");
	getchar();
	printf("按ENTER继续\n");

	//while(getchar()!='\n');

}
/****************************彩票的ID**********************************/
void create_lty_ID(blty_lk*blty_head,buy_lty*bdata)
{
	char array[10] = "";//格式：A B 0 1 a b 2 3 E F
	srand(time(NULL));
	blty_head = blty_head->blty_next;
	while(1)
	{
		array[0] = 65+random()%26;//大写字母
		array[1] = 65+random()%26;//大写字母
		array[2] = 48+random()%10;//数字
		array[3] = 48+random()%10;//数字
		array[4] = 97+random()%26;//小写字母
		array[5] = 97+random()%26;//小写字母
		array[6] = 48+random()%10;//数字
		array[7] = 48+random()%10;//数字
		array[8] = 65+random()%26;//大写字母
		array[9] = 65+random()%26;//大写字母
		while(blty_head != NULL)//标识唯一
		{
			if(strcmp(array,blty_head->blty_data.tkt_ID) == 0)
			{
				break;
			}
			blty_head = blty_head->blty_next;
		}
		if(blty_head == NULL)
			{break;}
	}

	strcpy(bdata->tkt_ID,array);

}
