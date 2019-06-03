#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define FILE_LEN 256

typedef struct Info
{
	char caName[FILE_LEN];
	off_t size;
}Info;

//typedef long int off_t
//typedef long int ssize_t    
//double *p = (double *)malloc(1024);   (*p)  --> 8
// char *p ;   *p  --> 1
// int *p ;  *p

//Info *p = (Info*)malloc(sizeof(Info));


void sort(Info *info, int num)
{
	Info tmp;
	int i = 0;
	int j = 0;
	for (; i<num-1; i++)
	{
		for (j=0; j<num-1-i; j++)
		{
			if (info[j].size < info[j+1].size)
			{
				tmp = info[j];
				info[j] = info[j+1];
				info[j+1] = tmp;
			}
		}
	}
}

void show(const Info *info, int num)
{
	int i = 0; 
	for (; i<num; i++)
	{
		printf("%s --> %ld\n", info[i].caName, info[i].size);
	}
}
//   ./a.out  aa bb cc
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("参数不对");
		exit(EXIT_FAILURE);
	}
	Info *info = (Info*)malloc((argc-1)*sizeof(Info));
	int i = 0;
	struct stat buf;
	for (i=1; i<argc; i++)
	{
		strcpy(info[i-1].caName, argv[i]);
		stat(argv[i], &buf);	
		info[i-1].size = buf.st_size;
	}	
	show(info, argc-1);

	sort(info, argc-1);

	printf("---------------------\n");
	show(info, argc-1);

		
	return 0;
}
