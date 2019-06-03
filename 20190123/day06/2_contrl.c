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

pid_t pid = -1;

void handle(int sig)
{
	if (SIGINT == sig)
	{
		kill(pid, SIGINT);
	}
}

int main(int argc, char *argv[])
{
	pid = atoi(argv[1]);
	signal(SIGINT, handle);
	while (1)
	{
		pause();
	}

	return 0;
}





