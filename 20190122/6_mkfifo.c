#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if (-1 == access(argv[1], F_OK))
	{
		int ret = mkfifo(argv[1], 0664);
		if (-1 == ret)
		{
			perror("mkfifo");
			exit(EXIT_FAILURE);
		}
	}

	int fd = open(argv[1], O_WRONLY);

	char caMsg[64] = {'\0'};
	while (1)
	{
		printf("请输入数据:\n");
		scanf("%s", caMsg);
		write(fd, caMsg, strlen(caMsg));
		if (0 == strcmp("exit", caMsg))
		{
			break;
		}
	}

	close(fd);


	return 0;
}





