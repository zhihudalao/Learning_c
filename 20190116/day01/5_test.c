#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

//r:4  w:2  x:1
// ./a.out  pathname
int main(int argc, char *argv[])
{// && || ！   
	umask(0000);  //  mode & ~mask	
	int fd = creat(argv[1], 0666);
	if (-1 == fd)
	{
		//strerror:返回错误编号对应的错误信息
		printf("errno = %d, error = %s\n", errno, strerror(errno));		
	}
	else
	{
		printf("fd = %d\n", fd);
		close(fd);   //关闭文件
	}

	/*
	 if ("aaaa")
	 if (-90)
	 if (3.14)
	 {
	 	printf("hello world\n");
	 }
	 
	 
	 */




	return 0;
}
