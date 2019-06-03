#include<stdio.h>

int func(int n){
  if(n<1){
    return 0;
  }else{return (n%10+func(n/10));
  }
}
int main(int argc,char**argv){
  int n;
  printf("please input n:\n");
  scanf("%d",&n);
  printf("Result:%d\n",func(n));
  return 0;
}
