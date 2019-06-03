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
		int status;
		pid_t ret = wait(&status);
		if (WIFEXITED(status))
		{
			printf("正常结束\n");
		}
		printf("对%d进程收尸\n", ret);
		printf("子进程返回值：%d\n", WEXITSTATUS(status));
		while (1)
		{
			printf("this is parent\n");
			sleep(1);
		}	
	}
	else if (0 == pid)
	{
		int i = 5;
		while (i--)
		{
			printf("this is child\n");
			sleep(1);
		}
		return 168;
	}
	else if (-1 == pid)
	{
		perror("fork");
	}

	return 0;
}
