#include "userLink.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include<unistd.h>
/*
	功能：创建用户链表的头节点
	参数：无
	返回值：返回头节点
*/
User* create_link(void)
{
	//申请头节点的空间
	User* headUser = malloc(sizeof(User));
	assert(headUser);
	memset(headUser, 0, sizeof(User));
	//对头节点的初始化
	headUser->next = NULL;
	headUser->prev = NULL;
	return headUser;
}
User* insertNewUser(void){
	User* newNode = malloc(sizeof(User));
	assert(newNode);
	memset(newNode, 0, sizeof(User));
	return newNode;
}
/*
	功能：添加一个新的节点到链表中
	参数：head 链表头节点 newNode 新节点的指针
	返回值 0 成功 1 失败
*/
int append_link(User* head, User* newNode)
{
	if(NULL == head || NULL == newNode)
		return 1;
	//找到尾部节点指针
	User* p = head;
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
	功能：打印所有用户信息
	参数：head 头节点
	返回值：无
*/

void display_link(User* head)
{
	assert(head);
	User* p = head->next;
	while(p !=NULL ){
		printf("%s ", p->data.name);
		printf("%d ", p->data.id);
		printf("%g \n", p->data.account);
		p = p->next;
	}
	printf("\n");
}

/*
	功能：释放链表所有节点
	参数：head 头节点
	返回值：无
*/
void free_link(User* head)
{
	assert(head);
	User* p = head;
	while(p->next!= NULL){
		p = p->next;
		free(p->prev);
	}

	free(p);
}
/*void qry_user_byname(User*user_head)
{
	struct User data;
	User*pre;
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
/*
	功能：通过名字检测用户是否存在
	参数：head 头节点  name 要检测的名字
	返回值：0 成功 1 失败
*/
int ifname(User* head,int id)
{
	if(NULL == head) return 1;

	User* p = head->next;
	while(p != NULL){
		if(p->data.id == id){
			return 0;
		}
		p = p->next;
	}
	return 1;
}
int ifpswd(User* head,char* pswd)
{
	if(NULL == head) return 1;

	User* p = head->next;
	while(p != NULL){
		if(strcmp(p->data.pswd,pswd)==0){
			return 0;
		}
		p = p->next;
	}
	return 1;
}

User* find_link( User* head,int id)
{
	assert(head);
	User* p = head->next;
	while(p != NULL){
		if(id == p->data.id){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

/*
	功能：排序（根据彩民账号排序）
	参数：head 头节点
	返回值：无
*/
void linkSort(User*head){
		User*p=head->next;
		int flag=0;
		struct User temp;
		while(1){
			flag=0;
			p=head->next;
			while(p->next!=NULL){
				if(p->data.id>p->next->data.id){
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
int cancell_user(User*pre)
{
	char pswd_temp[20] = "";
	char ch = 0;
	printf("想好要离开我了吗?\n");
	printf("按 Y 确认注销\n其他键取消\n");
	ch = getchar();
	if(ch == 'Y'||ch == 'y')
	{
		printf("请输入密码:");//注销时提示输入密码
		scanf("%s",pswd_temp);
		if(strcmp(pre->data.pswd,pswd_temp) == 0){
			if(pre->next!=NULL){
			pre->next->prev = pre->prev;
			}
			pre->prev->next=pre->next;
			free(pre);
			printf("\033[01;31m您的账户已注销成功,欢迎下次再次光临\033[0m\n");
			sleep(2);
			return 1;//注销成功返回1

		}else
		{
			printf("输入密码错误");
			getchar();
			while(getchar()!='\n');
			return 0;//注销失败返回0
		}
	}else{return 0;}
}
/*
	功能：读取所有用户信息到内存中
	参数：head 头节点
	返回值：无
*/
void load_Users(User* head)
{
	assert(head);

	//打开文件
	FILE* fp = fopen("data/User.bin", "rb");
	if(NULL == fp){
		printf("打开文件失败\n");
		return ;
	}

	while(1){
		User* newNode = malloc(sizeof(User));
		assert(newNode);
		memset(newNode, 0, sizeof(User));
		struct User f;
		memset(&f, 0, sizeof(struct User));

		int ret = fread(&f, sizeof(struct User), 1, fp);
		if(0 == ret){
			free(newNode);
			newNode = NULL;
			break ;
		}
		newNode->data = f;
		append_link(head, newNode);
	}

	fclose(fp);
	fp=NULL;
}

/*
	功能：将所有用户的信息保存到文件之中
	参数：head 头节点
	返回值：无
*/
void save_Users(User* head)
{
	assert(head);

	//打开文件
	FILE* fp = fopen("data/User.bin", "wb");
	if(NULL == fp){
		printf("打开文件失败\n");
		return ;
	}

	User* p = head->next;
	while(p != NULL){
		fwrite(&p->data, sizeof(struct User), 1, fp);
		p = p->next;
	}
	fclose(fp);
	fp = NULL;
}
