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

	int fd = open(argv[1], O_RDONLY);

	char caMsg[64] = {'\0'};
	ssize_t ret = -1;
	while (1)
	{
		memset(caMsg, 0, sizeof(caMsg));
		read(fd, caMsg, sizeof(caMsg));
		if (0 == strcmp("exit", caMsg))
		{
			break;
		}
		printf("recv msg --> %s\n", caMsg);
	}

	close(fd);


	return 0;
}





