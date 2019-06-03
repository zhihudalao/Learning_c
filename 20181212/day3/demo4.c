#include<stdio.h>

int main(int argc,char** argv){
	int i=0;
	int a=5;
	scanf("%d",&i);
	if(i>0){
		int a=10;
		printf("%d\n",a);
	}
	printf("%d\n",a++);
	return 0;
}
