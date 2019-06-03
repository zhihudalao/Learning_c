#include<stdio.h>

int insertStu(int* stuid,int* stuMS,int* stuCS){
	static int pos=0;
	int id=0;
	int ms=0;//手动输入的数学成绩
	int cs=0;//手动输入的语文成绩
	printf("请输入该学生的学号及语文成绩和数学成绩:");
	scanf("%d%d%d",&id,&cs,&ms);
	while(getchar()!='\n');
	stuid[pos]=id;
	stuMS[pos]=ms;
	stuCS[pos]=cs;
	pos++;//保证下次调用添加学生函数，不会把本次添加的学生信息给覆盖了
	return pos;//将当前数组中有多少个元素返回出去
}

void printALLStu(int* stuid,int* stuMS,int* stuCS,int len){
	int i=0;
	for(i=0;i<len;i++){
		printf("*********************\n");
		printf("学号:%d\n数学成绩:%d\n语文成绩:%d\n",stuid[i],stuMS[i],stuCS[i]);
	}
}

void stuSort(int* stuid,int* stuMS,int* stuCS,int len){
	int i=0,j=0;
	for(i=0;i<len;i++){
		for(j=0;j<len-1;j++){
			if((stuMS[j]+stuCS[j])<(stuMS[j+1]+stuCS[j+1])){
				stuid[j]=stuid[j]^stuid[j+1];
				stuid[j+1]=stuid[j]^stuid[j+1];
				stuid[j]=stuid[j]^stuid[j+1];

				stuMS[j]=stuMS[j]^stuMS[j+1];
				stuMS[j+1]=stuMS[j]^stuMS[j+1];
				stuMS[j]=stuMS[j]^stuMS[j+1];

				stuCS[j]=stuCS[j]^stuCS[j+1];
				stuCS[j+1]=stuCS[j]^stuCS[j+1];
				stuCS[j]=stuCS[j]^stuCS[j+1];
			}
		}
	}
}

int findStu(int* stuid,int* stuMS,int* stuCS,int len){
	int id=0;
	int i=0;
	printf("请输入学号:");
	scanf("%d",&id);
	while(getchar()!='\n');
	for(i=0;i<len;i++){
		if(stuid[i]==id){
			return i;
		}
	}
	printf("*********************\n");
	printf("该学生不存在\n");
	return -1;
}

void printStu(int* stuid,int* stuMS,int* stuCS,int pos){
	printf("*********************\n");
	printf("学号:%d\n数学成绩:%d\n语文成绩:%d\n",stuid[pos],stuMS[pos],stuCS[pos]);
	return ;
}

int deleteStu(int* stuid,int* stuMS,int* stuCS,int len){
	int pos=findStu(stuid,stuMS,stuCS,len);
	int i=0;
	for(i=pos;i<len-1;i++){
		stuid[i]=stuid[i+1];
		stuMS[i]=stuMS[i+1];
		stuCS[i]=stuCS[i+1];
	}
	stuid[i]=0;
	stuMS[i]=0;
	stuCS[i]=0;
	len--;
	return len;
}

void updateStu(int* stuid,int* stuMS,int* stuCS,int len){
	int pos=findStu(stuid,stuMS,stuCS,len);
	int ms=0;
	int cs=0;
	printf("请输入新的数学成绩和语文成绩:");
	scanf("%d%d",&ms,&cs);
	while(getchar()!='\n');
	stuMS[pos]=ms;
	stuCS[pos]=cs;
	return ;
}

int main(int argc,char** argv){
	int stuid[512]={0};//用来保存学号
	int stuMS[512]={0};//用来保存数学成绩
	int stuCS[512]={0};//用来保存语文成绩
	int choice=0;
	int len=0;
	int pos=0;//用来保存查找函数返回的找到的学生所在数组中的下标位置
	while(1){
		printf("*********************\n");
		printf("1:添加学生\n");
		printf("2:查看所有学生信息\n");
		printf("3:排序学生\n");
		printf("4:按学号查找学生\n");
		printf("5:按学号删除学生\n");
		printf("6:按学号修改学生信息\n");
		printf(":退出\n");
		printf("请输入要执行的操作:");
		scanf("%d",&choice);
		while(getchar()!='\n');
		switch(choice){
			case 1:
				len=insertStu(stuid,stuMS,stuCS);//使用len接受当前数组中有多少个元素，然后传入print函数中去，保证遍历次数的正确
				break;
			case 2:
				printALLStu(stuid,stuMS,stuCS,len);
				break;
			case 3:
				stuSort(stuid,stuMS,stuCS,len);
				break;
			case 4:
				pos=findStu(stuid,stuMS,stuCS,len);
				if(pos!=-1){
					printStu(stuid,stuMS,stuCS,pos);
				}
				break;
			case 5:
				len=deleteStu(stuid,stuMS,stuCS,len);
				break;
			case 6:
				updateStu(stuid,stuMS,stuCS,len);
				break;
			default:
				break;
		}
	}
	return 0;
}
