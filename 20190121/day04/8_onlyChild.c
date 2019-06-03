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
		int i = 0;
		while (1)
		{
			printf("this is parent pid = %d--> %d\n", getpid(), ++i);
			sleep(1);
			if (5 == i)
			{
				break;
			}
		}	
	}
	else if (0 == pid)
	{
		int i = 0;
		while (1)
		{
			printf("this is child ppid=%d --> %d\n", getppid(), ++i);
			sleep(1);
			if (20 == i)
			{
				break;
			}
		}
	}
	else if (-1 == pid)
	{
		perror("fork");
	}

	return 0;
}
