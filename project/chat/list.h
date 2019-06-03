#ifndef LIST_H
#define LIST_H

#include "public.h"

typedef struct Node
{
	uint uiId;
	char caPwd[PWD_LEN];
	int sockfd;

	struct Node *pNext;
}Node;

typedef struct List
{
	Node *pFirstNode;
	int iLen;
	uint uiMaxId;
}List;

Node *mkNode();
List *mkList();
void insert(List *list, Node *node);
Node *findNodeById(const List *list, uint iId);

#endif
