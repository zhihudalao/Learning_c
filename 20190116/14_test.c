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
	int fd = open(argv[1], O_RDWR|O_CREAT, 0664);
	if (-1 != fd)
	{
		lseek(fd, 0, SEEK_SET);

		STU stu;
		read(fd, &stu, sizeof(STU));
		printf("id:%d, name:%s, score:%.2f\n"
			   , stu.iId, stu.caName, stu.fScore);
	
		lseek(fd, 3*sizeof(STU), SEEK_CUR);	
		read(fd, &stu, sizeof(STU));
		printf("id:%d, name:%s, score:%.2f\n"
			   , stu.iId, stu.caName, stu.fScore);

		off_t  off = -4*sizeof(STU);
		lseek(fd, off, SEEK_CUR);	
		read(fd, &stu, sizeof(STU));
		printf("id:%d, name:%s, score:%.2f\n"
			   , stu.iId, stu.caName, stu.fScore);


		close(fd);
	}

	return 0;
}

