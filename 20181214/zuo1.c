#include<stdio.h>
/*编写一个函数用于将一个整数前后倒置，并调用此函数将一个从键盘输入的整数前后倒置*/
int func(int num){
  int Dnum=0,n=0;
  while(num>0){
    n=num%10;
    num=(num-n)/10;
    Dnum=Dnum*10+n;
  }
  return Dnum;
}

int main(int argc,char**argv){
  int numb=0,res=0;
  printf("please input one num\n");
  scanf("%d",&numb);
  res=func(numb);
  printf("res=%d\n",res);
  return 0;
}
