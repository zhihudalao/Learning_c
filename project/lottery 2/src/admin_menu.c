#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<user.h>
#include<issue_lottery.h>
#include<unistd.h>

void qry_user_byname(ulink*user_head);//姓名排序
void qry_user_bymoney(ulink*user_head);//余额排序
void data_statistic(ulink*uhead);//统计用户账户余额

//按余额排序在链表操作中实现

/**********************************充值*************************/
void recharge(ulink*user_head)
{
	user data;
	ulink*pre;
	printf("请输入要充值的用户:");
	scanf("%s",data.name);
	while(getchar()!='\n');
	pre = select_user(user_head,data.name);//寻找用户
	if(pre == NULL)
	{
		printf("用户不存在，ENTER返回\n");
		while(getchar()!='\n');
		return;
	}else
	{
		float mny = 0;
		printf("当前余额:%.2f\n",pre->next->data.money);
		//printf("请输入要充值的金额\n");

		while(1)
		{
			printf("请输入要充值的金额(最小金额:1元):\n");
			scanf("%f",&mny);
			if(getchar()!='\n')
			{
				printf("输入错误\n");
				while(getchar()!='\n');
				continue;
			}

			if(mny<1)
			{
				printf("请重新输入充值金额(至少1元)\n");
				continue;
			}
			else
			{
				pre->next->data.money += mny;
				printf("充值成功\n");
				sleep(2);
				break;
			}
		}
	}
}
/***********************查询用户信息************************/
void qry_user_inf(ulink*user_head)
{
	int choose = -1;
	while(choose != 0)
	{
		choose = -1;
		system("clear");
		printf("\n\n\t\t1.根据用户名查询\n");
		printf("\t\t2.根据用户余额区间查询\n");
		printf("\t\t0.退出\n");
		printf("\t\t请选择:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1://根据用户名查询
				qry_user_byname(user_head);
				break;
			case 2://用户余额区间查询
				qry_user_bymoney(user_head);
				data_statistic(user_head);//柱形图
				while(getchar()!='\n');
				break;
			case 0:
				return;
			default:
				printf("输入错误");
				while(getchar()!='\n');
				while(getchar()!='\n');
				break;

		}
	}
}
/*********************根据用户名查询用户信息*******************/
void qry_user_byname(ulink*user_head)
{
	user data;
	ulink*pre;
	printf("请输入要查询的用户名:");
	scanf("%s",data.name);
	pre = select_user(user_head,data.name);
	while(getchar()!='\n');
	if(pre == NULL)
	{
		printf("用户名不存在,或已注销\n");
		sleep(2);
		return;

	}
	else
	{
		printf("用户名:%s\t余额:%.2f\t注册时间:%s\n",data.name,pre->next->data.money,pre->next->data.regist_time);
		printf("按ENTER返回\n");
		while(getchar()!='\n');
	}
}
/************************根据用户余额区间查询****************/
void qry_user_bymoney(ulink*user_head)
{
	int min = 0,max = 0;
	int num = 0,sum_user = 0;
	float percent = 0;
	printf("请输入余额区间:\n");
	scanf("%d%d",&min,&max);
	user_head = user_head->next;
	if(user_head == NULL)
	{
		printf("暂时还没有用户,请稍后再试\n");
		while(getchar()!='\n');
		while(getchar()!='\n');
		return;

	}
	while(user_head != NULL)
	{
		if(user_head->data.money>min&&user_head->data.money<max)
		{printf("用户名:%s\t余额:%.2f\t注册时间:%s\n",user_head->data.name,user_head->data.money,user_head->data.regist_time);
			num++;//区间人数
		}
		sum_user++;//总人数
		user_head = user_head->next;

	}

	percent = (float)(num)/(float)(sum_user)*100;//百分比
	printf("共计%d人,占总人数的%.2f\n",num,percent);
	getchar();
	while(getchar() != '\n');



}
/************************发行彩票*************************/
int issue_ticket(lty_lk*lty_head)
{
	lty lty_data;
	lty_data.code = 0;//期号
	lty_data.unit_price = 0;//单价
	lty_data.is_run = 0;//是否已经开奖
	lty_data.lucky_num[20] = 0;//中奖号码
	lty_data.num_of_lty = 0;//本期售出总数
	lty_data.sum_lty = 0;//本期奖池总额

	lty_lk*pre = lty_head;
	if(lty_head == NULL)
	{
		printf("彩票发行头节点为空\n");
		exit(1);
	}
	while(pre->lty_next!=NULL)//寻找最新一期
	{
		pre = pre->lty_next;

	}
	if(lty_head->lty_next == NULL)//第一次发布区别
	{
		printf("请输入彩票单价\n");
		scanf("%d",&lty_data.unit_price);
		lty_data.code = 2016001;//期号
		lty_data.is_run = 0;//开奖状态
		lty_data.num_of_lty = 0;//本期售出总数
		lty_data.sum_lty = 1000000;//奖池
		insert_after_lty(lty_head,lty_data);//发行链表操作


	}else
	{
		if(!pre->lty_data.is_run)//判断上一期开奖状态
			{
				printf("上期彩票未开奖,您无权发行新一期彩票\n");
				printf("按ENTER返回\n");
				while(getchar()!='\n');
				return 0;
			}
		else
		{
			printf("请输入彩票单价(1-10元)\n");
			scanf("%d",&lty_data.unit_price);
			if(lty_data.unit_price<1||lty_data.unit_price>10)//单价
			{
				printf("输入价格错误");
				printf("按ENTER返回\n");
				getchar();
				while(getchar()!='\n');
				return 0;
			}
			lty_data.code = pre->lty_data.code+1;//期号
			lty_data.num_of_lty = 0;//注
			lty_data.is_run = 0;//开奖状态
			lty_data.sum_lty = pre->lty_data.sum_lty;//奖池
			insert_after_lty(lty_head,lty_data);
		}
	}
	printf("本次发行的彩票信息:\n");
	printf("期号:%d  单价:%d\t",lty_data.code,lty_data.unit_price);
	printf("奖池总额:%d\n",lty_data.sum_lty);
	printf("彩票发行成功\n");
	printf("按ENTER返回\n");
	getchar();
	while(getchar()!='\n');
	return 1;
}
/*************************开奖状态****************************/
void status(lty_lk*pre)
{
	if(pre->lty_data.is_run)
	{printf("最新一期%d期已开奖,请准备发行下一期\n",pre->lty_data.code);}
	else{printf("最新一期%d期还未开奖\n",pre->lty_data.code);}
	printf("按ENTER返回\n");
	while(getchar()!='\n');
}

