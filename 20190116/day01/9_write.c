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
	int fd = open(argv[1], O_WRONLY|O_CREAT|O_APPEND, 0664);
	if (-1 == fd)
	{
		perror("^_^ -->");
	}
	else
	{
		char caBuf[256] = {'\0'};
		ssize_t ret = -1;
		while (1)
		{
			printf("请输入要保存的数据:\n");
			scanf("%s", caBuf);
			if (0 == strcmp("exit", caBuf))
			{
				break;
			}
			ret = write(fd, caBuf, strlen(caBuf));
			if (-1 == ret)
			{
				perror("write -_- --> :");
				break;
			}
			printf("^_^ write %ld byts to file\n", ret);
		}
		close(fd);
	}


	return 0;
}
