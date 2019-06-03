#include<stdio.h>

int add(int a,int b){
	return a+b;
}//自定义的加法函数

int main(int argc,char** argv){
	int a=4;
	char b=0;
	void* p=&a;
	//p=&b;
	printf("%d\n",*((int*)p));
	/*int arr_1[5]={0,1,2,3,4};
	int arr_2[5]={5,6,7,8,9};
	int* arr[2]={arr_1,arr_2};
	int** p=arr;*/
	/*int i=0;
	for(i=0;i<5;i++){
		printf("%d\n",*(arr+i));
	}*/
	//printf("%d\n",*(*(p+1)+1));
	//咱们把arr称为指针数组，而把p称为数组指针

	/*int arr2[2][5]={
			{0,1,2,3,4},	
			{5,6,7,8,9}
		};//正儿八经的二维数组
	int(* q)[5]=arr2;*/
/*
使用两种方式，通过q来访问arr2中的7，必须都是指针的方式
*/
	/*printf("%d\n",*(*(q+1)+2));
	printf("%d\n",*(*q+7));
	printf("%d\n",q[1][2]);*/
	return 0;
}
/*
①：使用memcpy函数，实现字符串的拼接
②：封装代码：实现strcat的内部实现
*/











