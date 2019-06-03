#include<stdio.h>

void add(int a,int b){
	printf("%p\n",a);
	a=a+b;
}

int main(int argc,char** argv){
	int a=5,b=10;
	printf("%p\n",&a);
	add(a,b);
	printf("%d\n",a);
	return 0;
}
