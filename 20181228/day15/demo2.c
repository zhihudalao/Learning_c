#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student{
	char name[50];
	int id;
}stu_t;

int vol=5;

stu_t* insertStu(stu_t* DB,int* len,int* volume){
	if(*volume>=vol*0.9){
		printf("数据库扩容\n");
		vol*=2;
		//stu_t* newDB=(stu_t*)malloc(sizeof(stu_t)*vol);
		/*stu_t* newDB=(stu_t*)calloc(vol,sizeof(stu_t));
		memcpy(newDB,DB,sizeof(stu_t) * volume);
		free(DB);
		printf("请输入姓名和ID\n");
		scanf("%s%d",newDB[*len].name,&newDB[*len].id);
		return newDB;*/
		DB=(stu_t*)realloc(DB,sizeof(stu_t)*vol);
	}
	printf("请输入姓名和ID\n");
	scanf("%s%d",DB[*len].name,&DB[*len].id);
	(*volume)++;
	(*len)++;
	return DB;
}

void printStu(stu_t* DB,int len){
	int i=0;
	for(i=0;i<len;i++){
		printf("姓名:%s\n学号:%d\n",DB[i].name,DB[i].id);
	}
}

void loadStu(stu_t* DB,int* len,int* volume){
	FILE* Rfp=fopen("./DB.bin","rb");
	if(Rfp==NULL){
		return ;
	}
	int res=0;
	int i=0;
	while(1){
		if(!fread(DB+i,sizeof(stu_t),1,Rfp)){break;}
		i++;
		printf("%d\n",i);
		(*len)++;
		(*volume)++;
	}
	fclose(Rfp);
}

void saveStu(stu_t* DB,int len){
	FILE* Wfp=fopen("./DB.bin","wb");
	int i=0;
	for(i=0;i<len;i++){
		fwrite(DB+i,sizeof(stu_t),1,Wfp);
	}
	fclose(Wfp);
}

int main(int argc,char** argv){
	/*stu_t* DB=(stu_t*)malloc(sizeof(stu_t)*vol);//使用了未初始化的指针
	memset(DB,0,sizeof(stu_t)*vol);*/
	stu_t* DB=(stu_t*)calloc(vol,sizeof(stu_t));
	int volume=0;
	int len=0;
	int ch=0;
	loadStu(DB,&len,&volume);
	while(1){
		printf("1:插入学生\n");
		printf("2:打印所有学生信息\n");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch){
			case 1:
				DB=insertStu(DB,&len,&volume);
				break;
			case 2:
				printStu(DB,len);
				break;
			case 0:
				saveStu(DB,len);
				free(DB);
				return 0;
		}
		
	}
	
	return 0;
}
