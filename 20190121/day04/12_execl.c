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
	//execl("/bin/ls", "ls", "-l", "/home/wtp", NULL);
	int i = 10;
	while (i)
	{
		printf("pid = %d\n", getpid());
		i--;
		sleep(1);
	}
	//execl("/usr/bin/gedit", "gedit", "11_test.c", NULL);
	execl("/home/wtp/zr1807/day04/mytest", "mytest", NULL);
	printf("^_^ *_* -_- 0_0 >_< '_' :_: \n");


	return 0;
}
