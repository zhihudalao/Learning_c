#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if (2 != argc)
	{
		printf("运行参数不对\n");
		exit(EXIT_FAILURE);
	}
	int fd = open(argv[1], O_RDWR|O_CREAT, 0664);
	if (-1 == fd)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}	
	
	pid_t pid = fork();
	if (pid > 0)
	{
		char caData[128] = {'\0'};
		ssize_t ret = -1;
		while (1)
		{
			printf("请输入数据:\n");
			ret = read(STDIN_FILENO, caData, sizeof(caData));
			if (-1 == ret)
			{
				break;
			}
			write(fd, caData, ret);
		}
	}
	else if (0 == pid)
	{
		off_t newsize = -1;
		off_t oldsize = -1;
		while (1)
		{
			newsize = lseek(fd, 0, SEEK_END);
			if (newsize != oldsize)
			{
				printf("file size --> %ld\n", newsize);
				oldsize = newsize;
			}
		}
	}
	else if (-1 == pid)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
		
	return 0;
}
