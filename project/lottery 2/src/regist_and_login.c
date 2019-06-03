#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<termio.h>
#include"user.h"
#include"issue_lottery.h"
#include"buy_ticket.h"


void user_menu(ulink *,lty_lk*,blty_lk*);//用户登录界面
void admin_menu(ulink*,lty_lk*);//管理员界面
void notary_menu(ulink*,lty_lk*,blty_lk*);//公正员菜单

/***********************注册******************************/

void user_regist(ulink*user_head)
{
	if(user_head == NULL)
	{
		printf("头节点为空\n");
		exit(1);
		return;
	}
	user data;
 	char confirm_pswd[20];
	int name_err1 = 0;
	int name_err2 = 0;
	int pswd_err = 0;
	int pswd_err2 = 0;
	printf("请输入用户名和密码(16个字符以内)\n");

	while(1)/******************注册用户名**************/
		{
			printf("用户名:");
			name_err2 = name_input(data.name);//在辅助函数文件.c中 错误返回1
			if(name_err2)
			{
   				printf("用户名输入错误超过三次，将退出注册\n");
				sleep(2);
				return;
			}
			if(data.name[0] == '\0')
 			{
  	  			printf("\n用户名输入错误，请重新输入\n");
				if((name_err1++) >= 2)
				{
  	 				printf("用户名输入错误超过三次，将退出注册\n");
					sleep(2);
					return;
				}
			}
			else{
				break;
			}
		}
	ulink *pre = select_user(user_head,data.name);//查重
	if(pre!=NULL)
	{
		printf("\n\033[01;31m用户名已存在\033[0m\n");
		printf("按Enter返回");
		while(getchar()!='\n');
		return;
	}

	while(1)/******************注册密码********************/
	{
		printf("\n密码:");
		pswd_err2 = shadow_pswd(data.pswd);//输入错误返回1
		if(data.pswd[0] == '\0'||pswd_err2 == 1)//没有输入任何字符，错误标识
		{
			printf("\n密码输入错误,请重新输入\n");
			if((pswd_err++)>=2)
			{
 				printf("密码输入错误超过三次，将退出注册\n");
				sleep(2);
				return;
			}
		}else{break;}
	}
	printf("\n确认密码:");//确认密码
	pswd_err2 = shadow_pswd(confirm_pswd);//输入错误返回1
	if(pswd_err2)
	{
		fputs("\n输入错误",stderr);
		sleep(2);
		return;
	}
	if(strcmp(data.pswd,confirm_pswd)!=0)
	{
		printf("\n两次输入密码不同\n");
		printf("按Enter返回");
		while(getchar()!='\n');
		return;

	}
		now_time(data.regist_time);
		data.money = 10;//初始注册给予用户10元初始值
		insert_after_user(user_head,data);
		printf("\n注册成功\n");
		printf("按Enter返回");
		while(getchar()!='\n');

}

