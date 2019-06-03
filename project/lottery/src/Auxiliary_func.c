#include <termios.h>
#include<stdio.h>
#include <unistd.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "lotLink.h"
#include "userLink.h"
#include "LotRecord.h"
#include "Lottrey_func.h"
int getch(void){
        struct termios tm, tm_old;
        int fd = STDIN_FILENO, c; //fd终端参数设置到标准输入中
        if(tcgetattr(fd, &tm) < 0) //获得标准输入的终端参数，将获得的信息保存到tm中
                return -1;
        tm_old = tm; //保存当前终端参数
        cfmakeraw(&tm); //设置终端工作在“raw”模式下，输入以字符方式提供，禁止回显，所有特殊字符被禁止
        if(tcsetattr(fd, TCSANOW, &tm) < 0) //TCSANOW 不等数据传输完毕就立即改变属性
                return -1;
        c = fgetc(stdin); //获取终端一个字符
        if(tcsetattr(fd, TCSANOW, &tm_old) < 0) //恢复初始终端参数
                return -1;
        return c;
}
/*密码输入*/
int shadow_pswd(char *pswd)
{
	int i= 0;
	char ch;
	do
	{
		ch = getch();//接受一个字符
		if(ch!='\n'&&ch!='\r'&&ch!=127)//不是回车不是删除
		{
			pswd[i] = ch;
			i++;
			if(i>=16)//限定字符长度
			{
				return 1;
			}
			printf("*");
		}
		else if((ch!='\n'||ch!='\r')&&ch == 127)//删除键
		{
			if(i>0)
			{
				i--;
				printf("\b \b");//删除的效果
			}
		}
	}while(ch!='\n'&&ch!='\r');

		pswd[i] = '\0';
		return 0;

}
/*用户名输入*/
int name_input(char *name)
{
	int i= 0;
	char ch;
	int name_err = 0;
	do
	{
		ch = getch();//接受字符
		if(ch!='\n'&&ch!='\r'&&ch!=127)//非回车换行删除键
		{
			name[i] = ch;
			printf("%c",ch);//打印显示出
			i++;
			if(i>16)
			{
				printf("\n请输入16个字符以内的用户名\n");
				printf("用户名:");
				i = 0;
				if((name_err++)>=2)
				{
					return 1;
				}
			}

		}
		else if((ch!='\n'||ch!='\r')&&ch == 127)//删除
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
	}while(ch!='\n'&&ch!='\r');
	name[i] = '\0';
	return 0;
}

void now_time(char *NowTime)//获取时间
{
	time_t t;
	time(&t);
	strcpy(NowTime,ctime(&t));
}
/*验证码*/
int ver_code()
{

	//设置随机种子
	srand(time(NULL));
	int i = 0,flag = 0;//定义一个循环变量i,标志位 flag
	char array1[5] = "";//保存生存的验证码
	char array2[5] = "";//保存用户键入的
	//生成 随机的 种子
	array1[0] = 65+random()%26;//大写字母
	array1[1] = 97+random()%26;//小写字母
	array1[2] = 48+random()%10;//数字
	while(1)
	{
		array1[3] = 48+random()%10;//不同的数字
		if(array1[2] == array1[3])
			continue;
		else
			break;
	}
	printf("\n验证码:%s\n",array1);

	printf("请输入验证码:\n");
	while((array2[i]=getchar())!='\n')//判断长度
	{
		i++;
		if(i>=5)
		{
			return 1;;
		}
	}

	for(i = 0;i<4;i++)//验证码验证
	{
		if(array1[i]!=array2[i])
		{
			flag = 1;
			break;
		}
	}

	//判断标志位情况
	if(flag == 0)
	{
		return 0;
	}else{
		return 1;//错误返回1
	}
}





/*本期所有购买的彩票*/
void winner(User*user_head,Lot*lty_head,LotRec*blty_head)
{
	blty_head = blty_head->next;


	while(blty_head != NULL)
	{
		if(blty_head->data.tkt_code == lty_head->data.name)//期号相同
		{
			is_win(user_head,lty_head,blty_head);//判断这张彩票上的号是否中奖
		}
		blty_head = blty_head->next;
	}
}
/*判断彩票是否中奖*/
void is_win(User*user_head,Lot*lty_head,LotRec*blty_head)
{
	int i = 0,j = 0, n = 0;
	int luky_num[20] = {};
	int num = blty_head->data.buy_num;
	for(i=0;i<3;i++)
	{
		luky_num[i] = lty_head->data.lotNum[i];//幸运号
	}
	for(i=0;i<num;i++)//注数
	{
		n = 0;
		for(j=0;j<3;j++)//彩票上的每一注3个号码
		{
 			if(blty_head->data.own_ticket[i][j] == luky_num[j])
			{n++;}
		}
		if(n >= 3)			//中奖
		{
			lty_head->data.money -= BONUS*(blty_head->data.multiple); //奖池更新
			blty_head->data.is_win = 1;//中奖状态
			blty_head->data.win_amount += BONUS*(blty_head->data.multiple);//中奖金额

			send_prize(user_head,lty_head,blty_head);//派发奖金

		}else{printf("很抱歉，没中奖\n");}

	}

}
/*派发奖金*/
void send_prize(User*user_head,Lot*lty_head,LotRec*blty_head)//派发奖金
{
	user_head = user_head->next;
	while(user_head != NULL){
		if((user_head->data.id)==(blty_head->data.userId)){
			user_head->data.account += BONUS*(blty_head->data.multiple);//奖金加到用户余额
			return;
		}
		user_head = user_head->next;
	}
	if(user_head == NULL)//如果用户已注销，奖金派发失败，奖金返还奖池
	{
	printf("用户%d已注销无法派奖,奖金将返还奖池",blty_head->data.userId);
	lty_head->data.money += BONUS*(blty_head->data.multiple);//奖金返还到奖池
	}
}
