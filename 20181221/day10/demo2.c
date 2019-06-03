#include<stdio.h>

void add(int* a,int* b){
	*a=*a+*b;
}

void add2(int** a,int** b){
	**a=**a+**b;
}

int main(int argc,char** argv){
	int a=5,b=10;
	int* p=&a;
	int* q=&b;
	int** P=&(p);//*P==*(&p)==&a
	int** Q=&(q);
	//add(*P,*Q);
	add2(P,Q);
	printf("%d\n",a);
	return 0;
}
