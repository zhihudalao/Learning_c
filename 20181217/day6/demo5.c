#include<stdio.h>

int func(int n){//1234
	if(n/10==0){
		return n;
	}
	return func(n/10)+n%10;
}

int main(int argc,char** argv){
	int n=0;
	scanf("%d",&n);
	int res=func(n);
	printf("%d\n",res);
	return 0;
}
