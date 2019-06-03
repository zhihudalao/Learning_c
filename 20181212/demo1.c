#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int argc,char** argv){
 	/*char a,b,c;
 	scanf("%c %c %c",&a,&b,&c);
 	char charin=getchar();	
 	char max=(a>b)?a:b;
	char max2=(max>c)?max:c;
	printf("biggest=%c\n",max2 );*/
	//双色球彩票系统
	/*int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	time_t t;
	srand((unsigned)time(&t));
	int a1=rand()%50;
	int b1=rand()%50;
	int c1=rand()%50;
	int d1=rand()%50;
	printf("%d %d %d %d\n",a1,b1,c1,d1);
	if(a==a1&&b==b1&&c==c1&&d==d1){
		printf("头等奖\n");
	}else if(a==a1&&b==b1&&c==c1){
		printf("二等奖\n");
	}else if(a==a1||b==b1||c==c1||d==d1){
		printf("三等奖\n");
	}else{
		printf("没中奖\n");}*/
	/*课堂练习2：
	现在假定系统内已经存在了一组账号密码（都为int数据）
	要求，编写一套登录功能，先匹配账号是否正确，账号正确后，再匹配密码是否正确，如果密码输入错误超过2次，则要求输入4位验证码（验证码随机生成），直到密码及验证码都正确后，提示登录成功。*/
	int admin,password;
	int flag=1;
	srand(time(0));	
	int a=rand()%50;
	int b=rand()%50;
	int c=rand()%50;
	int d=rand()%50;
	int _a,_b,_c,_d;
	printf("请输入帐号\n");
	scanf("%d",&admin);
	printf("请输入密码\n");
	scanf("%d",&password);
	if(admin==120&&password==110){
	printf("密码正确登陆成功\n");
	}else{
	for(int i=1;i<2;i++)
	{
		if(password==110){
		printf("密码正确登陆成功\n");break;
		}else{
		printf("请重新输入密码\n");
		scanf("%d",&password);
			}
		}
	printf("密码输错次数过多，请输入验证码\n");
	printf("%d %d %d %d\n",a,b,c,d);
	for(int j=1;j<4;j++)
		{
		scanf("%d %d %d %d",&_a,&_b,&_c,&_d);
		if(a==_a&&b==_b&&c==_c&&d==_d){
		printf("验证码正确，请重新输入密码\n");
		printf("请重新输入密码\n");
		scanf("%d",&password);	
			if(password==110){
				printf("密码正确登陆成功\n");break;				
			}else{
				printf("密码错误，重新输入");
				}
		}else{}
	}
}
	return 0;
}
