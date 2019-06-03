#include"head.h"
/*
使用链表，编写一个学生管理系统，要求完成如下功能：
	①管理员能够对学生进行增、删、改、打印单个信息、排、打印全部信息、释放
	②学生节点拥有属性：
		1）姓名
		2）唯一自增学号
		3）密码（由管理员统一初始化）
		4）语数外成绩
	③管理员账号密码可以固定在系统内部
	④学生可以使用自己的学号当做账号，输入密码登录
	⑤学生登录后可以查看自己的3科成绩，并且查看每一科成绩排名以及总成绩排名
	⑥学生可以修改密码。要求输入旧密码2次，并且正确
	⑦要求程序开始时，从文件IO中加载所有信息，程序退出前，将链表中的所有信息保存到文件IO中
*/
int main(int argc,char** argv){
	stu_t*head=(stu_t*)malloc(sizeof(stu_t));
  memset(head,0,sizeof(stu_t));
	head->data.id=180700;
	loadStu(head);
	int ch=0;
	while(1){
		printf("************************\n");
		printf("1:管理员登录\n");
		printf("2:学生登录\n");
		printf("3:退出\n");
		printf("输入需要执行的操作\n");
		printf("************************\n");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch){
			case 1:
				adminLogin();
				adminInterface(head);
				break;
			case 2:
				stuInterface(head);
				break;
			case 3:
				saveStu(head);
				freeStu(head);
				return 0;
		}
	}
	return 0;
}
