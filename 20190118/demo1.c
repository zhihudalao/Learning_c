#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc,char**argv){
  int i=0;
  for(;i<argc-1;i++){
    int ret = mkdir(argv[i+1], 0777);
	if (-1 == ret)
	{
		perror("mkdir");
		exit(EXIT_FAILURE);
	}

	printf("mk %s ok\n", argv[i+1]);
  }
  return 0;
}
