#include<stdio.h>
/*回调函数写计算器*/
int a=0,b=0;
int add(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}
int mul(int a,int b){return a*b;}
int div(int a,int b){return a/b;}
int func(int (*p)(int,int)){
  int res=p(a,b);
  return res;
}
int main(int argc,char**argv){
  printf("*************choice***********\n");
  int c=0;
  char ch=0;
    scanf("%d",&a);
    scanf("%c",&ch);
    scanf("%d",&b);
    while(getchar()!='\n');
    switch (ch) {
      case '+':c=func(add);
      break;
      case '-':c=func(sub);
      break;
      case '*':c=func(mul);
      break;
      case '/':c=func(div);
      break;
      default:
      break;
    }
    printf("**********%d%c%d=%d***********\n",a,ch,b,c);
  return 0;
}
