#include<stdio.h>

int main(int argc,char** argv){
	int n=0;//求第n为的斐波那契值
	scanf("%d",&n);
	int res=0;
	int a=1,b=1;
	int mid=0;//中间变量用来保存b的旧值
	//1 1 2 3 5 8 13 21
	//a b n       
	//  a b n
	//    a b n		
	for(int pos=3;pos<=n;pos++){
		res=a+b;
		mid=b;
		b=a+b;
		a=mid;
	}
	if(n==1 || n==2){res=1;}
	printf("斐波那契数列第%d个数字是:%d\n",n,res);
	return 0;
}
