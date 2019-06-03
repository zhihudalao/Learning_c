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

void fun(int sig)
{
	if (SIGINT == sig)
	{
		printf("哈哈，你干不掉我....\n");
	}
}

int main(int argc, char *argv[])
{
	signal(SIGINT, fun);
	int i = 0;
	while (1)
	{
		printf("while --> %d\n", ++i);
		sleep(1);
	}

	return 0;
}





