#ifndef LOTTREY_FUNC_H_
#define LOTTREY_FUNC_H_
#define BONUS 1000//奖金#define BONUS 1000//奖金
#include "lotLink.h"
#include "userLink.h"
#include "LotRecord.h"
/*
函数名：adminLogin
函数功能：管理员登录用
返回值：void
*/
void adminLogin();
/*
函数名：userLogin
函数功能：用户登录用
返回值：成功0 失败1
*/
int userLogin(User*head);
/*
函数名：insertLot
函数功能：插入彩票
返回值：void
*/
void  insertLot(Lot*head);
/*
函数名：findUser
函数功能：找到用户账号
返回值：
*/
int findUser(User*head,int id);
/*
函数名：insterUser
函数功能：彩民注册
返回值：成功 id,失败1
*/
int insterUser(User*head);
/*
函数名：altPswd
函数功能：更改密码
返回值：成功 0 失败 1
*/
int altPswd(User* head,int id );
int shadow_pswd(char *pswd);
/*
函数名：payAccount
函数功能：充值
返回值：
*/
int payAccount(User*head);
//购买彩票
void buy_ticket(Lot*lty_head,LotRec*blty_head,User* personal);
void bet_now(buy_lty*bdata);
void automatic(buy_lty*bdata,int n);
void manual(buy_lty*bdata,int n);
void create_lty_ID(LotRec*blty_head,buy_lty*bdata);

void greate_luky_num(Lot*lty_head);
void run_lottery(User*user_head,Lot*lty_head,LotRec*blty_head);

void winner(User*user_head,Lot*lty_head,LotRec*blty_head);
void is_win(User*user_head,Lot*lty_head,LotRec*blty_head);
void send_prize(User*user_head,Lot*lty_head,LotRec*blty_head);
int ver_code();
int name_input(char *name);
void now_time(char *NowTime);

#endif
