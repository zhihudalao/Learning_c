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
		char caData[32] = {'\0'};

		lseek(fd, 0, SEEK_SET);
		read(fd, caData, 10);
		printf("-->%s<--\n", caData);

		memset(caData, '\0', sizeof(caData));
		lseek(fd, 30, SEEK_CUR);
		read(fd, caData, 5);
		printf("-->%s<--\n", caData);
		
		memset(caData, '\0', sizeof(caData));
		lseek(fd, -15, SEEK_CUR);
		read(fd, caData, 10);
		printf("-->%s<--\n", caData);
		
		memset(caData, '\0', sizeof(caData));
		lseek(fd, -20, SEEK_END);
		read(fd, caData, 10);
		printf("-->%s<--\n", caData);

		close(fd);
	}

	return 0;
}

