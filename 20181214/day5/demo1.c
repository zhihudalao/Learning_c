#include<stdio.h>

/*函数的声明及定义：
	函数的返回值类型 函数名(参数列表){
		函数具体实现的算法;
	}
关于return值：
	函数调用时的表达式的值==函数定义时的return值
*/

int func(int x){
	return -x;	
}

int main(int argc,char** argv){
	int a=10;
	int res=func(a);
	printf("%d\n",res);
	return 0;
}
/*
	封装函数，实现功能，传入一个数，判断其是否是一个质数，并在主函数中打印判断结果
*/














