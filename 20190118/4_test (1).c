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
	char tmp[256] = {'\0'};
	char *pos = argv[1];
	int ret = -1;
	while (1)
	{
		pos = strchr(pos, '/');
		if (NULL != pos)
		{
			memset(tmp, 0, sizeof(tmp));	
			strncpy(tmp, argv[1], pos-argv[1]+1);
			ret = mkdir(tmp, 0777);
			if (-1 == ret)
			{
				if (EEXIST != errno)
				{
					printf("mk %s failed --> %s\n"
						   , tmp, strerror(errno));
				}
			}
			pos++;
		}	
		else
		{
			ret = mkdir(argv[1], 0777);
			if (-1 == ret)
			{
				printf("mk %s failed --> %s\n", tmp, strerror(errno));
			}
			break;
		}
	}

	return 0;
}
