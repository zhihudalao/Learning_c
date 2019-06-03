#include<stdio.h>

int func(int n){//n
	if(n<=1){
		return 1;
	}
	return (func(n-1)+1)*2;
}

int feibo(int n){
	if(n<=2){
		return 1;
	}
	return feibo(n-1)+feibo(n-2);
}

int main(int argc,char** argv){
	printf("请输入斐波那契数列的第n位:");
	int n=0;
	scanf("%d",&n);
	int res=feibo(n);
	printf("%d\n",res);
	return 0;
}
/*
	1 1 2 3 5 8 13 21
	f(n)=f(n-1)+f(n-2);
	f(5)=f(4)+f(3)==5
	f(4)=f(3)+f(2)==3		f(3)=f(2)+f(1)==2
	f(3)=f(2)+f(1)==2
f(1)和f(2)为最底层解，都为1
*/
