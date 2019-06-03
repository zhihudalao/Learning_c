#include<stdio.h>

int main(int argc,char** argv){
	int a=31;//11111
	printf("%d\n",a&=~(1<<3));//10111

	int b=8;//1000
	printf("%d\n",b|=(1<<0));//1001
	return 0;
}

