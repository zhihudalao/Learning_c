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
	int bak = dup(STDOUT_FILENO);
	int fd = open(argv[1], O_RDWR|O_CREAT, 0664);
	dup2(fd, STDOUT_FILENO);

	int i = 0;
	int j = 0;
	char caData[256] = {'\0'};
	for (i=1; i<=9; i++)
	{
		for (j=1; j<=i; j++)
		{
			sprintf(caData, "%d*%d=%d ", j, i, j*i);
			write(STDOUT_FILENO, caData, strlen(caData));
		
			fprintf();
		}
		write(STDOUT_FILENO, "\n", 1);
	}
	close(STDOUT_FILENO);
	
	dup2(bak, STDOUT_FILENO);
	write(STDOUT_FILENO, "OK\n", 3);

	return 0;
}
