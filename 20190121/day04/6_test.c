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
	if (pid > 0)
	{
		printf("父进程:父进程号-->%d，本身进程号-->%d，子进程号-->%d\n"
			   , getppid(), getpid(), pid);
//		sleep(5);
	}
	else if (0 == pid)
	{
		printf("子进程:父进程号-->%d，本身进程号-->%d\n"
			   , getppid(), getpid());
	}
	else if (-1 == pid)
	{
		perror("fork");
	}



	return 0;
}
