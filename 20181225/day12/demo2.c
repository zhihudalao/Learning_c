#include<stdio.h>

int volume = 1024;

typedef struct Stu{
	char name[20];
	char pswd[20];
	int id;
	int score;
}stu_t;
/*
练习题:完成一个注册登录功能，要求：
	①需要防重复注册功能
	②登录时，验证账号是否存在，验证密码是否正确，2次不正确输入验证码,5次不正确退出程序.
*/
/*

*/
int insertStu(stu_t* stuDB){
	static int pos=0;
	static int id=180701;
	scanf("%s",stuDB[pos].name);
	while(getchar()!='\n');
	scanf("%s",stuDB[pos].pswd);
	while(getchar()!='\n');
	scanf("%d",&stuDB[pos].score);
	while(getchar()!='\n');
	stuDB[pos].id=id;
	pos++;
	id++;
	return pos;
}

void printStu(stu_t* stuDB,int len){
	int i=0;
	for(i=0;i<len;i++){
		printf("姓名:%s\n密码:%s\n学号:%d\n分数:%d\n",stuDB[i].name,stuDB[i].pswd,stuDB[i].id,stuDB[i].score);
	}
}

int main(int argc,char** argv){
	stu_t stuDB[volume];
	int len=insertStu(stuDB);
	printStu(stuDB,len);
	return 0;
}
