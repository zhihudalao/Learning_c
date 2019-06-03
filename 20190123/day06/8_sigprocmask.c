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
	//做处理A信号的过程中，又到来了B信号
	//则会暂停当前A信号的处理，先去处理B信号
	//处理完B信号之后，再回来接着处理之前的A信号
	if (SIGINT == sig)
	{
		printf("@@@@@@@@@@@@@\n");
		int i = 0;
		while (1)
		{
			printf("int while...%d\n", ++i);
			sleep(1);
		}
	}
	else if (SIGTSTP == sig)
	{
		printf("ctrl+z ....\n");
	}
}

int main(int argc, char *argv[])
{
	signal(SIGINT, handle);
	signal(SIGTSTP, handle);

	while (1)
	{
		pause();
	}
		
		
	return 0;
}





