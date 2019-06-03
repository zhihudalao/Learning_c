#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include"buy_ticket.h"
#include"issue_lottery.h"
#include"user.h"

void greate_luky_num(lty_lk*);//生成幸运号
void winner(ulink*,lty_lk*,blty_lk*);//本期购买的彩票
void is_win(ulink*,lty_lk*,blty_lk*);//彩票是否中奖
void send_prize(ulink*,lty_lk*,blty_lk*);//派发奖金

/***********************************开奖**************************/
void run_lottery(ulink*user_head,lty_lk*lty_head,blty_lk*blty_head)
{
	char ch = 0;
	lty_lk*pre = lty_head;
	if(lty_head == NULL)
	{
		printf("发行彩票链表头节点为空\n");
		exit(1);
	}
	while(lty_head->lty_next != NULL)
	{
		lty_head = lty_head->lty_next;//最新的一期

	}
		/********上一期已开奖，第一期还未发行********/
	if((lty_head->lty_data.is_run) || (pre->lty_next == NULL))
	{
		printf("最新一期彩票已经开奖,请等待下一期彩票发行\n");
		printf("按ENTER返回");
		getchar();
		while(getchar()!='\n');
		return;
	}else
	{
		printf("按y进行开奖,其他键退出\n");
		while(getchar()!='\n');
		ch = getchar();
		if(ch == 'y' || ch == 'Y')
		{
			lty_head->lty_data.is_run = 1;//已开奖标志置1
			greate_luky_num(lty_head);//生成幸运号码
			winner(user_head,lty_head,blty_head);//奖金派发,奖池更新
		}else
		{
			return;
		}

	}
	printf("开奖成功\n");
	printf("按ENTER返回");
	while(getchar()!='\n');
}

/********************生成幸运号码***********************/
void greate_luky_num(lty_lk*lty_head)
{
	int i = 0;
	int n = 0;
	int ch[20] = {};
	srand(time(NULL));
	while(getchar()!='\n');
	for(i=0;i<3;i++)
	{

		printf("按ENTER生成第%d个幸运数字\n",i+1);
		while(getchar()!='\n');
		while(n<100000)
		{

			ch[i] = random()%SCOPE;
			printf("\033[01;31m\r%d\033[0m",ch[i]);//随机生成的数字覆盖
			n++;
		}
		n = 0;
		printf("\n");
	}
	printf("本次开奖结果为:");
	for(i=0;i<3;i++)
	{
		printf("\033[01;33;41m%d \033[0m",ch[i]);
		lty_head->lty_data.lucky_num[i] = ch[i];
	}
}
/****************************本期所有购买的彩票************************/
void winner(ulink*user_head,lty_lk*lty_head,blty_lk*blty_head)
{
	blty_head = blty_head->blty_next;


	while(blty_head != NULL)
	{
		if(blty_head->blty_data.tkt_code == lty_head->lty_data.code)//期号相同
		{
			is_win(user_head,lty_head,blty_head);//判断这张彩票上的号是否中奖
		}
		blty_head = blty_head->blty_next;
	}
}
/***********************判断彩票是否中奖*********************/
void is_win(ulink*user_head,lty_lk*lty_head,blty_lk*blty_head)
{
	int i = 0,j = 0, n = 0;
	int luky_num[20] = {};
	int num = blty_head->blty_data.buy_num;
	for(i=0;i<3;i++)
	{
		luky_num[i] = lty_head->lty_data.lucky_num[i];//幸运号
	}
	for(i=0;i<num;i++)//注数
	{
		n = 0;
		for(j=0;j<3;j++)//彩票上的每一注3个号码
		{
 			if(blty_head->blty_data.own_ticket[i][j] == luky_num[j])
			{n++;}
		}
		if(n >= 3)			//中奖
		{
			lty_head->lty_data.sum_lty -= BONUS*(blty_head->blty_data.multiple); //奖池更新
			blty_head->blty_data.is_win = 1;//中奖状态
			blty_head->blty_data.win_amount += BONUS*(blty_head->blty_data.multiple);//中奖金额

			send_prize(user_head,lty_head,blty_head);//派发奖金

		}

	}

}
/******************************派发奖金**********************/
void send_prize(ulink*user_head,lty_lk*lty_head,blty_lk*blty_head)//派发奖金
{
	user_head = user_head->next;
	while(user_head != NULL)
	{
		if(strcmp((user_head->data.name),(blty_head->blty_data.user_name)) == 0)
		{
			user_head->data.money += BONUS*(blty_head->blty_data.multiple);//奖金加到用户余额
			return;
		}

		user_head = user_head->next;
	}
	if(user_head == NULL)//如果用户已注销，奖金派发失败，奖金返还奖池
	{
	printf("用户%s已注销无法派奖,奖金将返还奖池",blty_head->blty_data.user_name);
	lty_head->lty_data.sum_lty += BONUS*(blty_head->blty_data.multiple);//奖金返还到奖池
	}
}
