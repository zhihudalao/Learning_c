#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct Test
{
	int c;
	char data[4];
}Test;

int main(void)
{
	void *addr = malloc(1024);
	Test *t = (Test *)addr;
	t->c = 8980;
	strcpy(t->data, "上海自来水来自上海");
	strcat(t->data, "黄山落叶松叶落山黄");

	printf("%d\n", t->c);
	printf("%s\n", t->data);

	return 0;
}
