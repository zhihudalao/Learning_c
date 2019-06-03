#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include"buy_ticket.h"
#include"issue_lottery.h"
#include"user.h"

int flag ;//标记位打印红色背景
int input();
#define RED printf("\033[41m")
#define END printf("\033[0m")
#define UP 0
#define DOWN 1

void user_regist(ulink*);//注册

/*********************用户的操作********************/
void user_login(ulink*,lty_lk*,blty_lk*);//用户登录
void buy_ticket(ulink*,lty_lk*,blty_lk*);//购买彩票
int change_pswd(ulink*);//修改密码
void hist_recored(ulink*,blty_lk*);//购买历史记录
int cancell_user(ulink*);//注销
void num_statistic(lty_lk*);//统计

/********************管理员********************/
void admin_login(ulink*,lty_lk*);//管理员登录
void admin_menu_print();//管理员登录菜单打印
void qry_user_inf(ulink*);//查询用户信息
int issue_ticket(lty_lk*);//发行彩票
void admin_man_sort(ulink*);//排序
void sort_money(ulink*);//根据余额排序
void sort_name(ulink*);//根据用户名排序
void recharge(ulink*);//为彩民充值

void status(lty_lk*pre);//开奖状态
void the_lucky_num(lty_lk*pre);//中奖号码
void the_sum_of_lty(lty_lk*pre);//售出总数
void the_sum_money(lty_lk*pre);//奖池
/**************************公正员*************************/
void notary_login(ulink*,lty_lk*,blty_lk*);//公正员登录
void notary_menu_print();//公正员登录菜单打印
void run_lottery(ulink*,lty_lk*,blty_lk*);//开奖


/****************************注册登录菜单***************************/
void menu(ulink*user_head,lty_lk*lty_head,blty_lk*blty_head)
{
	while(1)
	{
		while(1)
		{
			system("clear");
			menu_print();
			int res = input();
			if(res == 0)
			{
				if(flag !=0)
					flag--;
				system("clear");
				menu_print();
			}else if(res == 1)
			{
				if(flag != 4)
					flag++;
				system("clear");
				menu_print();
			}else if(res == 2)
			{
				break;
			}
		}
		switch(flag)
		{
			case 0://用户注册
     				user_regist(user_head);
				break;
			case 1://用户登录
     				user_login(user_head,lty_head,blty_head);
				user_save(user_head);
				blty_save(blty_head);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				printf("加密保存成功\n");
				sleep(2);
				break;
			case 2://管理员登录
				admin_login(user_head,lty_head);

				break;
			case 3://公正员登录
				notary_login(user_head,lty_head,blty_head);
				user_save(user_head);
				lty_save(lty_head);
				blty_save(blty_head);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				printf("加密保存成功\n");
				sleep(2);
				break;
			case 4://退出
				return ;
			default:
				printf("输入错误,请重新输入\n");
				sleep(2);
				break;
		}
	}
}


/********************注册登录界面的按键判断*******************/
int input()
{
	char ch = getch();
	switch(ch)
	{
		case 27:
			ch = getch();
			if(ch == 91)
			{
 				ch = getch();
				if(ch== 65)
				{
					return UP;
				}else if(ch == 66)
				{
					return DOWN;
				}
			}
			break;
		case '1':
				flag = 0;
				break;
		case '2':
				flag = 1;
				break;
		case '3':
				flag = 2;
				break;
		case '4':
				flag = 3;
				break;
		case '0':
				flag = 4;
				break;
		case '\r':
				return 2;
				break;
	}
	return -1;
}

/****************************注册登录界面打印**********************/
void menu_print()
{
	printf("\n\n\t\t******************************************\t\n");
	printf("\t\t******************************************\t\n");
	printf("\t\t\t\033[01;31m欢\033[32m迎\033[33m使\033[34m用\033[35m海");
	printf("\033[36m同\033[37m科\033[31m技\033[35m彩\033[32m票\033\[36m管");
	printf("\033[33m理\033[34m系\033[32m统 v1.0\033[0m\t\n");
	printf("\t\t\t\t\tAuthor: 陆从杭\n");
	printf("\t\t******************************************\t\n");
	if(flag == 0)
	{
		printf("\t\t**\t\t\033[01;34m1.");
		RED;
		printf("用户注册\033[0m\t\t**\n");
		END;
	}else
	{
		printf("\t\t**\t\t\033[01;34m1.");
		printf("用户注册\033[0m\t\t**\n");
	}
	if(flag == 1)
	{
		printf("\t\t**\t\t\033[01;32m2.");
		RED;
		printf("用户登录\033[0m\t\t**\n");
		END;
	}else
	{
		printf("\t\t**\t\t\033[01;32m2.");
		printf("用户登录\033[0m\t\t**\n");
	}
	if(flag == 2)
	{
		printf("\t\t**\t\t\033[01;35m3.");
		RED;
		printf("管理员登录\033[0m\t\t**\n");
		END;
	}else
	{
		printf("\t\t**\t\t\033[01;35m3.");
		printf("管理员登录\033[0m\t\t**\n");
	}
	if(flag == 3)
	{
		printf("\t\t**\t\t\033[01;36m4.");
		RED;
		printf("公正员登录\033[0m\t\t**\n");
		END;
	}else
	{
		printf("\t\t**\t\t\033[01;36m4.");
		printf("公正员登录\033[0m\t\t**\n");
	}
	if(flag == 4)
	{
		printf("\t\t**\t\t\033[01;33m0.");
		RED;
		printf("退出系统\033[0m\t\t**\n");
		END;
	}else
	{
		printf("\t\t**\t\t\033[01;33m0.");
		printf("退出系统\033[0m\t\t**\n");
	}
	printf("\t\t******************************************\t\n");
	printf("\t\t******************************************\t\n");
	printf("\033[01;31;47m\t\t请选择\033[0m\n");
}





