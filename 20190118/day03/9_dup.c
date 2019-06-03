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
	printf("stdout_fileno = %d\n", STDOUT_FILENO);
	int fd = dup(STDOUT_FILENO);
	printf("fd = %d\n", fd);

	write(STDOUT_FILENO, "hello", 5);
	write(fd, "world", 5);


	return 0;
}
