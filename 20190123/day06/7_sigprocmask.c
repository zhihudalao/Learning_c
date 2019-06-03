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
	//若在处理A信号的过程中，又发生了A信号
	//则会先处理完当前的A信号，再去处理后面到来的A信号
	//若后面A信号到来多次，则只会处理一次
	if (SIGINT == sig)
	{
		printf("@@@@@@@@@@@@@\n");
		int i = 10;
		while (i)
		{
			printf("int while...%d\n", i);
			i--;
			sleep(1);
		}
	}
}

int main(int argc, char *argv[])
{
	signal(SIGINT, handle);

	while (1)
	{
		pause();
	}
		
		
	return 0;
}





