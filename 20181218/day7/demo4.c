#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
int ifName(int* nameDB,int name){
	int i=0;
	for(i=0;i<512;i++){
		if(name==nameDB[i]){
			return i;
		}
	}
	return -1;
}

int regist(int* nameDB,int* pswdDB){
	static int pos=0;
	int name=0;
	int pswd=0;
	printf("请输入账号:");
	scanf("%d",&name);
	while(getchar()!='\n');
	int res=ifName(nameDB,name);
	if(res!=-1){
		printf("账号已存在\n");
		return -1;
	}else{
		nameDB[pos]=name;
	}
	printf("请输入密码:");
	scanf("%d",&pswd);
	while(getchar()!='\n');
	pswdDB[pos]=pswd;
	pos++;
	return 1;
}

int ifPswd(int* pswdDB,int pswd,int pos){
	if(pswd==pswdDB[pos]){
		return 1;
	}
	return -1;
}

void login(int* nameDB,int* pswdDB){
	int name=0,pswd=0;
	printf("请输入账号:");
	scanf("%d",&name);
	while(getchar()!='\n');
	int res=ifName(nameDB,name);
	if(res==-1){
		printf("账号不存在\n");
		return ;
	}
	printf("请输入密码:");
	scanf("%d",&pswd);
	while(getchar()!='\n');
	int res2=ifPswd(pswdDB,pswd,res);
	if(res2==1){
		printf("登录成功\n");
	}else{
		printf("密码错误,请重新登录\n");
	}
}

int main(int argc,char** argv){
/*
	程序内有int型数组，分别叫nameDB和pswdDB，他们分别用来保存账号和密码信息。
	现在要求，编写一个注册登录功能，注册时，输入账号密码，保存到2个DB中去。注意需要有防重复注册功能。
	登录要求验证账号存在，密码正确即可
*/
	int choice=0;
	int nameDB[512]={0};
	int pswdDB[512]={0};
	while(1){
		
		printf("1:注册\n");
		printf("2:登录\n");
		printf("3:退出\n");
		printf("请选择要执行的操作:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				regist(nameDB,pswdDB);
				break;
			case 2:
				login(nameDB,pswdDB);
				break;
			case 3:
				return 0;
			default:
				break;
		}
		for(int i=1;i<3;i++){
			printf("%d...",i);
			fflush(stdout);
			sleep(1);
		}
		printf("\n");
		system("clear");
	}
	return 0;
}
