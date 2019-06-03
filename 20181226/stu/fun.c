#include"head.h"


/*
函数名称：insertStu
函数功能：管理员添加学生
函数返回值：将数组内有多少学生返回到外部
*/
int insertStu(stu_t* DB,int* len){
	static int id=180701;
	printf("请输入学生的姓名:");
	scanf("%s",DB[id-180701].name);
	while(getchar()!='\n');
	DB[id-180701].id=id;
	DB[id-180701].score=rand()%60+40;
	id++;
	(*len)++;
	return *len;
}

/*
函数名：findStu
函数功能：管理员通过输入id号找到对应的学生
函数返回值：将找到的学生所在数组中的下标位置返回给外部
*/
int findStu(stu_t* DB,int* len){
	int id=0;
	char name[50];
	int i=0;
	printf("请输入学生ID:");
	scanf("%d",&id);
	while(getchar()!='\n');
	for(i=0;i<*len;i++){
		if(DB[i].id==id){
			return i;
		}
	}
	printf("该学生不存在\n");
	return -1;
}

/*
函数名:updateStu
函数功能：通过调用查找函数，找到需要修改的学生的确切位置，然后使用该位置，直接找到该学
	生并修改信息
函数返回值：当找到学生并修改成功，返回1，反之则返回-1
*/

int updateStu(stu_t* DB,int* len){
	int pos=findStu(DB,len);
	if(pos==-1){
		return -1;
	}
	printf("请输入该学生的分数:");
	scanf("%d",&DB[pos].score);
	while(getchar()!='\n');
	return 1;
}

/*
函数名：printAllStu
函数功能：将结构体数组内所有代表学生个体的结构体打印出来
函数返回值：void
*/
void printAllStu(stu_t* DB,int* len){
	int i=0;
	for(i=0;i<*len;i++){
		printf("************\n");
		printf("姓名:%s\n学号:%d\n分数:%d\n",DB[i].name,DB[i].id,DB[i].score);
	}
}

/*
函数名：stuSort
函数功能：将学生结构体数组内所有学生结构体按照特定要求进行排序
函数返回值:void
*/
void stuSort(stu_t* DB,int* len){
	int i=0,j=0;
	stu_t temp;
	for(i=0;i<*len;i++){
		for(j=0;j<*len-1;j++){
			if(DB[j].score < DB[j+1].score){
				temp=DB[j];
				DB[j]=DB[j+1];
				DB[j+1]=temp;
			}
		}
	}
}

/*
函数名：removeStu
函数功能：删除学生
函数返回值：将学生结构体数组更新后的长度返回到外部
*/
int removeStu(stu_t* DB,int* len){
	int pos=findStu(DB,len);
	if(pos==-1){return -1;}
	int i=0;//循环变量
	for(i=pos;i<*len-1;i++){
		DB[i]=DB[i+1];
	}
	stu_t newStu={0,0,0};
	DB[i]=newStu;
	(*len)--;
	return *len;
}
/*
函数名：adminLogin
函数功能：管理员登录用
返回值：void
*/
void adminLogin(){
	char name[50]="admin123";
	char pswd[50]="123456";
	char _name[50];
	char _pswd[50];
	int flag=0;
	while(1){
		printf("请输入账号:");
		scanf("%s",_name);
		while(getchar()!='\n');
		printf("请输入密码:");
		scanf("%s",_pswd);
		while(getchar()!='\n');
		if(strcmp(name,_name)==0 && strcmp(pswd,_pswd)==0){
			flag=1;
		}
		if(flag==1){
			break;
		}
		printf("账号或密码错误\n");
	}
}

/*
函数名：printStu
函数功能：打印单个学生信息
返回值：void
*/
void printStu(stu_t* DB,int* len){
	int pos=findStu(DB,len);
	printf("********************");
	printf("姓名:%s\n学号:%d\n分数:%d\n",DB[pos].name,DB[pos].id,DB[pos].score);
}

/*
函数名：rankSort
函数功能：依照学生成绩排序后给学生排名定位
函数返回值：void
*/
void rankSort(stu_t* DB,int* len){
	int i=0;
	for(i=0;i<*len;i++){
		DB[i].rank=i+1;
	}
}

/*
函数名：stuLogin
函数功能：学生登录时使用
函数返回值：学生登录成功后，确切的将学生本身返回给外部 stu_t
*/
stu_t stuLogin(stu_t* DB,int* len){
	char _name[50];
	int _pswd=0;
	int i=0;
	stu_t newStu={0,0,0,0};
	while(1){
		printf("请输入账号:");
		scanf("%s",_name);
		while(getchar()!='\n');
		printf("请输入密码:");
		scanf("%d",&_pswd);
		while(getchar()!='\n');
		for(i=0;i<*len;i++){
			if(strcmp(DB[i].name,_name)==0 && DB[i].id==_pswd){
				return DB[i];
			}
		}
		printf("账号不存在或账号或密码错误\n");
		return newStu;
	}
}

/*
函数名：seachScore
函数功能：查看学生的成绩
函数返回值：void
*/
void seachScore(stu_t* DB,stu_t st,int* len){
	int i=0;
	for(i=0;i<*len;i++){
		if(DB[i].id==st.id){
			printf("成绩：%d\n",DB[i].score);
		}
	}
	
}

/*
函数名：seachRank
函数功能：查看学生的排名
函数返回值：void
*/
void seachRank(stu_t* DB,stu_t st,int* len){
	int i=0;
	for(i=0;i<*len;i++){
		if(DB[i].id==st.id){
			printf("成绩：%d\n",DB[i].rank);
		}
	}
}

/*
函数名：updateScore
函数功能：修改成绩
函数返回值：void
*/
void updateScore(stu_t* DB,stu_t st,int* len){
	printf("请输入新的成绩:");
	scanf("%d",&st.score);
	while(getchar()!='\n');
	int i=0;
	for(i=0;i<*len;i++){
		if(DB[i].id==st.id){
			DB[i]=st;
		}
	}
}



































