#include "lotLink.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/*
	功能：创建彩票链表的头节点
	参数：无
	返回值：返回头节点
*/
Lot* createLotlink(void)
{
	//申请头节点的空间
	Lot* headLot = malloc(sizeof(Lot));
	assert(headLot);
	memset(headLot, 0, sizeof(Lot));
	//对头节点的初始化
	headLot->next = NULL;
	headLot->prev = NULL;
	return headLot;
}
Lot* create_lty(lty data)
{
	Lot *new = calloc(1,sizeof(Lot));
	new->data = data;
	new->next = NULL;

	return new;
}
void insert_after_lty(Lot*head,lty data){
	if(head == NULL){
		printf("头节点为空\n");
		return;
	}
	while(head->next != NULL){
		head = head->next;
	}
	Lot* newNode = malloc(sizeof(Lot));
	assert(newNode);
	memset(newNode, 0, sizeof(Lot));
	newNode->data = data;
	head->next = newNode;
	newNode->prev=head;
	newNode->next = NULL;
}


Lot* insertNewLot(void){
	Lot* newNode = malloc(sizeof(Lot));
	assert(newNode);
	memset(newNode, 0, sizeof(Lot));
	return newNode;
}
/*
	功能：添加一个新的节点到链表中
	参数：head 链表头节点 newNode 新节点的指针
	返回值 0 成功 1 失败
*/
int appendLotlink(Lot* head, Lot* newNode)
{
	if(NULL == head || NULL == newNode)
		return 1;
	//找到尾部节点指针
	Lot* p = head;
	while(p->next != NULL){
		p = p->next;
	}

	//链接
	p->next=newNode;
  newNode->prev=p;
  newNode->next=NULL;
	return 0;
}

/*
	功能：打印所有彩票信息
	参数：head 头节点
	返回值：无
*/

void displayLotlink(Lot* head)
{
	assert(head);
	Lot* p = head->next;
	while(p != NULL){
		printf("发行期号:%d\t发行单价:%d\n",p->data.name,p->data.prize);
			if(p->data.run){
				printf("开奖状态:已开奖\t\t中奖号码为:%d %d %d\n",p->data.lotNum[0],
				p->data.lotNum[1],p->data.lotNum[2]);
				printf("本期售出总数:%d\t本期奖池总额:%d\n",p->data.numLot,p->data.money);
			}
			else{
				printf("开奖状态:未开奖\t中奖号码:未开奖\n本期目前已售出总数:%d\t本期总奖池:%d\n",
				p->data.numLot,p->data.money);
			}
			printf("———————————————————————————————————————————————\n");
			p = p->next;
	}
	printf("\n");
}


void status(Lot*p)//判断是否开奖
{
	if(p->data.run)
	{printf("最新一期%d期已开奖,请准备发行下一期\n",p->data.name);}
	else{printf("最新一期%d期还未开奖\n",p->data.name);}
	printf("按ENTER返回\n");
	while(getchar()!='\n');
}

void the_lucky_num(Lot*p)//中奖号码
{
	int i = 0;
	if(p->data.run)//开奖状态
	{
		printf("%d期中奖号码为:",p->data.name);
		for(i=0;i<3;i++)
		{
			printf("%d ",p->data.lotNum[i]);
		}
		printf("\n");
	}else
	{
		printf("最新一期%d期未开奖,请耐心等待开奖\n",p->data.name);
	}
	printf("按ENTER返回\n");
	while(getchar()!='\n');
}

void the_sum_of_lty(Lot*p)//售出总数
{
	if(p->data.run)
	{
		printf("最新一期%d期已开奖,共售出%d注\n",p->data.name,p->data.numLot);
	}
	else
	{
		printf("最新一期%d期还未开奖,目前共售出%d注\n",p->data.name,p->data.numLot);
	}
	printf("按ENTER返回\n");
	while(getchar()!='\n');
}
void the_sum_money(Lot*p)
{
	printf("奖池总额为:%d\n",p->data.money);
	printf("按ENTER返回\n");
	while(getchar()!='\n');
}
/*
	功能：释放链表所有节点
	参数：head 头节点
	返回值：无
*/
void freeLotlink(Lot* head)
{
	assert(head);
	Lot* p = head;
	while(p->next!= NULL){

		p = p->next;
		free(p->prev);
	}
	free(p);
}


/*
	功能：排序（根据彩票账号排序）
	参数：head 头节点
	返回值：无
*/
void linkLotSort(Lot*head){
		Lot*p=head->next;
		int flag=0;
		struct Lot temp;
		while(1){
			flag=0;
			p=head->next;
			while(p->next!=NULL){
				if(p->data.name>p->next->data.name){
					temp=p->data;
					p->data=p->next->data;
					p->next->data=temp;
					flag=1;
				}
				p=p->next;
			}
			if(flag==0){
				break;
			}
		}
}
/*
	功能：读取所有彩票信息到内存中
	参数：head 头节点
	返回值：无
*/
void loadLot(Lot* head)
{
	assert(head);

	//打开文件
	FILE* fp = fopen("data/Lot.bin", "rb");
	if(NULL == fp){
		printf("打开文件失败\n");
		return ;
	}

	while(1){
		Lot* newNode = malloc(sizeof(Lot));
		assert(newNode);
		memset(newNode, 0, sizeof(Lot));
		struct Lot f;
		memset(&f, 0, sizeof(struct Lot));

		int ret = fread(&f, sizeof(struct Lot), 1, fp);
		if(0 == ret){
			free(newNode);
			newNode = NULL;
			break;
		}
		newNode->data = f;
		appendLotlink(head, newNode);
	}


	fclose(fp);
}

/*
	功能：将所有彩票的信息保存到文件之中
	参数：head 头节点
	返回值：无
*/
void save_Lot(Lot* head)
{
	assert(head);

	//打开文件
	FILE* fp = fopen("data/Lot.bin", "wb");
	if(NULL == fp){
		printf("打开文件失败\n");
		return ;
	}

	Lot* p = head->next;
	while(p != NULL){
		fwrite(&p->data, sizeof(struct Lot), 1, fp);
		p = p->next;
	}

	fclose(fp);
	fp = NULL;
}
