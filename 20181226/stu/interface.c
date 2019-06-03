#include"head.h"

/*
函数名：adminInterface
函数功能：管理员登录后显示的界面
函数返回值：void
*/
void adminInterface(stu_t* DB,int* len){
	int ch=0;
	while(1){
		printf("1：添加学生\n");
		printf("2：查找学生\n");
		printf("3：修改学生信息\n");
		printf("4：打印所有学生信息\n");
		printf("5：排序学生\n");
		printf("6：删除学生\n");
		printf("7：退出\n");
		printf("请选择：\n");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch){
			case 1:
				insertStu(DB,len);
				break;
			case 2:
				printStu(DB,len);
				break;
			case 3:
				updateStu(DB,len);
				break;
			case 4:
				printAllStu(DB,len);
				break;
			case 5:
				stuSort(DB,len);
				rankSort(DB,len);
				printAllStu(DB,len);
				break;
			case 6:
				removeStu(DB,len);
				break;
			case 7:
				return ;
		}
	}
}

/*
函数名：stuInterface
函数功能：学生登录成功后显示的界面
函数返回值：void
*/
void stuInterface(stu_t st,stu_t* DB,int* len){
	int ch=0;
	while(1){
		printf("1：查看成绩\n");
		printf("2：查看排名\n");
		printf("3：修改成绩\n");
		printf("4：返回\n");
		printf("请选择:");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch){
			case 1:
				seachScore(DB,st,len);
				break;
			case 2:
				seachRank(DB,st,len);
				break;
			case 3:
				updateScore(DB,st,len);
				stuSort(DB,len);
				rankSort(DB,len);
				break;
			case 4:
				return ;
		}
	}
}




























