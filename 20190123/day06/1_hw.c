#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <signal.h>

int g_fd = -1;
int g_i = 0;
char caData[64] = {'\0'};

void child(int sig)
{
	if (SIGALRM == sig)
	{
		sprintf(caData, "hello --> %d \n", ++g_i);
		write(g_fd, caData, strlen(caData));
		alarm(1);	
	}
	else if (SIGINT == sig)
	{
//		exit(EXIT_SUCCESS);
		raise(SIGKILL);
	}
}

void parent(int sig)
{
	if (SIGCHLD == sig)
	{
		wait(NULL);
		printf("child process end\n");
	}
}

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGCHLD, parent);
		int i = 0;
		while (1)
		{
			printf("parent --> %d\n", ++i);
			sleep(1);
		}
	}
	else if (0 == pid)
	{
		char path[256] = {'\0'};
		getcwd(path, sizeof(path));
		printf("子进程获得当前工作路径:%s\n", path);
		strcat(path, "/");
		strcat(path, "1.txt");
		printf("创建文件的路径:%s\n", path);

		g_fd = open(path, O_WRONLY|O_CREAT|O_APPEND, 0664);
		signal(SIGINT, child);
		signal(SIGALRM, child);
		alarm(1);
		while (1)
		{
			//挂起程序，当收到信号，在信号处理完之后解除挂起往下执行
			pause();
		}
	}
	else if (-1 == pid)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	return 0;
}





