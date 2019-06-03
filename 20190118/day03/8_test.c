#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

typedef struct Node
{
	char caName[256];
	float fMath;
	float fMusic;
	float fDance;
	struct Node *pNext;
}Node;

typedef struct List
{
	Node *pFirstNode;
	int iLen;
}List;

Node *mkNode()
{
	Node *node = (Node *)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	return node;
}

List *mkList()
{
	List *list = (List*)malloc(sizeof(List));
	memset(list, 0, sizeof(List));
	return list;
}

void insert(List *list, Node *node)
{
	if (NULL == node || NULL == list)
	{
		return;
	}	
	node->pNext = list->pFirstNode;
	list->pFirstNode = node;
	list->iLen++;
}

void show(const List *list)
{
	Node *node = list->pFirstNode;
	while (NULL != node)
	{
		printf("name:%s, math:%.2f, music:%.2f, dance:%.2f\n"
			   , node->caName, node->fMath, node->fMusic, node->fDance);
		node = node->pNext;
	}
}

void display(const Node **arr, int num)
{
	int i = 0;
	for (; i<num; i++)
	{
		printf("name:%s, math:%.2f, music:%.2f, dance:%.2f\n"
			   , arr[i]->caName, arr[i]->fMath, arr[i]->fMusic
			   , arr[i]->fDance);
	}
}

int comByMath(const void *a, const void *b)
{
	return (*((Node**)a))->fMath > (*((Node**)b))->fMath;
}
int comByMusic(const void *a, const void *b)
{
	return (*((Node**)a))->fMusic > (*((Node**)b))->fMusic;
}
int comByDance(const void *a, const void *b)
{
	return (*((Node**)a))->fDance > (*((Node**)b))->fDance;
}

void sort(List *list)
{
	if (NULL == list)
	{
		return;
	}

	Node **arr = (Node **)malloc(sizeof(Node*)*(list->iLen));
	Node *node = list->pFirstNode;
	int i=0;
	while (NULL != node)
	{
		arr[i] = node;
		node = node->pNext;
		i++;
	}

	//display(arr, list->iLen);
	printf("----------------\n");

	//qsort(arr, list->iLen, sizeof(Node*), comByMath);
	//qsort(arr, list->iLen, sizeof(Node*), comByMusic);
	qsort(arr, list->iLen, sizeof(Node*), comByDance);
	
	display(arr, list->iLen);
}

int main(int argc, char *argv[])
{
	List *list = mkList();
	Node *node = NULL;

	node = mkNode();
	strcpy(node->caName, "jack");
	node->fMath = 90;
	node->fMusic = 89;
	node->fDance = 67;
	insert(list, node);
	
	node = mkNode();
	strcpy(node->caName, "rose");
	node->fMath = 78;
	node->fMusic = 79;
	node->fDance = 97;
	insert(list, node);
	
	node = mkNode();
	strcpy(node->caName, "hihi");
	node->fMath = 88;
	node->fMusic = 91;
	node->fDance = 89;
	insert(list, node);

	show(list);

	printf("----------------\n");
	sort(list);


	return 0;
}
