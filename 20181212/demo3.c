#include<stdio.h>


	/*使用switch case语句，编写一个简易的+ - * /计算器，要求计算器功能写在一个无限循环当中（while（1）），当输入计算公式的时候，显示计算结果，当输入q时候，退出程序*/
int main(int argc,char** argv){
int a,b,c;
char choice='\0';
while(1){
a=0;
printf("请输入计算公式\n");
scanf("%d",&a);
scanf("%c",&choice);
if(choice=='q'){return 0;}
scanf("%d",&b);
if (choice=='q'){
	break;
	}
	switch(choice){
		case '+':
			c=a+b;
			break;
		case '-':
			c=a-b;
			break;
		case '*':
			c=a*b;
			break;
		case '/':
			c=a/b;
			break;
		case 'q':
			break;
		default :
			break;
	}
	printf("%d%c%d=%d\n",a,choice,b,c);
	
}
return 0;	
}
