#ifndef LOTLINK_H_
#define LOTLINK_H_


typedef struct Lot{
	int   name;//期号
	int 	lotNum[20];//中奖号码
	int   prize;//单价
	int 	money;//奖池总额
	int   numLot;//售出总数
	int		run;//是否开奖
}lty;

//链表节点的定义
typedef struct LotteryList_link{
	struct LotteryList_link* 	prev;
	lty		data;			//值域
	struct LotteryList_link* 	next;			//指针域
}Lot;
/*
	功能：创建彩票链表的头节点
	参数：无
	返回值：返回头节点
*/
Lot* createLotlink(void);
Lot* insertNewLot(void);
Lot* create_lty(lty lty_data);
void insert_after_lty(Lot*lty_head,lty lty_data);
/*
	功能：添加一个新的节点到链表中
	参数：head 链表头节点 newNode 新节点的指针
	返回值 0 成功 1 失败
*/
int appendLotlink(Lot* head, Lot* newNode);
/*
	功能：打印所有用户信息
	参数：head 头节点
	返回值：无
*/

void displayLotlink(Lot* head);
void status(Lot*p);//判断是否开奖
void the_sum_of_lty(Lot*p);//售出总数
void the_lucky_num(Lot*p);//中奖号码
void the_sum_money(Lot*p);//奖池金额
/*
	功能：释放链表所有节点
	参数：head 头节点
	返回值：无
*/
void freeLotlink(Lot* head);
/*
	功能：通过名字检测用户是否存在
	参数：head 头节点  name 要检测的名字
	返回值：0 成功 1 失败
*/
int ifLotname(Lot* head,int id);
Lot* findLotlink( Lot* head,int id);
/*
	功能：排序（根据彩民账号排序）
	参数：head 头节点
	返回值：无
*/
void linkLotSort(Lot*head);
/*
	功能：读取所有用户信息到内存中
	参数：head 头节点
	返回值：无
*/
void loadLot(Lot* head);
/*
	功能：将所有用户的信息保存到文件之中
	参数：head 头节点
	返回值：无
*/
void save_Lot(Lot* head);




#endif
