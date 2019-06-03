#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

typedef struct STU
{
	int iId;
	char caName[32];
	float fScore;
}STU;

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	if (-1 != fd)
	{
		STU stu;
		ssize_t ret = -1;
		while (1)
		{
			ret = read(fd, &stu, sizeof(STU));
			if (0 == ret)
			{
				break;
			}
			else if (-1 == ret)
			{
				if (EINTR == ret)
				{
					continue;
				}
			}
			printf("id:%d, name:%s, score:%.2f\n", stu.iId
				   , stu.caName, stu.fScore);
		}
		close(fd);
	}

	return 0;
}
