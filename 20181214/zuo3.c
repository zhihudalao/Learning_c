#include<stdio.h>
#include<math.h>
int func(int n){
  if(n==1||n==2){
    return 1;
  }else{
    return func(n-1)+func(n-2);
  }
}
int main(int argc,char**argv){
  int n;
  printf("please input n:\n");
  scanf("%d",&n);
  printf("Result:%d\n",func(n));
  return 0;
}
