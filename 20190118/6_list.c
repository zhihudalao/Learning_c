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
	off_t size;
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

void insert(List *list, const char *name, off_t size)
{
	if (NULL == name || NULL == list)
	{
		return;
	}	
	Node *node = mkNode();
	strcpy(node->caName, name);
	node->size = size;

	node->pNext = list->pFirstNode;
	list->pFirstNode = node;
	list->iLen++;
}

void show(const List *list)
{
	Node *node = list->pFirstNode;
	while (NULL != node)
	{
		printf("%s\t\t%ld\n", node->caName, node->size);
		node = node->pNext;
	}
}

void init(const char *path, List *list)
{
	if (NULL == path || NULL == list)
	{
		return;
	}
	DIR *dir = opendir(path);
	if (NULL == dir)
	{
		perror("0_0 --> ");
		exit(EXIT_FAILURE);
	}
	struct dirent *pdirent = NULL;
	char caPath[256] = {'\0'};
	struct stat buf;
	while (1)
	{
		pdirent = readdir(dir);
		if (NULL == pdirent)
		{
			break;
		}
		if (0 == strncmp(".", pdirent->d_name, 1))	
		{
			continue;
		}
//		printf("%s\t", pdirent->d_name);	
		memset(caPath, 0, sizeof(caPath));

		//   /home/wtp/zr1807/day03     6_test.c
		strcat(caPath, path);
		strcat(caPath, "/");
		strcat(caPath, pdirent->d_name);
//		printf("%s\n", caPath);
		stat(caPath, &buf);
//		printf("size --> %ld\n", buf.st_size);
	
		insert(list, pdirent->d_name, buf.st_size);
	}
}

void display(const Node **arr, int num)
{
	int i = 0;
	for (; i<num; i++)
	{
		printf("%s\t\t%ld\n", arr[i]->caName, arr[i]->size);
	}
}

int compare(const void *a, const void *b)
{
	return (*((Node**)a))->size > (*((Node**)b))->size;
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

	display(arr, list->iLen);
	printf("----------------\n");

	qsort(arr, list->iLen, sizeof(Node*), compare);
	
	display(arr, list->iLen);
}

int main(int argc, char *argv[])
{
	List *list = mkList();
	init(argv[1], list);
	show(list);

	printf("----------------\n");
	sort(list);


	return 0;
}
