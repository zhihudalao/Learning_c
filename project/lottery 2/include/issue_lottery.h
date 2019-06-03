#ifndef FUN_M_
#define FUN_M_
/******************************发行彩票链表****************************/
typedef struct lottery
{
	int code;//期号
	int unit_price;//单价
	int is_run;//是否已经开奖
	int lucky_num[20];//中奖号码
	int num_of_lty;//本期售出总数
	int sum_lty;//本期奖池总额
}lty;
typedef struct ltylink
{
	lty lty_data;
	struct ltylink*lty_next;
}lty_lk;
/********************管理员操作************************/
void issue_menu();//发行彩票
void qry_tck_inf();//查询彩票信息
void qry_user_inf();//查询用户信息

/***********************发行彩票链表底层操作***************/
//lty_lk*select_lty(lty_lk*,char*);//选择
void insert_after_lty(lty_lk*,lty );//后向插入彩票信息，接入链表末端
lty_lk*create_lty(lty );//申请新的彩票节点
void free_lty(lty_lk*);//释放空间
//void del_lty(lty_lk *);
//void delete_lty(lty_lk *,char *);
void print_lty(lty_lk *);
/***********************彩票文件操作******************/
void lty_load(lty_lk*);//加载文件中存放的用户信息
void lty_save(lty_lk*);//保存用户信息到文件中
#endif
