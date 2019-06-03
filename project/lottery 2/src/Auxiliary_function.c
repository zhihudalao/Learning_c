#include <termios.h>
#include<stdio.h>
#include <unistd.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"user.h"
#include"issue_lottery.h"
#include"buy_ticket.h"
int getch(void)
{
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
/*********************************密码输入********************/
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
/*********************************用户名输入**************************/
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


/*****************************本地时间********************************/
void now_time(char *NowTime)//获取时间
{
	time_t t;
	time(&t);
	strcpy(NowTime,ctime(&t));
}

/****************************验证码*******************************/
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
	printf("\n验证码:\033[47;33m%s\033[0m\n",array1);

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

/**************************用户余额数据统计******************/
void data_statistic(ulink*uhead)
{
	int i = 0,j=0;
	int arr[10] = {0};//存储每个范围内用户的数量
	//int min = 0;
	int max = 0;
	if(uhead == NULL)
		{printf("没有用户数据");while(getchar()!='\n');return;}
	uhead = uhead->next;
	while(uhead!=NULL)
	{
		if(uhead->data.money<500)
		{
			arr[0]++;
		}else if(uhead->data.money>=500&&uhead->data.money<1000)
		{
			arr[1]++;
		}else if(uhead->data.money>=1000&&uhead->data.money<2000)
		{
			arr[2]++;
		}else if(uhead->data.money>=2000&&uhead->data.money<3000)
		{
			arr[3]++;
		}else if(uhead->data.money>=3000&&uhead->data.money<5000)
		{
			arr[4]++;
		}else
		{
			arr[5]++;
		}
		uhead = uhead->next;
	}
	for(i=0;i<6;i++)
	{
          //  min = (min<arr[i] ? min : arr[i]);
            max = (max>arr[i] ? max : arr[i]);
	}
	//min--;
	printf("用户余额数据统计:\n");
    	printf("^");
	printf("\n");
    for(i=max;i>=0;i--) //横坐标
        {
            char* p[6];  //指针数组，二维数组
            if(i==0)  //横坐标轴
            {
                 printf("+");
                for(j=0;j<6*6;j++)
                    printf("-");
                printf(">");
            }
            else
            {
                 if(i>0)
                {
                      for(j=0;j<6;j++)
                    {
                        if(arr[j]>=i)  //值大于当前最大值显示#
                            p[j]="####";
                        else
                            p[j]="    ";
                    }
                }
                else  //有负数时，此处用不到
                {
                    for(j=0;j<6;j++)
                    {
                        if(arr[j]>=0 || (arr[j]<0 && arr[j]>i))
                            p[j]="    ";
                        else
                            p[j]="####";
                    }
                }
                printf("|");
                for(j=0;j<6;j++)  //打印每一行
                {

                    printf("  %s",p[j]);
                }
                printf("\n");
            }
        }
        printf("\n");
  	printf("  <0.5k  0.5-1k 1-2k  2-3k  3-5k  >5k\n");//横坐标的值

}


/************************往期彩票开奖号码数据统计*******************/
void num_statistic(lty_lk*lty_head)
{
	int i = 0,j = 0,k = 0,n=0;
	int arr[50] = {0};
	int line_max = 0;
	char ch[50];
	int p[3][SCOPE] = {{0}};//共三组号码，每组号码有SCOPE个
	if(lty_head->lty_next == NULL||(lty_head->lty_next->lty_data.is_run==0))//没有发行过彩票，发行陆第一期
	{
		printf("没有彩票数据");
		while(getchar()!='\n');
		return;
	}
	lty_head = lty_head->lty_next;
	while(lty_head!=NULL)//每一期
	{
		if(lty_head->lty_data.is_run == 0)//如果最后一期没有开奖退出循环
		{break;}
		for(i=0,j=0;i<3;i++,j++)////每期的中奖号码
		{

			arr[i] = lty_head->lty_data.lucky_num[i];
			//k = arr[j];
			p[i][arr[i]]++;

		}
		lty_head = lty_head->lty_next;
	}
	for(j=0;j<3;j++)//号码出现次数最多的
	{
		for(k=0;k<SCOPE;k++)
		{line_max = ((p[j][k]>line_max)?p[j][k]:line_max);}
	}
	printf("^");
	printf("\n");
	for(i=line_max;i>=0;i--)//横坐标
	{
		if(i==0) //坐标横轴
		{
          	 	printf("+");
           	 	for(j=0;j<(SCOPE+2)*3;j++)
				printf("-");
            	printf(">");
        	}else
		{
			for(j=0;j<3;j++)//3组
			{
				for(k=0;k<SCOPE;k++)  //每组中的每个数字
           		 	{
                			if(p[j][k]>=i)  //大于当前横坐标值输出#
                   			{ch[n]='#';}
               			 	else
                   		 	{ch[n]=' ';}
					n++;
           			 }

			}


			n=0;
			printf("|");
			for(j=0,k=0;j<(SCOPE+2)*3;j++,k++)//横坐标的每一个值
			{
				if(j==SCOPE||j==(SCOPE+1)||j==(SCOPE*2+2)||j==(SCOPE*2+3)||j==(SCOPE*3+4)||j==(SCOPE*3+5))//每组之间两个空格分开
				{printf(" ");k--;}
				else
				{printf("%c",ch[k]);}
			}
			printf("\n");
		}
	}
	printf("\n");
	printf(" ");
	for(i=0;i<3;i++)//横坐标的每一个纵坐标
	{
		for(j=0;j<SCOPE;j++)
		{
			printf("%d",j);//标识当前纵坐标所示号码
		}
		printf("  ");
	}


	printf("\n");
}