/****************************用户登录*************************/
void user_login(ulink*user_head,lty_lk*lty_head,blty_lk*blty_head)
{
	user data;
	int pswd_err = 0;
	int pswd_err2 = 0;
	int ver_err = 0;
	ulink*pre;
	int i = 0;
	if(user_head == NULL)
	{
		printf("用户头节点为空\n");
		return;
	}

	while(1)
	{
		while(1)//输入验证码
		{
			i = 0;
			system("clear");
			menu_print();
			printf("请输入用户名与密码(16个字符以内)\n");
			printf("用户名:");
			while((data.name[i]=getchar())!='\n')//判断长度
			{
				i++;

				if(i>=16)
				{
				fputs("\n输入错误！,请重新输入!",stderr);
				sleep(2);
				return;
				}
			}
			data.name[i] = '\0';//密码输入最后一个\n位置变成\0
			pre = select_user(user_head,data.name);//查找用户名
			printf("密码:");
			pswd_err2 = shadow_pswd(data.pswd);//密码
			if(pswd_err2)
			{
				fputs("\n输入错误",stderr);
				sleep(2);
				return;
			}
			if(ver_code())//验证码
			{
				fputs("验证码输入错误\n",stderr);
				fputs("按Enter返回",stderr);
				while(getchar()!='\n');
				//sleep(2);
				if((ver_err++)>5)
				{printf("验证码输入错误超过5次，退出登录\n");sleep(2);return;}

			}else
			{
				break;

			}
		}
		if((pre == NULL)||(strcmp(data.pswd,pre->next->data.pswd)!=0))//无用户名密码不匹配
		{
			printf("用户名不存在或密码错误\n");
			printf("按Enter返回");
			if((pswd_err++)>=2)
			{
				printf("输入错误超过三次,将退出登录\n");
				sleep(2);
				return;
			}else{while(getchar()!='\n');}

		}else
		{
				break;
		}
	}
		printf("登录成功\n");
		printf("按Enter进入");
		while(getchar()!='\n');
		user_menu(pre,lty_head,blty_head);
}
/*********************************管理员登录************************/
void admin_login(ulink*user_head,lty_lk*lty_head)
{
	char admin_name[20] = "admin";//管理员固定帐号密码
	char admin_pswd[20] = "123456";
	char name[20];
	char pswd[20];
	int admin_err = 0;
	int i = 0;
	while(1)
	{	i = 0;
		system("clear");
		menu_print();
		printf("请输入管理员帐号:");
		while((name[i]=getchar())!='\n')//判断长度限定16字符长度
		{
			i++;
			if(i>=16)
			{
				fputs("\n输入错误！,请重新输入!",stderr);
				sleep(2);
				return;
			}
		}
		name[i] = '\0';
		printf("\n请输入密码:");
		if(shadow_pswd(pswd))//隐藏密码错误返回1
		{
			fputs("\n输入错误",stderr);
			sleep(2);
			return;
		}
		if(strcmp(name,admin_name) == 0 && strcmp(pswd,admin_pswd) == 0)
		{
			printf("\n登录成功\n\033[01;31;47m欢迎进入管理员菜单\033[0m\n");
			sleep(2);
			admin_menu(user_head,lty_head);
			return;
		}else
		{

			admin_err++;
			if(admin_err>=5)
			{
  				fputs("\n输入错误次数超过5次",stderr);
				sleep(2);
				return;
			}
			printf("\n用户名或密码错误,请重新登录\n");
			while(getchar()!='\n');
		}
	}
}
/****************************公正员登录*********************/
void notary_login(ulink*user_head,lty_lk*lty_head,blty_lk*blty_head)
{
	char admin_name[20] = "notary";//公正员帐号密码固定
	char admin_pswd[20] = "123456";
	char name[20];
	char pswd[20];
	int admin_err = 0;
	int i = 0;
	while(1)
	{
		system("clear");
		menu_print();
		printf("请输入用户名:");
		while((name[i]=getchar())!='\n')//判断长度
		{
			i++;
			if(i>=16)
			{
				fputs("输入错误！,请重新输入!",stderr);
				sleep(2);
				return;
			}
		}
		name[i] = '\0';
		printf("\n请输入密码:");
		if(shadow_pswd(pswd))//隐藏密码
		{
			fputs("\n输入错误",stderr);
			sleep(2);
			return;
		}
		if(strcmp(name,admin_name) == 0 && strcmp(pswd,admin_pswd) == 0)
		{
			printf("\n登录成功\n\033[01;31;47m欢迎进入公正员菜单\033[0m\n");
			sleep(2);
			notary_menu(user_head,lty_head,blty_head);//验证成功进入公正员菜单
			return;
		}else
		{
			printf("用户名或密码错误,请重新登录\n");
			sleep(2);
			admin_err++;
			if(admin_err>=4)
			{
  				printf("输入错误次数超过5次");
				sleep(2);
				return;
			}
		}
	}




}
