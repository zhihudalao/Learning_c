#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Student{
	char name[50];
	int id;
}stu_t;

int* func(){
	int a=5;
	//int arr[5];
	int* arr=(int*)malloc(sizeof(int)*5);//这样申请的堆空间是一个连续堆空间，可以将他看做一个数组来进行操作
	arr[0]=a;
	printf("%p\n",arr);
	return arr;
}

int main(int argc,char** argv){
	int* p=func();
	printf("%p\n",p);
	free(p);
	return 0;
}
/*
	封装一个函数:
	函数功能：当传入的数组容量足够时，则完成添加功能，并且返回数组本身
		当传入的数组容量不足1/10时，则扩容至原来的两倍，并返回新的数组
	在函数外部，设计好逻辑，所有会使用到该数组的函数，都能准确的在扩容后，使用新的数组

*/
