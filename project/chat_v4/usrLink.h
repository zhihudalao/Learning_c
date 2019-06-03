#ifndef USR_LINK_H
#define USR_LINK_H

#include "public.h"

typedef struct UsrNode
{
	uint uiId;
	char caName[NAME_LEN];
	char caPwd[PWD_LEN];
	int sockfd;

	struct UsrNode *pNext;
	
}UsrNode;

typedef struct UsrLink
{
	UsrNode *pFirstNode;   //指向第一个用户信息节点
	uint uiLen;            //存放用户的总量
	uint uiMaxId;          //存放最大的用户id
}UsrLink;

UsrNode *mkUsrNode();      //产生用户信息节点
UsrLink *mkUsrLink();      //产生用户信息链表

void insertUsrLink(UsrNode *node, UsrLink *link);
//通过id查找用户
UsrNode *findUsrById(uint uiId, const UsrLink *link);
//显示链表
void displayUsrLink(const UsrLink *link);

#endif






