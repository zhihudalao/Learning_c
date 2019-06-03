#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_WRONLY);
	if (-1 == fd)
	{
		perror("^_^ -->");
	}
	else
	{
		close(fd);
	}


	return 0;
}
