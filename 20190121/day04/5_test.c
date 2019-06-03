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
	fork();
	fork() && fork() || fork();
	printf("sssss\n");

#if 0
	int i = 0;
	for (; i<2; i++)
	{
		fork();
//		write(STDOUT_FILENO, "g", 1);
//		fwrite("g", 1, 1, stdout);
	}
#endif

#if 0
	//printf("hahaha\n");
	printf("hahaha");
	while (1)
	{
//		sleep(5);
//		break;
	}
#endif

#if 0
	int i = 0;
	for (; i<2; i++)
	{
		fork();
		//printf("g\n");
		printf("g");
	}
#endif


#if 0
	fork();
	fork();	
	printf("pid = %d\n", getpid());
#endif
	return 0;
}
