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
	int i = 0;
	int fd = -1;
	for (i=1; i<argc; i++)
	{
		fd = creat(argv[i], 0664);
		if (-1 == fd)
		{
			//strerror:返回错误编号对应的错误信息
			printf("errno = %d, error = %s\n"
				   , errno, strerror(errno));
		}
		else
		{
			printf("fd = %d\n", fd);
//			close(fd);   //关闭文件
		}
	}
	return 0;
}
