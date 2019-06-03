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
	pid_t pid = fork();
	if (pid > 0)
	{
	}
	else if (0 == pid)
	{
		int i = 0;
		pid_t pid2 = -1;
		for (; i<100; i++)
		{
			pid2 = fork();
			if (0 == pid2)
			{
				printf("创建第%d个僵尸进程-->%d\n", i+1, getpid());
				break;
			}
		}
		if (pid2>0)
		{
			while (1)
			{}
		}
	}
	else if (-1 == pid)
	{
		perror("fork");
	}

	return 0;
}
