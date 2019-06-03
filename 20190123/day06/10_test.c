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
//		sigprocmask(SIG_UNBLOCK, &set, NULL);
	}
	else if (SIGTSTP == sig)
	{
		printf("ctrl+z ....\n");
	}
	else if (SIGQUIT == sig)
	{
		while (1)
		{
			printf("ctrl+/ ....\n");
			sleep(1);
		}
	}
}

int main(int argc, char *argv[])
{
	signal(SIGINT, handle);
	signal(SIGTSTP, handle);
	signal(SIGQUIT, handle);
		
	sigset_t set;
	sigset_t old;

	sigemptyset(&set);
//		sigfillset(&set);
	sigaddset(&set, SIGTSTP);

	sigprocmask(SIG_BLOCK, &set, &old);

	while (1)
	{
		pause();
	}
		
		
	return 0;
}





