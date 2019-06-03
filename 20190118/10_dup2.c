#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDWR|O_CREAT, 0664);
	printf("fd = %d\n", fd);
	printf("stdout_fileno = %d\n", STDOUT_FILENO);

	write(STDOUT_FILENO, "hello", 5);

	dup2(fd, STDOUT_FILENO);
	
	write(STDOUT_FILENO, "rose", 4);


	return 0;
}
