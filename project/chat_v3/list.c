#include "list.h"

Node *mkNode()
{
	Node *node = (Node*)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	return node;
}

List *mkList()
{
	List *list = (List*)malloc(sizeof(List));
	memset(list, 0, sizeof(List));
	list->uiMaxId = 1000;
	return list;
}

void insert(List *list, Node *node)
{
	if (NULL == list || NULL == node)
	{
		return;
	}
	node->pNext = list->pFirstNode;
	list->pFirstNode = node;
	list->iLen++;
	if (node->uiId > list->uiMaxId)
	{
		list->uiMaxId = node->uiId;
	}
}

Node *findNodeById(const List *list, uint iId)
{
	Node *node = NULL;
	if (NULL != list)
	{
		node = list->pFirstNode;
		while (NULL != node)
		{
			if (node->uiId == iId)
			{
				break;
			}
			node = node->pNext;
		}
	}
	return node;
}

