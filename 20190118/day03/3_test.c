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
	int ret = -1;
	int i = 1;
	while (NULL != argv[i])
	{	
		ret = mkdir(argv[i], 0777);
		if (-1 == ret)
		{
			perror("mkdir");
			exit(EXIT_FAILURE);
		}
		printf("mk %s ok\n", argv[i]);
		i++;
	}

	return 0;
}
