#include<stdio.h>

void add(int a,int b){
	a=a+b;
	printf("%p\n",&a);
	return ;
}

int main(int argc,char** argv){
	int a=5,b=10;
	add(a,b);
	printf("%d\n",a);//形参不能传递给实参
	return 0;
}