/*********************************用户登录界面***********************/
//传入当前登录用户前一个节点
void user_menu(ulink *pre,lty_lk*lty_head,blty_lk*blty_head)
{
	ulink*personal = pre->next;
	while(1)
	{
		int choose = -1;
	system("clear");
	printf("\t\t******************************************\n");
	printf("\t\t******************************************\n");
	printf("\t\t**\t\t\033[01;31m1.查看个人信息\033[0m\t\t**\n");
	printf("\t\t**\t\t\033[01;33m2.修改密码\033[0m\t\t**\n");
	printf("\t\t**\t\t\033[01;35m3.购买彩票\033[0m\t\t**\n");
	printf("\t\t**\t\t\033[01;36m4.查看购彩记录\033[0m\t\t**\n");
	printf("\t\t**\t\t\033[01;36m5.往期开奖号码统计\033[0m\t**\n");
	printf("\t\t**\t\t\033[01;32m6.注销账户\033[0m\t\t**\n");
	printf("\t\t**\t\t\033[01;34m0.返回主菜单\033[0m\t\t**\n");
	printf("\t\t******************************************\n");
	printf("\t\t******************************************\n");
	printf("请选择\n");
		scanf("%d",&choose);
		while(getchar()!='\n');
		switch(choose)
		{
			case 1://打印个人信息
 				printf("用户名:%s\t余额:%.2f\t",personal->data.name,personal->data.money);//用户名，余额
				printf("注册时间:%s",personal->data.regist_time);
				printf("\n按Enter返回");
				while(getchar()!='\n');
				break;
			case 2://修改密码
   				if(change_pswd(personal))
				{return;}else{break;}
			case 3://购买彩票.下注
 				buy_ticket(personal,lty_head,blty_head);
				break;
			case 4://购彩记录
				hist_recored(personal,blty_head);
				printf("按ENTER返回");
				while(getchar()!='\n');
				break;
			case 5://往期彩票统计
				num_statistic(lty_head);
				printf("按ENTER返回");
				while(getchar()!='\n');
				break;
			case 6://注销
    				if(cancell_user(pre))
					{return;}else
					{break;}
			case 0:

				return;
			default:
   				printf("输入错误,请重新输入\n");
				printf("按Enter返回");
				while(getchar()!='\n');

				break;
		}
	}

}



/****************************管理员菜单**************************/
void admin_menu_print()
{
	printf("\n\t\t******************************************\t\n");
	printf("\t\t******************************************\t\n");
	printf("\t\t**\t\t\033[01;31m管\033[32m理\033[33m员\033[36m菜\033[34m单\033[0m\t\t**\n");
	printf("\t\t******************************************\t\n");
	printf("\t\t**\t\t\033[01;34m1.发行彩票\033[0m\t\t**\n");
	printf("\t\t**\t\t\033[01;33m2.查询彩民信息\033[0m\t\t**\n");
	printf("\t\t**\t\t\033[01;36m3.按功能排序\033[0m\t\t**\n");
	printf("\t\t**\t\t\033[01;34m4.为彩民充值\033[0m\t\t**\n");
	printf("\t\t**\t\t\033[01;32m5.保存\033[0m\t\t\t**\n");
	printf("\t\t**\t\t\033[01;31m0.返回主菜单\033[0m\t\t**\n");
	printf("\t\t******************************************\t\n");
	printf("\t\t******************************************\t\n");
}


