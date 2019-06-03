#include "link.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

link_t* create_link(void)
{
	//申请头节点的空间
	link_t* head = malloc(sizeof(link_t));
	assert(head);
	memset(head, 0, sizeof(link_t));

	//对头节点的初始化
	head->next = head;
	head->prev = head;
	return head;
}

void insert_link(link_t* head, int _data)
{
	//节点申请和值域的赋值
	link_t* newNode = malloc(sizeof(link_t));
	assert(newNode);
	memset(newNode, 0, sizeof(link_t));
	
	newNode->data = _data;

	//链接
	newNode->next = head;
	newNode->prev = head->prev;

	head->prev->next = newNode;
	head->prev = newNode;
}

void display_link(link_t* head)
{
	assert(head);
	link_t* p = head->next;
	while(p != head){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void free_link(link_t* head)
{
	assert(head);
	link_t* p = head->next;

	while(p != head){
		p = p->next;
		free(p->prev);
	}

	free(head);
}



link_t* find_link(link_t* head, int find_val)
{
	assert(head);
	link_t* p = head->next;
	while(p != head){
		if(find_val == p->data){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int delete_link(link_t*head, int delete_val)
{
	if(NULL == head) 	return 1;
	link_t* p = head->next;
	while(p != head){
		//找到元素并删除
		if(p->data == delete_val){
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);
			p = NULL;
			return 0;
		}
		p = p->next;
	}
	return 1;
}

void sort_link(link_t* head, link_t* start, link_t* end, int(*cmp)(int,int))
{
	assert(head && start && end);
	if(start == end || end->next == start || start->prev == end){
		return ;
	}
	link_t* low = start;		//低位
	link_t* high = end;			//高位
	int key = start->data;		//基准值


	while(low != high){
		while(cmp(high->data, key) >= 0&& low != high){
			high = high->prev;
		}
		low->data = high->data;
		
		while(cmp(low->data, key) <= 0&& low != high){
			low = low->next;
		}
		high->data = low->data;
	}	
	//基准值的位置
	low->data = key;	
	//对分割的序列进行递归排序
	sort_link(head, start, low->prev, cmp);
	sort_link(head, low->next, end, cmp);
}
