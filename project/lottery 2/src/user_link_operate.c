#include<stdio.h>
#include"user.h"
#include<string.h>
#include<stdlib.h>
/**************************选择其中已添加的用户**************************/
ulink*select_user(ulink*head,char*name)
{
	if(head == NULL)
	{

		printf("头节点为空\n");
		return NULL;
	}
	ulink *pre = head;
	head = head->next;
	while(head!=NULL)
	{
		if(strcmp(head->data.name,name)==0)
			return pre;
		pre = head;
		head = head->next;
	}
	return NULL;
}
/**********************从链表后端插入************************************/
void insert_after_user(ulink*head,user data)
{
	ulink*new;
	if(head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	while(head->next != NULL)
	{
		head = head->next;
	}
	new = create_user(data);
	head->next = new;
}

ulink*create_user(user data)
{
	ulink *new = calloc(1,sizeof(ulink));
	new->data = data;
	new->next = NULL;
	return new;
}
/**********************************释放空间******************/
void free_user(ulink*head)
{
	if(head == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	while(head!=NULL)
	{
		ulink*save = head->next;
		free(head);
		head = save;
	}
	head = NULL;
}
/************************************遍历打印***************************/
void print_user(ulink *head)
{
	if(head == NULL)
	{
	printf("头节点错\n");
		return;
	}
	head=head->next;
	printf("\t用户名\t余额\t注册时间\n");
	while(head != NULL)
	{
		printf("\t%s\t%.2f\t%s\n",head->data.name,head->data.money,head->data.regist_time);
		head = head->next;
	}
}
/**********************************余额排序*********************************/
void sort_money(ulink* head)
{
	int i = 0,j = 0;
	ulink* Hd = head;
	if(Hd == NULL)
	{
		printf("头节点为空\n");
		return ;
	}
	int length = 0;
	Hd = Hd ->next;//头节点不做排序
	while(Hd != NULL)
	{
		Hd = Hd->next;
		length++;
	}
	Hd = head->next;
	for(i = 0;i<length;i++)
	{
		Hd = head->next;
		for(j = 0;j<length-i-1;j++)
		{
			if(Hd->data.money < Hd->next->data.money)
			{	user data = Hd->data;
				Hd->data = Hd->next->data;
				Hd->next->data = data;
			}
			Hd = Hd->next;
		}
	}
}
/**************************用户名排序*********************/

void sort_name(ulink* head)
{
	int i = 0,j = 0;
	ulink* Hd = head;
	if(Hd == NULL)
	{
		printf("头节点为空\n");
		return ;
	}
	int length = 0;
	Hd = Hd ->next;//头节点不做排序
	while(Hd != NULL)
	{
		Hd = Hd->next;
		length++;
	}
	Hd = head->next;
	for(i = 0;i<length;i++)
	{
		Hd = head->next;
		for(j = 0;j<length-i-1;j++)
		{
			if(Hd->data.name[0] > Hd->next->data.name[0])
			{

				user data = Hd->data;
				Hd->data = Hd->next->data;
				Hd->next->data = data;
			}
			Hd = Hd->next;
		}
	}
}
/*************************需要删除时用户键入入************************/
void del_user(ulink *head)
{
	char name[20];
	printf("请输入要删除的用户姓名\n");
	scanf("%s",name);
	delete_user(head,name);
}
/****************************删除用户**********************/
void delete_user(ulink *head,char *name)
{
	if(is_null(head))
		return;
	ulink *pre = select(head,name);
	if(pre == NULL)
	{
		printf("查无此人\n");
		return;
	}
	pre->next = pre->next->next;
}