void admin_menu(ulink*user_head,lty_lk*lty_head)
{
	int choose = -1;

	while(1)
	{
		system("clear");
		choose = -1;
		admin_menu_print();
		printf("\033[01;31;43m\t\t请选择\033[0m\n");
		scanf("%d",&choose);
		//while(getchar()!='\n');
		switch(choose)
		{
			case 1://发行彩票
         			issue_menu(lty_head);
				break;
			case 2://查询用户信息
  				qry_user_inf(user_head);
				break;
			case 3://排序
  				admin_man_sort(user_head);
				while(getchar()!='\n');
				break;
			case 4://为彩民充值
	 			recharge(user_head);
				break;
			case 5://保存
				lty_save(lty_head);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				printf("加密保存成功\n");
				getchar();
				while(getchar()!='\n');
				break;
			case 0:

				return;
			default:
      				printf("输入错误,请重新输入\n");
				getchar();
				while(getchar()!='\n');
				break;
		}
	}
}
/*****************************彩票发行界面*************************/
void issue_menu(lty_lk*lty_head)
{
	lty_lk*pre = lty_head;
	if(lty_head == NULL)
	{
		printf("彩票发行头节点为空\n");
		exit(1);
	}
	while(pre->lty_next!=NULL)//最新一期
	{
		pre = pre->lty_next;

	}
	int choose = -1;
	while(choose != 0)
	{
		system("clear");
		choose = -1;
		printf("\n\t\t******************************************\n");
		printf("\t\t******************************************\n");
		printf("\t\t**\t\t\033[01;32m亲\033[31m爱\033[35m的\033[37m管\033[31m理\033[33m员\033[0m\t\t**\n");
		printf("\t\t**\t\t\033[01;37m欢\033[35m迎\033[32m发\033[34m行\033[36m彩\033[35m票\033[0m\t\t**\n");
		printf("\t\t******************************************\n");
		printf("\t\t**\033[01;34m\t1 ————————————  发行彩票\033[0m\t**\n");
		printf("\t\t**\033[01;36m\t2 ————————————  开奖状态\033[0m\t**\n");
		printf("\t\t**\033[01;31m\t3 ————————————  中奖号码\033[0m\t**\n");
		printf("\t\t**\033[01;32m\t4 ————————————  本期售出总数\033[0m\t**\n");
		printf("\t\t**\033[01;33m\t5 ————————————  本期奖池总额\033[0m\t**\n");
		printf("\t\t**\033[01;35m\t0 ————————————  返回\033[0m\t\t**\n");
		printf("\t\t******************************************\n");
		printf("\t\t******************************************\n");
		printf("请选择：\n");
		scanf("%d",&choose);
		while(getchar()!='\n');
		switch (choose)
		{
			case 1://发行彩票
				if(issue_ticket(lty_head))
				pre = pre->lty_next;//发行完成后将pre指向最新发行的彩票链表
				break;
			case 2: //开奖状态
				status(pre);
				break;
			case 3: //中奖号码
				the_lucky_num(pre);
				break;
			case 4: //售出总额
				the_sum_of_lty(pre);
				break;
			case 5: //奖池
				the_sum_money(pre);
				break;
			case 0:
				break;
			default:
				printf("输入错误！\n");
				while(getchar()!='\n');
				break;
		}
	}
	return ;

}

/*****************************按功能排序******************************/
void admin_man_sort(ulink*user_head)
{

	int choose = -1;
	while(choose != 0)
	{
		choose = -1;
		system("clear");
		printf("\n\n\t\t1.根据用户余额排序\n");
		printf("\t\t2.根据用户名排序\n");
		printf("\t\t0.退出\n");
		printf("\t\t请选择:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1://用户余额排序
				sort_money(user_head);
				print_user(user_head);//打印用户信息
				while(getchar()!='\n');
				while(getchar()!='\n');
				break;
			case 2://用户名排序
				sort_name(user_head);
				print_user(user_head);//打印用户信息
				while(getchar()!='\n');
				while(getchar()!='\n');
				break;
			case 0:
				return;
			default:
				printf("输入错误");
				while(getchar()!='\n');
				while(getchar()!='\n');
				break;
		}
	}


}


/*******************************公正员登录menu************************/
void notary_menu_print()
{
	printf("\n\t\t******************************************\t\n");
	printf("\t\t******************************************\t\n");
	printf("\t\t\t\t\033[01;31m公正员菜单\033[0m\t\n");
	printf("\t\t******************************************\t\n");
	printf("\t\t**\t\t\033[01;32m1.开奖\033[0m\t\t\t**\n");
	printf("\t\t**\t\t\033[01;33m2.查看所有期彩票信息\033[0m\t**\n");
	printf("\t\t**\t\t\033[01;35m3.查询所有彩票购买信息\033[0m\t**\n");
	printf("\t\t**\t\t\033[01;34m0.返回\033[0m\t\t\t**\n");
	printf("\t\t******************************************\t\n");
	printf("\t\t******************************************\t\n");

}



/*****************************公正员******************/
void notary_menu(ulink*user_head,lty_lk*lty_head,blty_lk*blty_head)
{
	int choose = -1;

	while(1)
	{
		system("clear");
		choose = -1;
		notary_menu_print();
		printf("\t\t\033[01;31m请选择\033[0m\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1://开奖
 				run_lottery(user_head,lty_head,blty_head);
				break;
			case 2://查看所有发行的彩票
				print_lty(lty_head);
				getchar();
				while(getchar()!='\n');
				break;
			case 3://查看所有购买彩票信息
				print_blty(blty_head);
				getchar();
				while(getchar()!='\n');
				break;
			case 0:
				return;
			default:
      				printf("输入错误,请重新输入\n");
				getchar();
				while(getchar()!='\n');
				break;
		}
	}
}
