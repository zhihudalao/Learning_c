#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	FILE *file = fopen("./test.info", "r+");
	if (NULL != file)
	{
		fputs("上海自来水来自海上", file);
		fclose(file);
	}
	else
	{
		printf("open failed\n");	
	}

	return 0;
}
