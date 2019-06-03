#include<stdio.h>

int main(int argc,char** argv){
	int a=0,b=0,res=0;
	char c='\0';
	while(1){
		a=0;
		printf("请输入要计算的公式:");
		scanf("%d",&a);
		scanf("%c",&c);
		if(a==0){
			if(c=='q'){return 0;}
		}
		scanf("%d",&b);
		switch(c){
			case '+':
				res=a+b;
				break;
			case '-':
				res=a-b;
				break;
			case '*':
				res=a*b;
				break;
			case '/':
				res=a/b;
				break;
		}
		printf("%d%c%d=%d\n",a,c,b,res);
	}
	return 0;
}
