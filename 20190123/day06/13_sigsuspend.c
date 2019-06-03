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
	if (SIGALRM == sig)
	{
		printf("alrm --- alrm\n");
	}
	else if (SIGINT == sig)
	{
		printf("ctrl+c...\n");
	}
}

int main(int argc, char *argv[])
{
	signal(SIGALRM, handle);	
	signal(SIGINT, handle);	

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGALRM);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_BLOCK, &set, NULL);

	alarm(10);

	sigset_t replace;
	sigemptyset(&replace);
	sigaddset(&replace, SIGTSTP);

	sigsuspend(&replace);


	//pause();

	// do something
	while (1)
	{
		printf("main while ....\n");
		sleep(1);
	}
		
	return 0;
}





