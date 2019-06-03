#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/*
 无名管道：一块临时的内存空间，独立于进程，电脑关机后自动被回收
 在创建该无名管道时，会自动获得该管道文件的读和写文件描述符 

 无名管道一般用于具有亲缘关系的进程间通讯
 */

int main(int argc, char *argv[])
{
	int pipefd[2] = {0};
	int ret = pipe(pipefd);
	if (-1 == ret)
	{
		perror("pipe");
	}
	else
	{
		printf("%d %d\n", pipefd[0], pipefd[1]);
	}

	pid_t pid = fork();
	if (pid > 0)
	{
		char caMsg[256] = {'\0'};
		while (1)
		{
			printf("父进程输入数据:\n");
			scanf("%s", caMsg);
			write(pipefd[1], caMsg, strlen(caMsg));		
			if (0 == strcmp("exit", caMsg))
			{
				wait(NULL);
				printf("父进程给子进程收完尸\n");
				break;
			}
//			sleep(1);
//			read();
		}
	}
	else if (0 == pid)
	{
		char caMsg[256] = {'\0'};
		while (1)
		{
			memset(caMsg, 0, sizeof(caMsg));
			read(pipefd[0], caMsg, sizeof(caMsg));
			if (0 == strcmp("exit", caMsg))
			{
				break;
			}	
			printf("子进程读到数据:%s\n", caMsg);
		}
	}


	return 0;
}





