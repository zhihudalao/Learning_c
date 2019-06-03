#include<stdio.h>


int main(void){
	int a[3][4]={1,1,1,1,1,1,1,1,1,1,1,1};
	int res=*(a+2)-(a[0]+2);
	printf("%d\n",res);
	return 0;
}
