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
	char *p = "jack and rose";
	printf("%p\n", p);
	printf("%p\n", "jack and rose");
//	*p = 'A';

	printf("%c\n", p[0]);
	printf("%c\n", "jack and rose"[3]);
	printf("%p\n", "jack and rose");

	char arr[] = "jack and rose";
	arr[0] = 'A';
	printf("%p\n", "jack and rose");

	return 0;
}
