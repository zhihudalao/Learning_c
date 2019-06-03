#include<stdio.h>

int main(int argc,char** argv){
	int a=10;
	//printf("&a at:	%p\n",&a);
	int* p=&a;
	/*printf("p at:	%p\n",p);
	printf("&p at:	%p\n",&p);*/

	int** p1=&p;
	printf("p1 at:	%p\n",p1);
	printf("&p at:	%p\n",&p);
/*
练习：通过对p1的操作，将a变成20，并打印
*/
	**p1 *= 2;
	printf("%d\n",a);
	return 0;
}
