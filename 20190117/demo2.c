#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

double getIntFromSTDIN()
{
	char caBuf[512] = {'\0'};
	read(STDIN_FILENO, caBuf, 512);
	char *p = strchr(caBuf, '\n');
	//若找到了'\n'则表示将输入缓存的数据全部读取掉了
	if (NULL != p)
	{
		*p = '\0';
	}
	else
	{
		//若没有找到'\n',则表示将输入缓存中含有数据
		//则需要循环将缓存中的数据读取掉
		caBuf[511] = '\0';
		while ('\n' != getchar()){}
	}
	double num = -1;
	//从caBuf中按照指定的格式读取数据放入num中
	sscanf(caBuf, "%g", &num);
	return num;
}


int main(void)
{
	double ret = getIntFromSTDIN();
	printf("ret = %lf\n", ret);

	return 0;
}
