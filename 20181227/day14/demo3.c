#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student{
	char name[50];
	int id;
	struct Student st;
}stu_t;

int main(int argc,char** argv){
	/*stu_t* DB=(stu_t*)malloc(sizeof(stu_t)*2);
	memset(DB,0,sizeof(stu_t)*2);*/
	stu_t* DB=(stu_t*)calloc(1,sizeof(stu_t));
	DB=(stu_t*)realloc(DB,3*sizeof(stu_t));
	//printf("%lu\n",sizeof(DB));
/*
早上写的动态内存分配的实例，使用realloc去实现
*/
	int x=1,y=1;
	int res=!x||(--y);
	printf("%d\n",res);
	return 0;
}
