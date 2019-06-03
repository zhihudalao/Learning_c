#include "view.h"
#include <stdio.h>
#include<stdlib.h>
/*
系统菜单
*/
void menu(void)
{
  system("clear");
  printf("\n\n\t\t******************************************\t\n");
	printf("\t\t******************************************\t\n");
	printf("\t\t\t\033[01;31m欢\033[32m迎\033[33m使\033[34m用\033[35m海");
	printf("\033[36m同\033[37m科\033[31m技\033[35m彩\033[32m票\033\[36m管");
	printf("\033[33m理\033[34m系\033[32m统\033[0m\t\n");
	printf("\t\t******************************************\t\n");
  printf("\t\t**\t\t\033[01;31m");
	printf("选择身份登陆\033[0m\t\t**\n");
  printf("\t\t**\t\t\033[01;35m1.");
	printf("管理员登录\033[0m\t\t**\n");
  printf("\t\t**\t\t\033[01;32m2.");
	printf("用户登录\033[0m\t\t**\n");
  printf("\t\t**\t\t\033[01;34m3.");
	printf("用户注册\033[0m\t\t**\n");
  printf("\t\t**\t\t\033[01;36m4.");
	printf("公正员登录\033[0m\t\t**\n");
  printf("\t\t**\t\t\033[01;33m0.");
	printf("退出系统\033[0m\t\t**\n");
  printf("\t\t******************************************\t\n");
	printf("\t\t******************************************\t\n");
	printf("请选择\033[0m\n");
}
/*
管理员菜单
*/
void menu_admin(void){

  printf("************************\n");
  printf("1、添加彩票（期号，单价，中奖情况，号码，售出总数，总额）\n");
  printf("2、查询（根据彩民账号）\n");
  printf("3、排序（根据彩民账号）\n");
  printf("4、账户充值\n");
  printf("0、保存退出\n");

}
/*
用户登陆界面
*/
void menu_user_(void){

  printf("************************\n");
  printf("1、查看个人信息\n");
  printf("2、修改密码\n");
  printf("3、购买彩票下注\n");
  printf("4、注销\n");
  printf("5、查看历史记录（已购买的彩票及其中奖情况）\n");
  printf("0、退出\n");

}
/*
公证员界面
*/
void menu_greffier(void){

  printf("************************\n");
  printf("1、开奖\n");
  printf("2、查看所有发行的彩票信息\n");
  printf("3、查看所有购买的彩票信息\n");

  printf("0、退出\n");

}
