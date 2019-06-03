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
	int fd = open(argv[1], O_RDWR|O_CREAT, 0664);
	if (-1 != fd)
	{
		off_t ret = lseek(fd, 0, SEEK_END);
		if (-1 == ret)
		{
			perror("lseek");
		}
		else
		{
			printf("%s size --> %ld\n", argv[1], ret);
		}

		close(fd);
	}

	return 0;
}
