#include<stdio.h>
int main(int argc,char** argv){
/*
	1)键盘输入一个数字，判断他是不是质数
	2)求1~100之内所有质数的和

*/
	int x=0;
	int i=0;
	int flag=0;//0是质数，1不是质数
	int n=0;
	int res=0;
	scanf("%d",&n);
	for(x=2;x<=n;x++){
		flag=0;
		for(i=2;i<x;i++){
			if(x%i==0){
				flag=1;
			}
		}
		if(flag==0){
			res=res+x;
		}
	}
	printf("1~%d之间质数和为:%d\n",n,res);
	return 0;
}










