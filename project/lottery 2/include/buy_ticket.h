#ifndef FUN_B_
#define FUN_B_
#define SCOPE 5//产生随机数的范围
#define BONUS 1000//奖金
typedef struct buy_lty
{
	int tkt_code;			//发行期号
	char tkt_ID[10];		//彩票唯一ID
	int own_ticket[5][20];		//所选号码
	char user_name[20];		//购买者帐号
	int buy_num;			//购买某一彩票期号注数
	int multiple;			//购买倍数
	int is_win;			//中奖状态
	int win_amount;			//中奖金额
	char buy_time[30];		//购买时间
}buy_lty;
typedef struct buy_lottery_link		//购买彩票链表
{
	buy_lty blty_data;
	struct buy_lottery_link*blty_next;
}blty_lk;
/****************************************************************/
void now_time(char*);
/***********************购买彩票链表底层操作**********************/
blty_lk*select_blty(blty_lk*blty_head,char*name);
void insert_after_blty(blty_lk*,buy_lty);
blty_lk*create_blty(buy_lty);
void free_blty(blty_lk*);
void print_blty(blty_lk *);
//void sort_buy(blty_lk*);
/***********************购买彩票链表文件操作**********************/
void blty_load(blty_lk*);
void blty_save(blty_lk*);
#endif
