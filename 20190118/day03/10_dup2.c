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
	int fd = open(argv[1], O_RDWR|O_CREAT, 0664);
	printf("fd = %d\n", fd);
	printf("stdout_fileno = %d\n", STDOUT_FILENO);

	write(STDOUT_FILENO, "hello", 5);
	//bak表示标准输出	
	int bak = dup(STDOUT_FILENO);

	//STDOUT_FILENO和fd作为同一个文件的文件描述符
	dup2(fd, STDOUT_FILENO);
	//"rose"会写入文件，而不是标准输出
	write(STDOUT_FILENO, "rose", 4);
	
	//重新将STDOUT_FILENO作为标准输出的文件描述符
	dup2(bak, STDOUT_FILENO);
	write(STDOUT_FILENO, "^_^\n", 4);

	return 0;
}
