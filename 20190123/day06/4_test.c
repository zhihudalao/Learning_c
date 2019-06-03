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

void handle(int sig)
{
	if (SIGQUIT == sig)  // ctrl+\
	{
		printf("hello\n");
	}
	else if (SIGTSTP == sig)  // ctrl+z
	{
		printf("world\n");
	}
}

int main(int argc, char *argv[])
{
	signal(SIGQUIT, handle);
	signal(SIGTSTP, handle);
	while (1)
	{
		//挂起程序，当收到信号，在信号处理完之后解除挂起往下执行
		pause();
	}
	return 0;
}





