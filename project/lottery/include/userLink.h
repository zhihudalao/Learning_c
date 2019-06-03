#ifndef USERLINK_H_
#define USERLINK_H_

typedef struct User{
	char 	name[20];
	int 	id;
	char 	pswd[20];
	double 	account;
}user;

//链表节点的定义
typedef struct User_link{
	struct User_link* 	prev;
	user		data;			//值域
	struct User_link* 	next;			//指针域
}User;
/*
	功能：创建用户链表的头节点
	参数：无
	返回值：返回头节点
*/
User* create_link(void);
User* insertNewUser(void);
/*
	功能：添加一个新的节点到链表中
	参数：head 链表头节点 newNode 新节点的指针
	返回值 0 成功 1 失败
*/
int append_link(User* head, User* newNode);
/*
	功能：打印所有用户信息
	参数：head 头节点
	返回值：无
*/

void display_link(User* head);
/*
	功能：释放链表所有节点
	参数：head 头节点
	返回值：无
*/
void free_link(User* head);
/*
	功能：通过名字检测用户是否存在
	参数：head 头节点  name 要检测的名字
	返回值：0 成功 1 失败
*/
int ifname(User* head,int id);
int ifpswd(User* head,char* pswd);
User* find_link( User* head,int id);
/*
	功能：排序（根据彩民账号排序）
	参数：head 头节点
	返回值：无
*/
void linkSort(User*head);
/*
	功能：读取所有用户信息到内存中
	参数：head 头节点
	返回值：无
*/
int cancell_user(User*pre);
void load_Users(User* head);

/*
	功能：将所有用户的信息保存到文件之中
	参数：head 头节点
	返回值：无
*/
void save_Users(User* head);


#endif
