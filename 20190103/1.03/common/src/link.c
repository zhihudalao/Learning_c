#include "link.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

link_t* create_link(int size)
{
	//申请头节点的空间
	link_t* head = malloc(sizeof(link_t));
	assert(head);
	memset(head, 0, sizeof(link_t));

	//对头节点的初始化
	head->next = head;
	head->prev = head;
	head->data = NULL;
	head->size = size;
	return head;
}

void insert_link(link_t* head, void* _data)
{
	//节点申请
	link_t* newNode = malloc(sizeof(link_t));
	assert(newNode);
	memset(newNode, 0, sizeof(link_t));
	
	//值域空间的申请
	newNode->data = malloc(head->size);
	assert(newNode->data);
	memset(newNode->data, 0, sizeof(head->size));

	//值域空间的赋值
	memcpy(newNode->data, _data, head->size);

	//链接
	newNode->next = head;
	newNode->prev = head->prev;

	head->prev->next = newNode;
	head->prev = newNode;
}

void display_link(link_t* head, void(*print)(const void*))
{
	assert(head);
	link_t* p = head->next;
	while(p != head){
		print(p->data);
		p = p->next;
	}
}

void free_link(link_t* head)
{
	assert(head);
	link_t* p = head->next;

	while(p != head){
		p = p->next;
		free(p->prev->data);		//释放值域
		free(p->prev);				//释放节点
	}

	free(head);
}

link_t* find_link(link_t* head, const void* data, 
									int (*cmp)(const void*, const void*))
{
	assert(head);
	link_t* p = head->next;
	while(p != head){
		if(cmp(p->data, data) == 0){
			return p;
		}
		p = p->next;
	}
	return NULL;
}


int delete_link(link_t*head, const void* data, 
						int (*cmp)(const void*, const void*))
{
	if(NULL == head) 	return 1;
	link_t* p = head->next;
	while(p != head){
		//找到元素并删除
		if(cmp(p->data, data) == 0){
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p->data);
			free(p);
			p = NULL;
			return 0;
		}
		p = p->next;
	}
	return 1;
}


void sort_link(link_t* head, link_t* start, 
				link_t* end, int(*cmp)(const void* , const void*))
{
	assert(head && start && end);
	if(start == end || end->next == start || start->prev == end){
		return ;
	}
	link_t* low = start;		//低位
	link_t* high = end;			//高位
	void* key = start->data;	//基准值


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
