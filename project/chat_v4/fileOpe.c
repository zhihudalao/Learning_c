#include "fileOpe.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define USR_PATH "./usr.info"

//打开文件
int openFile(const char *path, int flags)
{
	int fd = open(path, flags|O_CREAT, 0664);
	if (-1 == fd)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return fd;
}

//将用户链表保存到文件中
void saveUsrToFile(const UsrLink *link)
{
	if (NULL == link)
	{
		return;
	}
	int fd = openFile(USR_PATH, O_WRONLY);
	UsrNode *node = link->pFirstNode;
	while (NULL != node)
	{
		write(fd, node, sizeof(UsrNode));
		node = node->pNext;
	}
	close(fd);
}

//将文件中的用户信息读取出来放到链表中
void getUsrFromFile(UsrLink *link)
{
	if (NULL == link)
	{
		return;
	}
	int fd = openFile(USR_PATH, O_RDONLY);
	UsrNode *node = NULL;
	ssize_t ret = -1;
	while (1)
	{
		node = mkUsrNode();
		ret = read(fd, node, sizeof(UsrNode));
		if (-1 == ret)
		{
			if (EINTR == errno)
			{
				free(node);
				continue;
			}
			perror("read usr node from file");
			exit(EXIT_FAILURE);
		}
		else if (0 == ret)
		{
			free(node);
			break;
		}
		node->sockfd = 0;
		node->pNext = NULL;
		insertUsrLink(node, link);
	}
	close(fd);
}









