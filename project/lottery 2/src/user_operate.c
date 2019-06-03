#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"user.h"
#include"buy_ticket.h"
#include"issue_lottery.h"
void print_own_lty(blty_lk*,int);//打印记录

/********************************更改密码************************/
int change_pswd(ulink*pre)
{
	char old_pswd[20] = "";
	char new_pswd[20] = "";
	char confirm_pswd[20] = "";

	printf("请输入旧密码\n");
	shadow_pswd(old_pswd);//输入旧密码
	if(strcmp(pre->data.pswd,old_pswd)!=0)
	{
		printf("旧密码不正确\n");
		printf("按Enter返回");
		while(getchar()!='\n');
		return 0;
	}
	else{
		printf("\n密码输入正确\n");
		printf("请输入新密码:");
		shadow_pswd(new_pswd);
		if(new_pswd[0] == '\0')
		{
			printf("\n密码输入错误\n");

			return 0;
		}
		printf("\n确认密码:");
		shadow_pswd(confirm_pswd);
		if(strcmp(new_pswd,confirm_pswd)!=0)
		{
			printf("\n两次输入密码不同\n");
			printf("按Enter返回");
			while(getchar()!='\n');
			return 0;
		}else
		{
			strcpy(pre->data.pswd,new_pswd);//密码修改成功再修改链表中的密码值
			printf("\n密码修改成功,请重新登录\n");
			sleep(2);
			return 1;

		}

	}

}
/*************************购彩记录*********************/
void hist_recored(ulink*personal,blty_lk*blty_head)
{
	int n = 0;//记录条数
	if(blty_head == NULL)
	{
		printf("购彩链表头节点为空\n");
		exit(1);
	}
	blty_head = blty_head->blty_next;
	while(blty_head != NULL)
	{
		if(strcmp(blty_head->blty_data.user_name,personal->data.name)==0)
		{
			n++;
			print_own_lty(blty_head,n);//打印记录
		}
		blty_head = blty_head->blty_next;
	}
	if(n == 0)
	{
		printf("您没有购彩记录\n");
	}
}
/********************************打印购买记录********************/
void print_own_lty(blty_lk*pre,int n)
{
	int i = 0,j = 0;
	printf("第%d条记录\n",n);
	printf("\t发行期号:%d 彩票ID:%s 购买时间:%s",pre->blty_data.tkt_code,
			pre->blty_data.tkt_ID,pre->blty_data.buy_time);

	printf("\t购彩号码:\n");
	for(i=0;i<(pre->blty_data.buy_num);i++)
	{
		printf("\t第%d注\t",i+1);
		for(j=0;j<3;j++)
		{
			printf("%d ",pre->blty_data.own_ticket[i][j]);
		}
		printf("\n");
	}
	if(pre->blty_data.is_win)
		{
			printf("\t中奖状态: 已中奖\t中奖金额: %d\n",pre->blty_data.win_amount);
		}else
		{
			printf("\t中奖状态: 未中奖\t中奖金额: %d\n",pre->blty_data.win_amount);
		}
		printf("—————————————————————————————————————————————————————————————————————————\n");
}




/************************注销用户************************/
int cancell_user(ulink*pre)
{
	char pswd_temp[20] = "";
	char ch = 0;
	printf("想好要离开我了吗?\n");
	printf("按 Y 确认注销\n其他键取消\n");
	ch = getchar();
	if(ch == 'Y'||ch == 'y')
	{
		printf("请输入密码:");//注销时提示输入密码
		scanf("%s",pswd_temp);
		if(strcmp(pre->next->data.pswd,pswd_temp) == 0)
		{
			pre->next = pre->next->next;
			free(pre->next);
			printf("\033[01;31m您的账户已注销成功,欢迎下次再次光临\033[0m\n");
			sleep(2);
			return 1;//注销成功返回1

		}else
		{
			printf("输入密码错误");
			getchar();
			while(getchar()!='\n');
			return 0;//注销失败返回0
		}
	}else{return 0;}


}
