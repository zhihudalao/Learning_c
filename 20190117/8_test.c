#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
//输入任意个整数，求和
int main(void)
{
	int num = 0;
	int sum = 0;
	while (1)
	{
		if (1 == scanf("%d", &num))
		{
			sum += num;
		}
		else
		{
			break;
		}
	}
	printf("sum = %d\n", sum);

#if 0		
	int num = 0;
	while (1)
	{
		if (1 == scanf("%d", &num))
		{
			printf("num = %d\n", num);
		}
		else
		{
			while ('\n' != getchar()){}
		}
	}
#endif

	return 0;
}
