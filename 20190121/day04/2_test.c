#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i = 0;
	while (1)
	{
		printf("data --> %d\n", ++i);
		sleep(1);
	}

	return 0;
}
