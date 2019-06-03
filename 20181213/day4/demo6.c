#include<stdio.h>

int main(int argc,char** argv){
/*
	编写一个程序，使用循环的方式，来测定char类型数据的取值范围
*/
	char a=0;
	char b=a+1;
	int count=0;//计数器
	for(;a<b;a++,b++){
		count++;
	}
	printf("char的最大取值范围为:%d\n",count);
	return 0;
}
