#include<stdio.h>

double func(double n){
  if(n<=1){
    return 1;
  }else{return (func(n-1)+1/n);}
}
int main(int argc,char**argv){
  double n;
  printf("please input n:\n");
  scanf("%lf",&n);
  printf("Result:%g\n",func(n));
  return 0;
}
