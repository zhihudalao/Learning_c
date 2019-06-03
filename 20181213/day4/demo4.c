#include<stdio.h>


int main(int argc,char** argv){
/*
	键盘输入一个整型数，长度不限，将其逆序输出。
	例如键盘输入123456789，输出987654321
*/
/*
	x=12345
	第一次循环res=0*10+5=5
	第二次循环res=5*10+4=54
	第三次循环res=54*10+3=543
	第四次循环res=543*10+2=5432
	第五次循环res=5432*10+1=54321
*/
	long long a=0;//用来接受输入的值
	long long res=0;//这是一个累加池
	scanf("%lld",&a);//12345
	for(;a!=0;a/=10){
		res=res*10+a%10;
	}
	printf("%lld\n",res);
	return 0;
}
