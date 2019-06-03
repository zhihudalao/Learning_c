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
	if (SIGCHLD == sig)
	{
		wait(NULL);
		printf("替子进程收完尸...\n");
	}
}

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if (pid > 0)
	{
		signal(SIGCHLD, handle);
		int i = 0;
		while (1)
		{
			printf("parent --> %d\n", ++i);
			sleep(1);
		}
	}
	else if (0 == pid)
	{
		int i = 0;
		while (1)
		{
			printf("child --> %d\n", ++i);
			sleep(1);	
			if (10 == i)
			{
				break;
			}
		}
	}

	return 0;
}





