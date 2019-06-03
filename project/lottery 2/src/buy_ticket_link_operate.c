#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"issue_lottery.h"
#include"buy_ticket.h"

/**********************从链表后端插入************************************/
void insert_after_blty(blty_lk*blty_head,buy_lty blty_data)
{
	blty_lk*new;
	if(blty_head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	while(blty_head->blty_next != NULL)
	{
		blty_head = blty_head->blty_next;
	}
	new = create_blty(blty_data);
	blty_head->blty_next = new;
}
/**********************申请新空间并将数据保存到链表中**********************/
blty_lk*create_blty(buy_lty blty_data)
{
	blty_lk *new = calloc(1,sizeof(blty_lk));
	new->blty_data = blty_data;
	new->blty_next = NULL;
	return new;
}
/**********************释放空间*******************************/
void free_blty(blty_lk*blty_head)
{
	if(blty_head == NULL)
	{
		printf("购彩头节点为空\n");
		exit(1);
	}
	while(blty_head != NULL)
	{
		blty_lk*save = blty_head->blty_next;
		free(blty_head);
		blty_head = save;
	}
	blty_head = NULL;
}


/************************************彩票遍历打印***************************/
void print_blty(blty_lk *blty_head)
{
	int i = 0,j = 0;
	if(blty_head == NULL)
	{
	printf("头节点错\n");
		exit(1);
	}
	if(blty_head->blty_next == NULL)
	{
		printf("\033[01;31m未查到购买彩票信息\033[0m");
		return;
	}
	blty_head=blty_head->blty_next;
	while(blty_head != NULL)
	{
		printf("——————————————————————————————————————————————————————————\n");
		printf("期号:%d\n",blty_head->blty_data.tkt_code);
		printf("ID:%s\t时间:%s",blty_head->blty_data.tkt_ID,blty_head->blty_data.buy_time);
		printf("购买者帐号:%s\t购买注数:%d\t",blty_head->blty_data.user_name,blty_head->blty_data.buy_num);
		printf("倍数:%d\n",blty_head->blty_data.multiple);
		printf("彩票号码:\n");
		for(i=0;i<blty_head->blty_data.buy_num;i++)
		{
			printf("%d\t",i+1);
			for(j=0;j<3;j++)
			{
				printf("%d ",blty_head->blty_data.own_ticket[i][j]);
			}
			printf("\n");
		}
		if(blty_head->blty_data.is_win)
		{
			printf("中奖状态: 已中奖\t中奖金额: %d\n",blty_head->blty_data.win_amount);
		}else
		{
			printf("中奖状态: 未中奖\t中奖金额: %d\n",blty_head->blty_data.win_amount);
		}
		printf("——————————————————————————————————————————————————————————\n");
		blty_head = blty_head->blty_next;
	}

}
/**********************************排序*********************************/
void sort_buy(blty_lk* blty_head)
{
	int i = 0,j = 0;
	blty_lk* Hd = blty_head;
	if(Hd == NULL)
	{
		printf("头节点为空\n");
		return ;
	}
	int length = 0;
	Hd = Hd ->blty_next;//头节点不做排序
	while(Hd != NULL)
	{
		Hd = Hd->blty_next;
		length++;
	}
	Hd = blty_head->blty_next;
	for(i = 0;i<length;i++)
	{
		Hd = blty_head->blty_next;
		for(j = 0;j<length-i-1;j++)
		{
			if(Hd->lty_data.money < Hd->blty_next->lty_data.money)
			{

				lty lty_data = Hd->lty_data;
				Hd->lty_data = Hd->blty_next->lty_data;
				Hd->blty_next->lty_data = lty_data;
			}
			Hd = Hd->blty_next;
		}
	}
}

/**************************选择其中已购买的彩票**************************/
blty_lk*select_blty(blty_lk*blty_head,char*name)
{
	blty_lk *pre = blty_head;
	blty_head = blty_head->blty_next;
	while(blty_head!=NULL)
	{
		if(strcmp(blty_head->blty_data.user_name,name)==0)
			return pre;
		pre = blty_head;
		blty_head = blty_head->blty_next;
	}
	return NULL;
}

/*************************需要删除时用户键入入************************
void del_lty(blty_lk *blty_head)
{
	char ID[20];
	printf("请输入要删除的用户姓名\n");
	scanf("%s",ID);
	delete_lty(blty_head,ID);
}
/****************************删除用户**********************/
void delete_lty(blty_lk *blty_head,char *ID)
{
	if(is_null(blty_head))
		return;
	blty_lk *pre = select(blty_head,ID);
	if(pre == NULL)
	{
		printf("查无此人\n");
		return;
	}
	pre->blty_next = pre->blty_next->blty_next;
}
