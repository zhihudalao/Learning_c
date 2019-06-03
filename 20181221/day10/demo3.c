#include<stdio.h>

int main(int argc,char** argv){
	char a=0;
	char* p=&a;
	char** P=&p;
	char** Q=P+1;
	printf("p at	:%p\n",P);
	printf("q at	:%p\n",Q);
	return 0;
}
