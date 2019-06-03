#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR *dir = opendir(argv[1]);
	if (NULL == dir)
	{
		perror("0_0 --> ");
		exit(EXIT_FAILURE);
	}

	struct dirent *pdirent = NULL;
	while (1)
	{
		pdirent = readdir(dir);
		if (NULL == pdirent)
		{
			break;
		}
		if (0 == strncmp(".", pdirent->d_name, 1))	
		{
			continue;
		}
		printf("%s\t", pdirent->d_name);	
		switch (pdirent->d_type)
		{
		case DT_DIR:
			printf("is a directory\n");
			break;
		case DT_REG:
			printf("is a regular file\n");
			break;
		default:
			printf("is unknow file\n");
			break;
		}
	}
	printf("\n");

	return 0;
}
