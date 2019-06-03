#include<stdio.h>
#include<stdlib.h>
#include"issue_lottery.h"
#include"user.h"
#include"buy_ticket.h"
void menu(ulink*,lty_lk*,blty_lk*);//登录注册菜单
int main(void)
{
	ulink *user_head = calloc(1,sizeof(ulink));//用户链表头节点
	user_head->next = NULL;
	lty_lk *lty_head = calloc(1,sizeof(lty_lk));//发行彩票链表头节点
	lty_head->lty_next = NULL;
	blty_lk*blty_head = calloc(1,sizeof(blty_lk));//购买彩票链表头节点
	blty_head->blty_next = NULL;

	user_load(user_head);//用户链表加载
	lty_load(lty_head);//发行链表加载
	blty_load(blty_head);//购买链表加载

	menu(user_head,lty_head,blty_head);

	user_save(user_head);//用户信息保存
	lty_save(lty_head);//发行彩票信息保存
	blty_save(blty_head);//购买彩票信息保存
	free_user(user_head);//空间释放
	free_lty(lty_head);
	free_blty(blty_head);

	return 0;
}
