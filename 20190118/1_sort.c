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
	int srcfd = open(argv[1], O_RDONLY);
	off_t size = lseek(srcfd, 0, SEEK_END);
	lseek(srcfd, 0, SEEK_SET);

	char *data = (char*)malloc(size+1);
	memset(data, 0, size+1);

	read(srcfd, data, size);
	printf("data -->  %s\n", data);
	//break;
		
	int *buf = (int *)malloc(sizeof(int)*size);
	int i = 0;
	char *pos = data;
	while (1)
	{
		if (1 != sscanf(pos, "%d", buf+i))
		{
			break;
		}
//		printf("%d\n", buf[i]);
//		sleep(1);
		i++;
		pos = strchr(pos, '\n');
		if (NULL == pos)
		{
			break;
		}
		pos++;
	}
/*
	int j = 0;
	for (; j<i; j++)
	{
		printf("%d ", buf[j]);
	}
	printf("\n");
*/

	int m = 0;
	int n = 0;
	int tmp = 0;
	for (; m<i-1; m++)
	{
		for (n=0; n<i-1-m; n++)
		{
			if (buf[n] < buf[n+1])
			{
				tmp = buf[n+1];
				buf[n+1] = buf[n];
				buf[n] = tmp;
			}
		}
	}

	int j = 0;
	for (; j<i; j++)
	{
		printf("%d ", buf[j]);
	}
	printf("\n");

	int destfd = open(argv[2], O_WRONLY|O_CREAT, 0664);

	char arr[32] = {'\0'};
	for (j=0; j<i; j++)
	{
		sprintf(arr, "%d\n", buf[j]);
		write(destfd, arr, strlen(arr));
	}

	close(srcfd);
	close(destfd);

	return 0;
}
