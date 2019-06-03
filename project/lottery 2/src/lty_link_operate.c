#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"issue_lottery.h"


/**********************从链表后端插入************************************/
void insert_after_lty(lty_lk*lty_head,lty lty_data)
{
	lty_lk*new;
	if(lty_head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	while(lty_head->lty_next != NULL)
	{
		lty_head = lty_head->lty_next;
	}
	new = create_lty(lty_data);
	lty_head->lty_next = new;
}
/**********************申请新空间并将数据保存到链表中**********************/
lty_lk*create_lty(lty lty_data)
{
	lty_lk *new = calloc(1,sizeof(lty_lk));
	new->lty_data = lty_data;
	new->lty_next = NULL;
	return new;
}
/**********************释放空间*******************************/
void free_lty(lty_lk*lty_head)
{
	if(lty_head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	while(lty_head!=NULL)
	{
		lty_lk*save = lty_head->lty_next;
		free(lty_head);
		lty_head = save;
	}
	lty_head = NULL;
}


/************************************遍历打印***************************/
void print_lty(lty_lk *lty_head)
{

	if(lty_head == NULL)
	{
	printf("发行头节点错\n");
		return;
	}
	if(lty_head->lty_next == NULL)
	{
		printf("\033[01;31m未查到彩票发行信息\033[0m");
		return;
	}
	lty_head=lty_head->lty_next;

	printf("———————————————————————————————————————————————\n");
	while(lty_head != NULL)
	{
		printf("发行期号:%d\t发行单价:%d\n",lty_head->lty_data.code,lty_head->lty_data.unit_price);
		if(lty_head->lty_data.is_run)
		{
			printf("开奖状态:已开奖\t\t中奖号码为:%d %d %d\n",lty_head->lty_data.lucky_num[0],
				lty_head->lty_data.lucky_num[1],lty_head->lty_data.lucky_num[2]);
			printf("本期售出总数:%d\t本期奖池总额:%d\n",lty_head->lty_data.num_of_lty,lty_head->lty_data.sum_lty);
		}
		else{printf("开奖状态:未开奖\t中奖号码:未开奖\n本期目前已售出总数:%d\t本期总奖池:%d\n",
					lty_head->lty_data.num_of_lty,lty_head->lty_data.sum_lty);}
		printf("———————————————————————————————————————————————\n");
		lty_head = lty_head->lty_next;
	}

}
/**********************************排序*********************************/
void sort_money(lty_lk* lty_head)
{
	int i = 0,j = 0;
	lty_lk* Hd = lty_head;
	if(Hd == NULL)
	{
		printf("头节点为空\n");
		return ;
	}
	int length = 0;
	Hd = Hd ->lty_next;//头节点不做排序
	while(Hd != NULL)
	{
		Hd = Hd->lty_next;
		length++;
	}
	Hd = lty_head->lty_next;
	for(i = 0;i<length;i++)
	{
		Hd = lty_head->lty_next;
		for(j = 0;j<length-i-1;j++)
		{
			if(Hd->lty_data.money < Hd->lty_next->lty_data.money)
			{

				lty lty_data = Hd->lty_data;
				Hd->lty_data = Hd->lty_next->lty_data;
				Hd->lty_next->lty_data = lty_data;
			}
			Hd = Hd->lty_next;
		}
	}
}

/**************************选择其中已添加的彩票**************************/
lty_lk*select_lty(lty_lk*lty_head,char*ID)
{
	if(lty_head == NULL)
	{
		printf("头节点为空\n");
		return NULL;
	}
	lty_lk *pre = lty_head;
	lty_head = lty_head->lty_next;
	while(lty_head!=NULL)
	{
		if(strcmp(lty_head->lty_data.ID,ID)==0)
			return pre;
		pre = lty_head;
		lty_head = lty_head->lty_next;
	}
	return NULL;
}

/*************************需要删除时用户键入入************************/
void del_lty(lty_lk *lty_head)
{
	char ID[20];
	printf("请输入要删除的用户姓名\n");
	scanf("%s",ID);
	delete_lty(lty_head,ID);
}
/****************************删除用户**********************/
void delete_lty(lty_lk *lty_head,char *ID)
{
	if(is_null(lty_head))
		return;
	lty_lk *pre = select(lty_head,ID);
	if(pre == NULL)
	{
		printf("查无此人\n");
		return;
	}
	pre->lty_next = pre->lty_next->lty_next;
}