/*******************************中奖号码**********************/
void the_lucky_num(lty_lk*pre)
{
	int i = 0;
	if(pre->lty_data.is_run)//开奖状态
	{
		printf("%d期中奖号码为:",pre->lty_data.code);
		for(i=0;i<3;i++)
		{
			printf("%d ",pre->lty_data.lucky_num[i]);
		}
		printf("\n");
	}else
	{
		printf("最新一期%d期未开奖,请耐心等待开奖\n",pre->lty_data.code);
	}
	printf("按ENTER返回\n");
	while(getchar()!='\n');
}

/*********************************售出总数*******************/
void the_sum_of_lty(lty_lk*pre)
{
	if(pre->lty_data.is_run)
	{
		printf("最新一期%d期已开奖,共售出%d注\n",pre->lty_data.code,pre->lty_data.num_of_lty);
	}
	else
	{
		printf("最新一期%d期还未开奖,目前共售出%d注\n",pre->lty_data.code,pre->lty_data.num_of_lty);
	}
	printf("按ENTER返回\n");
	while(getchar()!='\n');
}
/**************************奖池金额********************************/
void the_sum_money(lty_lk*pre)
{
	printf("奖池总额为:%d\n",pre->lty_data.sum_lty);
	printf("按ENTER返回\n");
	while(getchar()!='\n');
}
