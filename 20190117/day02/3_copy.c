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
	//打开要拷贝的文件
	int srcfd = open(argv[1], O_RDONLY);
	if (-1 == srcfd)
	{
		perror("open src");
		exit(EXIT_FAILURE);
	}	
	//打开新的文件	
	int destfd = open(argv[2], O_WRONLY|O_CREAT, 0664);
	if (-1 == destfd)
	{
		perror("open dest");
		exit(EXIT_FAILURE);
	}	

	char caBuf[4096];
	ssize_t ret = -1;
	while (1)
	{
		ret = read(srcfd, caBuf, 4096);
		if (-1 == ret)
		{
			if (EINTR == errno)
			{
				continue;
			}
			break;
		}
		else if (0 == ret)
		{
			break;
		}
		write(destfd, caBuf, ret);	
	}
	close(srcfd);
	close(destfd);


	return 0;
}






