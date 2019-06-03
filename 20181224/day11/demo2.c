#include<stdio.h>

int add(int a,int b){return a+b;}

int mul(int a,int b){return a*b;}

int pos(int a,int b){return a-b;}

int div(int a,int b){return a/b;}

int lis(int a,int b){return a%b;}

int factory(int(*p)(int,int),int a,int b){
	int res=p(a,b);
	return res;
}

int main(int argc,char** argv){
	int a=0,b=0;
	char ch=0;
	int res=0;
	while(1){
		printf("请输入计算式:");
		scanf("%d%c%d",&a,&ch,&b);
		while(getchar()!='\n');
		switch(ch){
			case '+':
				res=factory(add,a,b);
				break;
			case '-':
				res=factory(pos,a,b);
				break;
			case '*':
				res=factory(mul,a,b);
				break;
			case '/':
				res=factory(div,a,b);
				break;
			case '%':
				res=factory(lis,a,b);
				break;			
		}
		printf("%d%c%d=%d\n",a,ch,b,res);
	}

//提问：回调函数和递归函数的却别在哪？
/*
	①回调函数是在函数内部调用其他函数，而递归函数则是自己调用自己
	②由于第一个特点的原因，导致：回调函数并不会产生大量的栈空间占用，而递归的空间复杂度非常的高
	③回调函数不存在任何的循环形式，所以不需要设置退出条件
*/
	return 0;

}
