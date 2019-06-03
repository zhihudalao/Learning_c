#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if (0 == pid)
	{
		fork();
	}

	printf("selfpid=%d,  ppid=%d\n", getpid(), getppid());

//	pause();
	while (1){}

	return 0;
}
