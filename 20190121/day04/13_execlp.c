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
	//execlp("ls", "ls", "-l", "/home/wtp", NULL);
	//execlp("gedit", "gedit", "11_test.c", NULL);
	execlp("mytest", "mytest", NULL);
	printf("^_^ *_* -_- 0_0 >_< '_' :_: \n");


	return 0;
}
