#include<stdio.h>
#include<math.h>
double add(double a,double b){
	return a+b;
}

double sub(double a,double b){
	return a-b;
}

double mul(double a,double b){
	return a*b;
}

double div(double a,double b){
	if(b==0){
		return 10000000;
	}
	return a/b;
}

double lest(double a,double b){
	return (int)a%(int)b;
}

double myPow(double a,double b){
	return pow(a,b);
}

double mySqrt(double a){
	return sqrt(a);
}

int main(int argc,char** argv){
	double a=0,b=0;
	char ch=0;
	double res=0;
	while(1){
		a=9876543210;
		printf("请输入要计算的公式:");
		scanf("%lf",&a);
		scanf("%c",&ch);
		if(a==9876543210){
			if(ch=='q'){return 0;}
		}
		scanf("%lf",&b);
		while(getchar()!='\n');
		if(ch=='$'){
			res=mySqrt(b);
			printf("%c%g=%g\n",ch,b,res);
		}else{
			switch(ch){
				case '+':
					res=add(a,b);
					break;
				case '-':
					res=sub(a,b);
					break;
				case '*':
					res=mul(a,b);
					break;
				case '/':
					res=div(a,b);
					break;
				case '%':
					res=lest(a,b);
					break;
				case '^':
					res=myPow(a,b);
					break;
				default:
					printf("计算公式错误\n");
					break;
			}
		printf("%g%c%g=%g\n",a,ch,b,res);
		}
		
	}
	return 0;
}
/*
	封装函数，实现一个简易计算器功能，要求能够+ - * / % 平方和开根号
	并且能够直接按q退出
	平方符号用数字+‘^’+指数 来表示，开根号符号用'$'+数字来表示
	求指数的函数为pow(),开根号函数为sqrt()函数
*/
