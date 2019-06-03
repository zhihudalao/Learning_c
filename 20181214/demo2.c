#include<stdio.h>
#include<math.h>
/*封装函数，实现一个简易计算器功能，要求能够+ - * / % 平方和开根号
并且能够直接按q退出
平方符号用数字+‘^’+指数 来表示，开根号符号用'$'+数字来表示
求指数的函数为pow(),开根号函数为sqrt()函数*/
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
    return 1000000;
  }
  return a/b;
}
int mo(int a,int b){
  return a%b;
}
double po(double a,double b){
  return pow(a,b);
}
double sq(double a){
  return sqrt(a);
}
int main(int argc,char**argv){
  double a,b;
  char ch;
  double res;
  while(1){
  printf("please input\n");
  scanf("%lf",&a);
  scanf("%c",&ch);
  if(a==0){
    if(ch=='q'){return 0;
    }
  }

  res=0;
  if(ch=='$'){
    res=sq(a);
    printf("%g%c=%g\n",a,ch,res );
  }else {
    scanf("%lf",&b);
  switch (ch) {
    case '+':res=add(a,b);
      break;
    case '-':res=sub(a,b);
      break;
    case '*':res=mul(a,b);
      break;
    case '/':res=div(a,b);
      break;
    case '%':res=mo(a,b);
      break;
    case '^':res=po(a,b);
      break;
    default:
      printf("error\n");
      return 0;
  }
  printf("%g%c%g=%g\n",a,ch,b,res );
}
}
  return 0;
}
