#include<stdio.h>

typedef struct Student{
	char name[50];
	int id;
}stu_t;

int main(int argc,char** argv){
	FILE* fp=fopen("./DB.txt","r");
	char str[512]={0};
	char* p;
	while(1){
		p=fgets(str,sizeof(stu_t),fp);
		if(p==NULL){
			printf("%p\n",p);
			break;
		}
		printf("%s\n",p);
		//printf("%s",str);
	}
	
	fclose(fp);
	return 0;
}
/*
练习题，使用fgets和fputs实现shell指令的cp功能
*/










