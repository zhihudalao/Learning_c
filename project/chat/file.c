#include "file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int openFile(const char *path, int flags)
{
	int fd = -1;
	if (NULL != path)
	{
		fd = open(path, flags|O_CREAT, 0664);
		if (-1 == fd)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
	}
	return fd;
}

void saveListToFile(const char *path, const List *list)
{
	if (NULL == path || NULL == list)
	{
		return;
	}
	int fd = openFile(path, O_WRONLY|O_TRUNC);
	Node *node = list->pFirstNode;
	while (NULL != node)
	{
		write(fd, node, sizeof(Node));
		node = node->pNext;
	}
	close(fd);
}

void getListFromFile(const char *path, List *list)
{
	if (NULL == path || NULL == list)
	{
		return;
	}
	int fd = openFile(path, O_RDONLY);
	ssize_t ret = -1;
	Node *node = NULL;
	while (1)
	{
		node = mkNode();
		ret = read(fd, node, sizeof(Node));
		if (-1 == ret)
		{
			if (EINTR == errno)
			{
				free(node);	
				continue;
			}
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (0 == ret)
		{
			free(node);
			break;
		}
		node->sockfd = -1;
		node->pNext = NULL;
		insert(list, node);
	}	
}








