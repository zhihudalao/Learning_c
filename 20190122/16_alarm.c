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

int main(int argc, char *argv[])
{
	alarm(10);
	int i = 0;
	while (1)
	{
		printf("while --> %d\n", ++i);
		sleep(1);
	}

	return 0;
}





