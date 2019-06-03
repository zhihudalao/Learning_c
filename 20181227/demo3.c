#include<stdio.h>
#include<stdlib.h>
/*使用堆内存分配一个5个元素的一维数组(malloc)，从键盘输入5个元素进行初始化，实现冒泡排序并输出，数组的初始化、排序、输出都要求分函数写*/
void in(int *p,int n);
void sort(int *p,int n);
void out(int *p,int n);
int main()
{
	int *p=(int*)malloc(5*sizeof(int));
	printf("请输入5个整数\n");
	in(p,5);
	printf("原数组是  ：");
	out(p,5);
	sort(p,5);
	printf("冒泡排序后：");
	out(p,5);
	return 0;
}
void out(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d  ",*(p+i));
	}
	printf("\n---------------------\n");
}
void in(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",(p+i));
	}
}
void sort(int *p,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(*(p+j)>*(p+j+1))
			{
				int tem=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=tem;
			}
		}
	}
}
