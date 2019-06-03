#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "view.h"
#include "lotLink.h"
#include "userLink.h"
#include "controller.h"
#include "Lottrey_func.h"
#include "LotRecord.h"

/*
	功能:彩票界面的管理
	参数：head 头节点
	返回值：无
*/
void Lottrey_control(User* headUser,Lot* headLot,LotRec* headRec)
{
	int choice = 0;
	int flag=0;
	system("clear");
	while(1){
		menu();
		scanf("%d", &choice);
		while(getchar()!='\n');
		switch(choice){
			case 1:
				adminLogin();//管理员登陆
				admin_control(headUser,headLot,headRec);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				printf("\n加密保存成功\n");
				sleep(2);
				break;
			case 2:
				flag=userLogin(headUser);//用户登陆
				if(flag==1){
					printf("登陆失败\n");
					printf("按Enter返回");
					while(getchar()!='\n');
					break;
				}
				user_control(headUser,headLot,headRec,flag);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				printf("\n加密保存成功\n");
				sleep(2);
				break;
			case 3:
				insterUser(headUser);//注册
				printf("按Enter返回");
				while(getchar()!='\n');
				break;
			case 4:
				adminLogin();//管理员登陆
				menu_greffier();
				judge_control(headUser,headLot,headRec);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				fputc('.',stderr);sleep(1);
				printf("\n加密保存成功\n");
				sleep(2);
				break;
			case 0:
				return ;
			default:
			printf("输入错误\n");
			printf("按Enter返回");
			while(getchar()!='\n');
				break;
		}
	}
}
/*
	功能:管理员界面的管理
	参数：head 头节点
	返回值：无
*/
void admin_control(User* headUser,Lot* headLot,LotRec* headRec){
	int choice;
	int id=0;
	  system("clear");
		menu_admin();
	while(1){
		printf("请输入你的选择: ");
		scanf("%d",&choice);
		while(getchar()!='\n');
		switch (choice) {
			case 1:
							insertLot(headLot);//添加

							break;
			case 2:
							printf("请输入用户id：   ");
							scanf("%d",&id);
							findUser(headUser,id);//查询
							break;
			case 3:
							linkSort(headUser);
							display_link(headUser);//排序
							break;
			case 4:
							payAccount(headUser);
							break;
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
/*
	功能:用户界面的管理
	参数：head 头节点
	返回值：无
*/
void user_control(User* headUser,Lot* headLot,LotRec* headRec,int id){
	int choice;
	  system("clear");
		menu_user_();
	while(1){
		printf("请输入你的选择: ");
		scanf("%d",&choice);
		while(getchar()!='\n');
		User*p=find_link(headUser,id);

		switch (choice) {
			case 1:
							findUser(headUser,id);
							//查看个人信息
							break;
			case 2:
							if(altPswd(headUser,id)){return;}
							else{break;}//修改密码
							break;
			case 3:
							//下注
							buy_ticket(headLot,headRec,p);
							break;
			case 4:
							//注销
							if(cancell_user(p)){
								printf("注销成功\n");
								return;}
							break;
			case 5:
							//采购记录
							hist_recored(headRec,id);

							printf("\n按Enter返回");
							while(getchar()!='\n');
							break;
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
/*
	功能:公证员界面的管理
	参数：head 头节点
	返回值：无
*/
void judge_control(User* headUser,Lot* headLot,LotRec* headRec){
	int choice;
	 system("clear");
	 menu_greffier();
	while(1){
			printf("\n请输入你的选择: ");
			scanf("%d",&choice);
			while(getchar()!='\n');
			switch (choice) {
			case 1://开奖
							run_lottery(headUser,headLot,headRec);
							winner(headUser,headLot,headRec);
							break;
			case 2://查看所有发行的彩票信息
							displayLotlink( headLot);
							break;
			case 3://查看所有购买的彩票信息彩票
							displayReclink(headRec);
							break;


			case 0:
							return;
			default:
							printf("输入错误,请重新输入\n");
							break;
		}
	}
}
