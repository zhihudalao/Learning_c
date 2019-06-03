#include<stdio.h>


int main(int argc,char** argv){
/*
	从键盘输入两个数字，求他们的最大公约数和最小公倍数
*/
/*/
//最小公倍数
	int i=0,j=0;//输入的两个数
	int big=0;//最小公倍数
	printf("请输入要计算最小公倍数的两个数:");
	scanf("%d %d",&i,&j);
	big=(i>j)?i:j;
	for(big=big;big%i!=0 || big%j!=0;big++){}
	printf("%d和%d的最小公倍数是:%d\n",i,j,big);
*/
//最大公约数

	int i=0,j=0;//输入的两个数
	int small=0;//最大公约数
	printf("请输入要计算最大公约数的两个数:");
	scanf("%d %d",&i,&j);
	small=(i<j)?i:j;
	for(small=small;i%small!=0 || j%small!=0;small--){}
	printf("%d和%d的最大公约数是:%d\n",i,j,small);

	return 0;
}
