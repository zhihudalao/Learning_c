#include<stdio.h>
#include<string.h>
/*typedef,define*/

typedef struct Student{
	char name[50];
	int age;
}Stu_t;

typedef struct Teacher{
	char name[50];
	int slr;
}Tea_t;

typedef struct Person{
	Stu_t stu;
	Tea_t Tea;
}Per;

typedef struct Stu{
	int a[25];//96+8=104+8=112+96+8=216s
	double b;
	int c[25];
}Stu;

typedef int aaa;//将int类型取一个叫做aaa的别名
int main(int argc,char** argv){
	Stu_t* st1;
	Stu_t* st2;
	st1=st2;
	Tea_t* tea;
	tea=(Tea_t*)st1;//虽然编译通过了，但是由于内部结构是不同的，在数据复制过程中，会发生错误，所以杜绝这样的操作出现。
	/*Stu_t student;
	strcpy(student.name,"zhangsan");
	student.age=20;
	printf("姓名:%s\n年龄:%d\n",student.name,student.age);*/
	/*Per per;
	strcpy(per.stu.name,"zhangsan");
	per.stu.age=20;
	printf("姓名:%s\n年龄:%d\n",per.stu.name,per.stu.age);*/
	return 0;
}
