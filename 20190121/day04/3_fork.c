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
	int num = 0;
	char caData[64] = {'\0'};

	printf("1234567890\n");
	pid_t pid = fork();
	printf("after fork\n");
	if (pid > 0)
	{
		num = 3;
		strcpy(caData, "parent");	
	}
	else if (0 == pid)
	{
		num = 6;
		strcpy(caData, "child");
	}
	else if (-1 == pid)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
		
	int i = 0;
	for (; i<num; i++)
	{
		printf("%s\n", caData);
		sleep(1);
	}	
		
	return 0;
}
