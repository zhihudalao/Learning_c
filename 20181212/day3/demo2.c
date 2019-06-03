#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int argc,char** argv){
	srand(time(0));
	int name=1234;
	int password=4321;
	int _name=0;
	int _password=0;
	printf("请输入账号:");
	scanf("%d",&_name);
	while(getchar()!='\n');
	if(name==_name){
		printf("请输入密码:");
		scanf("%d",&_password);
		while(getchar()!='\n');
		if(password==_password){
			printf("登录成功\n");
		}else{
			printf("密码错误，请重新输入密码:");
			scanf("%d",&_password);
			int security=rand()%9000+1000;
			int _security=0;
			if(password==_password){
				printf("请输入验证码\n");
				printf("验证码:%d\n",security);
				scanf("%d",&_security);
				while(getchar()!='\n');
				if(security==_security){
					printf("登录成功\n");
				}else{
					printf("验证码错误，程序退出\n");
				}
			}else{
				printf("密码错误，程序退出\n");
			}
		}
	}else{
		printf("账号不存在，程序退出\n");
	}
	return 0;
}
