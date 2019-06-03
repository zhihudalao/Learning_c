#ifndef LOTRECORT_H_
#define LOTRECORT_H_


typedef struct buy_lty
{
	int tkt_code;			//发行期号
	int tkt_ID;		//彩票唯一ID
	int own_ticket[5][20];		//所选号码
	int userId;		//购买者帐号
	int buy_num;			//购买某一彩票期号注数
	int multiple;			//购买倍数
	int is_win;			//中奖状态
	int win_amount;			//中奖金额
	char buy_time[30];		//购买时间
}buy_lty;

//链表节点的定义
typedef struct Rec{
	struct Rec* 	prev;
	buy_lty 		data;			//值域
	struct Rec* 	next;			//指针域
}LotRec;
/*
	功能：创建彩票链表的头节点
	参数：无
	返回值：返回头节点
*/
LotRec* createReclink(void);
LotRec* insertNewRec(void);
void insert_after_blty(LotRec*head,buy_lty data);

void hist_recored(LotRec*blty_head,int id);
void print_own_lty(LotRec*pre,int n);
/*
	功能：添加一个新的节点到链表中
	参数：head 链表头节点 newNode 新节点的指针
	返回值 0 成功 1 失败
*/
int appendReclink(LotRec* head, LotRec* newNode);
/*
	功能：打印所有用户信息
	参数：head 头节点
	返回值：无
*/

void displayReclink(LotRec* head);
/*
	功能：释放链表所有节点
	参数：head 头节点
	返回值：无
*/
void freeReclink(LotRec* head);
/*
	功能：通过名字检测用户是否存在
	参数：head 头节点  name 要检测的名字
	返回值：0 成功 1 失败
*/
int ifRecname(LotRec* head,int id);
LotRec* findReclink( LotRec* head,int id);
/*
	功能：排序（根据彩民账号排序）
	参数：head 头节点
	返回值：无
*/
void linkRecSort(LotRec*head);
/*
	功能：读取所有用户信息到内存中
	参数：head 头节点
	返回值：无
*/
void loadRec(LotRec* head);
/*
	功能：将所有用户的信息保存到文件之中
	参数：head 头节点
	返回值：无
*/
void save_Rec(LotRec* head);




#endif
