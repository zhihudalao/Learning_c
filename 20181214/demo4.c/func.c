#include"head.h"
int ifName(){
	int name=0;
	printf("请输入账号:");
	scanf("%d",&name);
	if(name==NAME){
		return 1;
	}else{
		return -1;
	}
}
int ifSecurity(){
	int secNo=rand()%9000+1000;
	int _secNo=0;
	printf("验证码为:%d\n请输入验证码:",secNo);
	scanf("%d",&_secNo);
	if(secNo==_secNo){
		return 1;
	}else{return -1;}
}
int ifPswd(int times){
	int pswd=0;
	int res=0;
	printf("请输入密码:");
  system("stty -echo");
	scanf("%d",&pswd);
  system("stty echo");
  printf("\n");
	if(times>=2 && times<=5){
		res=ifSecurity();
		if(res==-1){
			return 0;
		}
	}
	if(pswd==PSWD){
		return 1;
	}else{
		return -1;
	}
}

int login(){
	int times=0;
	int res=0;
	while(1){
		res=ifName();
		if(res==1){
			break;
		}
	}
	while(1){
		if(times>=5){
			return -1;
		}
		res=ifPswd(times);
		if(res==1){
			printf("登录成功\n");
			return 1;
		}else if(res==-1){
			printf("密码错误,请重新登录\n");
			times++;
		}else{
			printf("验证码错误,请重新登录\n");
			times++;
		}
	}
}
