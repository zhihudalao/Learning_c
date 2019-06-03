#include "usrLink.h"

UsrNode *mkUsrNode()      //产生用户信息节点
{
	UsrNode *node = (UsrNode*)malloc(sizeof(UsrNode));
	if (NULL == node)
	{
		printf("mallco usr node failed");
		exit(EXIT_FAILURE);
	}
	memset(node, 0, sizeof(UsrNode));
	return node;
}

UsrLink *mkUsrLink()      //产生用户信息链表
{
	UsrLink *link = (UsrLink*)malloc(sizeof(UsrLink));
	if (NULL == link)
	{
		printf("mallco usr link failed");
		exit(EXIT_FAILURE);
	}
	memset(link, 0, sizeof(UsrLink));
	link->uiMaxId = 1000;

	return link;
}

void insertUsrLink(UsrNode *node, UsrLink *link)
{
	if (NULL == node || NULL == link)
	{
		return;
	}
	node->pNext = link->pFirstNode;
	link->pFirstNode = node;
	link->uiLen++;
	if (node->uiId > link->uiMaxId)
	{
		link->uiMaxId = node->uiId;
	}
}

//通过id查找用户
UsrNode *findUsrById(uint uiId, const UsrLink *link)
{
	UsrNode *node = NULL;
	if (NULL != link && uiId <= link->uiMaxId)
	{
		node = link->pFirstNode;
		while (NULL != node)
		{
			if (node->uiId == uiId)
			{
				break;
			}
			node = node->pNext;
		}
	}
	return node;
}

//显示链表
void displayUsrLink(const UsrLink *link)
{
	if (NULL != link)
	{
		UsrNode *node = link->pFirstNode;
		while (NULL != node)
		{
			printf("ID:%u, name:%s, pwd:%s, socket:%d\n"
				   , node->uiId, node->caName
				   , node->caPwd, node->sockfd);
			node = node->pNext;
		}
	}
}










