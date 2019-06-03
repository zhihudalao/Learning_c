#include<stdio.h>

typedef struct Student{
	char name[50];
	int id;
}stu_t;

int main(int argc,char** argv){
	stu_t DB[512]={0};
	FILE* fp=fopen("./DB1.txt","rb+");
	//char buf[512]={0};
	stu_t st;
	int i=0;
	while(!feof(fp)){
		fread(DB+i,sizeof(stu_t),1,fp);
		i++;
	}
	fclose(fp);
	for(int i=0;i<2;i++){
		printf("%s %d\n",DB[i].name,DB[i].id);
	}
	return 0;
}
