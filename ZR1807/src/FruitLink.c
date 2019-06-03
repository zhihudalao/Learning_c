#include "FruitLink.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

Fruit* create_link(void)
{
	Fruit* head = malloc(sizeof(Fruit));
	//assert(head);
	if(NULL == head)	return NULL;
	memset(head, 0, sizeof(Fruit));

	head->next = NULL;
	return head;
}

int append_link(Fruit* head, Fruit* newNode)
{
	if(NULL == head || NULL == newNode)
		return 1;
	//找到尾部节点指针
	Fruit* p = head;
	while(p->next != NULL){
		p = p->next;
	}

	//链接
	p->next = newNode;
	newNode->next = NULL;
	return 0;
}


void display_link(Fruit* head)
{
	assert(head);
	Fruit* p = head->next;
	printf("水果名\t价格\n");
	while(p != NULL){
		struct fruit f = p->fruit;
		printf("%s\t%g\n", f.name, f.price);
		p = p->next;
	}
}

/*
	功能：释放链表所有节点
	参数：head 头节点
	返回值：无
*/
void free_link(Fruit* head)
{
	assert(head);
	Fruit* q = head->next;
	Fruit* p = q;
	while(q != NULL){
		p = p->next;
		free(q);
		q = p;
	}
	free(head);
}

/*
	功能：通过名字检测水果是否存在
	参数：head 头节点  name 要检测的名字
	返回值：0 成功 1 失败
*/
int find_fruit_by_name(Fruit* head, const char* name)
{
	if(NULL == head || NULL == name) return 1;
	
	Fruit* p = head->next;
	while(p != NULL){
		if(strcmp(name, p->fruit.name) == 0){
			return 0;
		}
		p = p->next;
	}
	return 1;
}

/*
	功能：删除一个节点
	参数：head 头节点  name 要删除的水果名
	返回值：0 成功 1 失败
*/
int remove_node(Fruit* head, const char* name)
{
	if(NULL == head || NULL == name) return 1;
	
	Fruit* cur = head->next;
	Fruit* before = head;
	while(cur != NULL){
		if(strcmp(cur->fruit.name, name) == 0){
			//删除
			before->next = cur->next;
			free(cur);
			cur = NULL;
			return 0;
		}
		before = cur;
		cur = cur->next;
	}
	return 1;
}

/*
	功能：对链表的所有水果排序
	参数：head 头节点
	返回值：无
*/
void sort_fruit(Fruit* head)
{
	assert(head);
	if(head->next == NULL || head->next->next == NULL) return ;
	
	Fruit* p = NULL;
	Fruit* q = NULL;
	for(p = head->next; p->next != NULL;p = p->next){
		for(q = p->next; q != NULL; q = q->next){
			if(p->fruit.price > q->fruit.price){
				//交换名字
				/*
				char _name[20] = {'\0'};
				strcpy(_name, p->name);
				strcpy(p->name, q->name);
				strcpy(q->name, _name);
				
				//交换价格
				double _price = p->price;
				p->price = q->price;
				q->price = _price;
				*/
				struct fruit tmp  = p->fruit;
				p->fruit = q->fruit;
				q->fruit = tmp;
			}
		}
	}
}

/*
	功能：读取所有水果信息到内存中
	参数：head 头节点
	返回值：无
*/
void load_fruits(Fruit* head)
{
	assert(head);

	//打开文件
	FILE* fp = fopen("data/fruit.bin", "rb");
	if(NULL == fp){
		printf("打开文件失败\n");
		return ;
	}
	
	while(1){	
		Fruit* newNode = malloc(sizeof(Fruit));
		assert(newNode);
		memset(newNode, 0, sizeof(Fruit));
		struct fruit f;
		memset(&f, 0, sizeof(struct fruit));
		
		int ret = fread(&f, sizeof(struct fruit), 1, fp);
		if(0 == ret){
			free(newNode);
			newNode = NULL;
			break;
		}
		newNode->fruit = f;
		append_link(head, newNode);
	}
	
	
	fclose(fp);
}

/*
	功能：将所有水果的信息保存到文件之中
	参数：head 头节点
	返回值：无
*/
void save_fruits(Fruit* head)
{
	assert(head);
	
#if 0
	size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
	size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                     FILE *stream);
#endif
	
	//打开文件
	FILE* fp = fopen("data/fruit.bin", "wb");
	if(NULL == fp){
		printf("打开文件失败\n");
		return ;
	}
	
	Fruit* p = head->next;
	while(p != NULL){
		fwrite(&p->fruit, sizeof(struct fruit), 1, fp);
		p = p->next;
	}

	fclose(fp);
	fp = NULL;
}














