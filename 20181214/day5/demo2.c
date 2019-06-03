#include<stdio.h>

/*
	封装函数，实现功能，传入一个数，判断其是否是一个质数，并在主函数中打印判断结果
*/

char func(int x){
	int i=0;//循环变量
	for(i=2;i<x;i++){
		if(x%i==0){
			return 'n';
		}
	}
	return 'y';
}

int main(int argc,char** argv){
	printf("请输入要判断的数字:");
	int x=0;
	scanf("%d",&x);
	char ch=func(x);
	if(ch=='n'){
		printf("他不是一个质数\n");
	}else{
		printf("他是一个质数\n");
	}
	return 0;
}

