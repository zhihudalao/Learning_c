#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Node
{
	int iData;
	struct Node *pNext;
}Node;

typedef struct List
{
	Node *pFirstNode;
	int iLen;
}List;

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
	return list;
}

void insert(List *list, int data)
{
	if (NULL == list)
	{
		return;
	}
	Node *node = mkNode();
	node->iData = data;

	node->pNext = list->pFirstNode;
	list->pFirstNode = node;

	list->iLen++;
}

void show(const List *list)
{
	if (NULL == list)
	{
		return;
	}

	Node *node = list->pFirstNode;
	while (NULL != node)
	{
		printf("%d ", node->iData);
		node = node->pNext;
	}
	printf("\n");
}


void reverse(List *list)
{
	if (NULL == list)
	{
		return;
	}

	Node *p = list->pFirstNode;
	Node *node = NULL;
	if (NULL != p)
	{
		while (1)
		{
			node = p->pNext;
			if (NULL == node)
			{
				break;
			}
			p->pNext = node->pNext;

			node->pNext = list->pFirstNode;
			list->pFirstNode = node;
		}
	}
}

int main(void)
{
	List *list = mkList();
	insert(list, 90);
	insert(list, 91);
	insert(list, 92);
	insert(list, 93);
	insert(list, 94);
	show(list);

	reverse(list);

	show(list);


	return 0;
}
