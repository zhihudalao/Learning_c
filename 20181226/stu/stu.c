#include"head.h"


int main(int argc,char** argv){
	stu_t DB[512]={0};
	int len=0;
	int ch=0;
	stu_t st;
	srand(time(0));
	while(1){
		printf("1:管理员登录\n");
		printf("2:学生登录\n");
		printf("3:退出\n");
		printf("输入需要执行的操作\n");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch){
			case 1:
				adminLogin();
				adminInterface(DB,&len);
				break;
			case 2:	
				st=stuLogin(DB,&len);
				if(st.id!=0){
					stuInterface(st,DB,&len);
				}
				break;
			case 3:
				return 0;
		}

		
		
	}
	return 0;
}
