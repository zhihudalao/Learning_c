#include<stdio.h>

int main(int argc,char** argv){
	int a=5,b=10;
/*
	int mid=0;
	mid=a;
	a=b;
	b=mid;
*/
/*
	a=a+b;//a=15,b=10
	b=a-b;//a=15,b=5
	a=a-b;//b=5,a=10
*/
/*
	a=1010
	b= 101
*/
	a=a^b;//a=1111,b=0101	这里都是二进制数
	b=a^b;//a=1111,b=1010
	a=a^b;//b=1010,a=0101
	printf("a:%d,b:%d\n",a,b);
	return 0;
}
