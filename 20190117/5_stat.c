#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
//./r  aa bb cc dd ee ff  -->   bbb 789  aaa 678   ccc 567
int main(int argc, char *argv[])
{
	struct stat s;	
	int ret = stat(argv[1], &s);
	if (-1 == ret)
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}

	if (S_ISREG(s.st_mode))
	{
		printf("%s is a regular file\n", argv[1]);
	}
	else if (S_ISDIR(s.st_mode))
	{
		printf("%s is a directory\n", argv[1]);
	}
	else
	{
		printf("%s is unknow file type\n", argv[1]);
	}

	return 0;
}






