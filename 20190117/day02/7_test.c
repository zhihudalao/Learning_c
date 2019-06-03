#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
#if 1
	char *p = "Hello World";
	int fd = open("test.txt", O_WRONLY|O_CREAT, 0664);
	write(fd, p, strlen(p));
	//write(STDOUT_FILENO, p, strlen(p));
	//write(1, p, strlen(p));
#endif

	//STDERR_FILENO

#if 1
	char caData[10] = {'\0'};
	printf("%d\n", STDIN_FILENO);
	//read(STDIN_FILENO, caData, 10);
	read(0, caData, 10);
	printf("%s\n", caData);
#endif


#if 0
	scanf("%s", caData);
	gets(caData);
	fgets(caData, 12, stdin);
	int a = 0;
	float b = 0;
	fscanf(stdin, "%d%f", &a, &b);
	printf("a=%d, b=%.2f\n", a, b);
#endif


	return 0;
}
