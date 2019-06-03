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

void init(STU *stu, int num)
{
	static int siId = 1001;
	int i = 0;
	for (; i<num; i++)
	{
		printf("请输入学生姓名，成绩:\n");
		stu[i].iId = siId;
		siId++;
		scanf("%s%f", stu[i].caName, &stu[i].fScore);
	}
}

void show(const STU *stu, int num)
{
	int i = 0;
	for (; i<num; i++)
	{
		printf("id:%d, name:%s, score:%.2f\n"
		       , stu[i].iId, stu[i].caName, stu[i].fScore);
	}
}

void save(const char *path, const STU *stu, int num)
{
	if (NULL == path || NULL == stu || num <= 0)
	{
		return;
	}
	int fd = open(path, O_WRONLY|O_CREAT|O_TRUNC, 0664);
	if (-1 == fd)
	{
		perror("open");
		return;
	}
	int i = 0;
	ssize_t ret = -1;
	for (; i<num;)
	{
		ret = write(fd, stu+i, sizeof(STU));
		if (-1 == ret)
		{
			if (EINTR == errno)
			{
				continue;
			}
			break;
		}
		i++;
	}
	close(fd);
}

int main(int argc, char *argv[])
{
	int num = 0;
	printf("请输入学生的个数:\n");
	scanf("%d", &num);

	STU *stu = (STU *)malloc(num*sizeof(STU));

	init(stu, num);
	show(stu, num);

	save(argv[1], stu, num);

	return 0;
}
