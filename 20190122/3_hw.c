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

	char caCommand[32] = {'\0'};
	char *pNote = "^_^@^_^:";
	int bak = dup(STDOUT_FILENO);
	pid_t pid = -1;
	while (1)
	{
		dup2(bak, STDOUT_FILENO);
		write(STDOUT_FILENO, pNote, strlen(pNote));
		scanf("%s", caCommand);
		if (0 == strcmp("exit", caCommand))
		{
			break;
		}
		pid = fork();
		if (pid > 0)
		{
			wait(NULL);
		}
		else if (0 == pid)
		{
			dup2(fd, STDOUT_FILENO);
			execlp(caCommand, caCommand, NULL);
			break;
		}
	}

	return 0;
}





