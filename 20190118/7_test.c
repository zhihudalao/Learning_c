#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

int compare(const void *a, const void *b)
{
	return *(int *)a < *(int*)b;
}

void bubble(int *a, int num)
{
	int i = 0;
	int j = 0;
	for (; i<num-1; i++)
	{
		for (j=0; j<num-1-i; j++)
		{
			//if (a[j] < a[j+1])
			if (compare(a+j, a+j+1))
			{
			
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int arr[5] = {12, 89, 67, 23, 77};
	qsort(arr, 5, sizeof(int), compare);

	int i=0;
	for (; i<5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");






	return 0;
}
