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
	int fd = open(argv[1], O_WRONLY|O_CREAT, 0664);
	if (-1 == fd)
	{
		return;
	}

	double data[99999];
	long int left = sizeof(data);
#if 1
	printf("size = %ld\n", left);
	long int writed = 0;
	ssize_t ret = 0;
	while (left)
	{
		if (left < 4096)
		{
			ret = write(fd, (char*)data+writed, left);
		}
		else
		{
			ret = write(fd, (char*)data+writed, 4096);
		}
		if (-1 == ret)
		{
			if (EINTR == errno)
			{
				continue;
			}
			break;
		}
		left -= ret;
		writed += ret;
	}
	printf("writed = %ld\n", writed);
#endif

	return 0;
}






