#include"head.h"

/*
函数名：adminInterface
函数功能：管理员登录后显示的界面
函数返回值：void
*/
void adminInterface(stu_t*head){
	int ch=0;
	while(1){
		printf("************************\n");
		printf("1：添加学生\n");
		printf("2：查找学生\n");
		printf("3：修改学生信息\n");
		printf("4：打印所有学生信息\n");
		printf("5：排序学生\n");
		printf("6：删除学生\n");
		printf("7：退出\n");
		printf("请选择：\n");
		printf("************************\n");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch){
			case 1:
				insertStu(head);
				break;
			case 2:
				printStu(head);
				break;
			case 3:
				updataStu(head);
				break;
			case 4:
				printAll(head);
				break;
			case 5:
				stuSort(head);
				printAll(head);
				break;
			case 6:
				removeStu(head);
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
void stuInterface(stu_t* head){
	int id=0;
	id=stuLogin(head);
	int ch=0;
	while(1){
		printf("1：查看成绩\n");
		printf("2：查看排名\n");
		printf("3：修改密码\n");
		printf("4：返回\n");
		printf("请选择:");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch){
			case 1:
				seachScore(head,id);
				break;
			case 2:
				seachRank(head,id);
				break;
			case 3:
				updatepswd(head,id);
				/*stuSort(DB,len);
				rankSort(DB,len);*/
				break;
			case 4:
				return ;
		}
	}
}
