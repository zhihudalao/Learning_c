#include "LotRecord.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/*
	功能：创建彩票链表的头节点
	参数：无
	返回值：返回头节点
*/
LotRec* createReclink(void)
{
	//申请头节点的空间
	LotRec* headRec = malloc(sizeof(LotRec));
	assert(headRec);
	memset(headRec, 0, sizeof(LotRec));
	//对头节点的初始化
	headRec->next = NULL;
	headRec->prev = NULL;
	return headRec;
}
LotRec* insertNewRec(void){
	LotRec* newNode = malloc(sizeof(LotRec));
	assert(newNode);
	memset(newNode, 0, sizeof(LotRec));
	return newNode;
}
/*
	功能：添加一个新的节点到链表中
	参数：head 链表头节点 newNode 新节点的指针
	返回值 0 成功 1 失败
*/
int appendReclink(LotRec* head, LotRec* newNode)
{
	if(NULL == head || NULL == newNode)
		return 1;
	//找到尾部节点指针
	LotRec* p = head;
	while(p->next != NULL){
		p = p->next;
	}

	//链接
	p->next=newNode;
  newNode->prev=p;
  newNode->next=NULL;
	return 0;
}

void insert_after_blty(LotRec*head,buy_lty data){
	if(head == NULL){
		printf("头节点为空\n");
		return;
	}
	while(head->next != NULL){
		head = head->next;
	}
	LotRec* newNode = malloc(sizeof(LotRec));
	assert(newNode);
	memset(newNode, 0, sizeof(LotRec));
	newNode->data = data;
	head->next = newNode;
	newNode->prev=head;
	newNode->next = NULL;
}
/*
	功能：打印所有彩票信息
	参数：head 头节点
	返回值：无
*/

void displayReclink(LotRec* head)
{
	assert(head);
	int i,j;
	LotRec* p = head->next;
	if(p==NULL){
		printf("未查找到购物信息\n");
		return;
	}
	while(p!= NULL){
		printf("——————————————————————————————————————————————————————————\n");
		printf("期号:%d\n",p->data.tkt_code);
		printf("ID:%d\t时间:%s",p->data.tkt_ID,p->data.buy_time);
		printf("购买者帐号:%d\t购买注数:%d\t",p->data.userId,p->data.buy_num);
		printf("倍数:%d\n",p->data.multiple);
		printf("彩票号码:\n");
		for(i=0;i<p->data.buy_num;i++)
		{
			printf("%d\t",i+1);
			for(j=0;j<3;j++)
			{
				printf("%d ",p->data.own_ticket[i][j]);
			}
			printf("\n");
		}
		if(p->data.is_win)
		{
			printf("中奖状态: 已中奖\t中奖金额: %d\n",p->data.win_amount);
		}else
		{
			printf("中奖状态: 未中奖\t中奖金额: %d\n",p->data.win_amount);
		}
		printf("——————————————————————————————————————————————————————————\n");
		p = p->next;
	}
	printf("\n");
}
void hist_recored(LotRec*blty_head,int id)//采购记录
{
	int n = 0;//记录条数
	if(blty_head == NULL){
		printf("购彩链表头节点为空\n");
		exit(1);
	}
	blty_head = blty_head->next;
	while(blty_head != NULL){
		if(blty_head->data.userId==id){
			n++;
			if(n>0){
			print_own_lty(blty_head,n);//打印记录
			}
		}
		blty_head = blty_head->next;
	}
	if(n <= 0){
		printf("您没有购彩记录\n");
	}
}
void print_own_lty(LotRec*pre,int n)
{
	int i = 0,j = 0;
	printf("第%d条记录\n",n);
	printf("\t发行期号:%d 彩票ID:%d 购买时间:%s",pre->data.tkt_code,
			pre->data.tkt_ID,pre->data.buy_time);

	printf("\t购彩号码:\n");
	for(i=0;i<(pre->data.buy_num);i++)
	{
		printf("\t第%d注\t",i+1);
		for(j=0;j<3;j++)
		{
			printf("%d ",pre->data.own_ticket[i][j]);
		}
		printf("\n");
	}
	if(pre->data.is_win)
		{
			printf("\t中奖状态: 已中奖\t中奖金额: %d\n",pre->data.win_amount);
		}else
		{
			printf("\t中奖状态: 未中奖\t中奖金额: %d\n",pre->data.win_amount);
		}
		printf("—————————————————————————————————————————————————————————————————————————\n");
}

/*void delete_lty(LotRec*blty_head,char *ID)
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
/*
	功能：释放链表所有节点
	参数：head 头节点
	返回值：无
*/
void freeReclink(LotRec* head)
{
	assert(head);
	LotRec* p = head;
	while(p->next != NULL){

		p = p->next;
		free(p->prev);
	}
	free(p);
}

/*
	功能：通过名字检测用户是否存在
	参数：head 头节点  name 要检测的名字
	返回值：0 成功 1 失败
*/
int ifRecname(LotRec* head,int userId)
{
	if(NULL == head) return 1;

	LotRec* p = head->next;
	while(p != NULL){
		if(p->data.userId == userId){
			return 0;
		}
		p = p->next;
	}
	return 1;
}

LotRec* findReclink( LotRec* head,int userId)
{
	assert(head);
	LotRec* p = head->next;
	while(p != NULL){
		if(userId == p->data.userId){
			return p;
		}
		p = p->next;
	}
	return NULL;
}
/*
	功能：排序（根据彩票账号排序）
	参数：head 头节点
	返回值：无
*/
void linkRecSort(LotRec*head){
		LotRec*p=head->next;
		int flag=0;
		buy_lty  temp;
		while(1){
			flag=0;
			p=head->next;
			while(p->next!=NULL){
				if(p->data.userId>p->next->data.userId){
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
void loadRec(LotRec* head)
{
	assert(head);

	//打开文件
	FILE* fp = fopen("data/Rec.bin", "rb");
	if(NULL == fp){
		printf("打开文件失败\n");
		return ;
	}

	while(1){
		LotRec* newNode = malloc(sizeof(LotRec));
		assert(newNode);
		memset(newNode, 0, sizeof(LotRec));
		buy_lty f;
		memset(&f, 0, sizeof(buy_lty));

		int ret = fread(&f, sizeof(buy_lty), 1, fp);
		if(0 == ret){
			free(newNode);
			newNode = NULL;
			break;
		}
		newNode->data = f;
		appendReclink(head, newNode);
	}


	fclose(fp);
}

/*
	功能：将所有彩票的信息保存到文件之中
	参数：head 头节点
	返回值：无
*/
void save_Rec(LotRec* head)
{
	assert(head);

	//打开文件
	FILE* fp = fopen("data/Rec.bin", "wb");
	if(NULL == fp){
		printf("打开文件失败\n");
		return ;
	}

	LotRec* p = head->next;
	while(p != NULL){
		fwrite(&p->data, sizeof(buy_lty), 1, fp);
		p = p->next;
	}

	fclose(fp);
	fp = NULL;
}
