/********************************用户链表************************/
#ifndef FUN_L_
#define FUN_L_
typedef struct user
{
	char name[20];
	char pswd[20];
	char regist_time[20];
	float money;

}user;
typedef struct userlink
{
	user data;
	struct userlink *next;
}ulink;


/**************用户链表底层操作********************/
ulink*create_user(user data);//为新的数据申请新的空间
void insert_after_user(ulink*,user);//后向插入用户信息，放入链表末端
ulink*select_user(ulink*,char *name);//在链表中查找到所需要的用户所在位置
void free_user(ulink*);//释放空间
void delete_user(ulink *head,char *name);//删除用户+
void print_user(ulink *head);//打印

/*************注册登录文件操作*****************/
void user_load(ulink*);//加载文件中存放的用户信息
void user_save(ulink*);//保存用户信息到文件中

/**************辅助函数***********************************/
void menu_print();//注册登录菜单显示
int shadow_pswd(char*);//隐藏密码与限制输入字符长度
int getch();//不回显的获取输入的字符，
int name_input(char *);//用户名输入（限制长度）
int ver_code();//验证码
void now_time(char *);
#endif
