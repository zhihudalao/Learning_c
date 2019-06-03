#include<stdio.h>

int func(int n){
  if(n<=1){
    return 1;
  }else{return (n+func(n-1));}
}
int main(int argc,char**argv){
  int n;
  printf("please input n:\n");
  scanf("%d",&n);
  printf("Result:%d\n",func(n));
  return 0;
}
