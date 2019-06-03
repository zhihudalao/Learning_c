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
	if (SIGINT == sig)
	{
		printf("@@@@@@@@@@@@@\n");
		int i = 0;
		while (1)
		{
			printf("int while...%d\n", ++i);
			sleep(1);
			if (10 == i)
			{
				break;
			}
		}
	}
	else if (SIGTSTP == sig)
	{
		printf("ctrl+z ....\n");
	}
	else if (SIGQUIT == sig)
	{
		printf("ctrl+/ ....\n");
	}
}

int main(int argc, char *argv[])
{
	signal(SIGTSTP, handle);
	signal(SIGQUIT, handle);

	struct sigaction act;
	struct sigaction old;

	act.sa_handler = handle;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGTSTP);
//	sigaddset(&act.sa_mask, SIGTSTP);
	
	sigaction(SIGINT, &act, &old);

	while (1)
	{
		pause();
	}
		
		
	return 0;
}





