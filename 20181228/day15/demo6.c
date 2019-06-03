#include<stdio.h>

typedef struct Student{
	char name[50];
	int id;
}stu_t;

int main(int argc,char** argv){
	stu_t DB[512]={0};
	stu_t st1={"zhangsan",1};
	stu_t st2={"lisi",2};
	DB[0]=st1;
	DB[1]=st2;
	FILE* fp=fopen("./DB.txt","wb+");
	for(int i=0;i<2;i++){
		fwrite(DB+i,sizeof(stu_t),1,fp);
	}
	fclose(fp);

	return 0;
}
