#include<stdio.h>
/*封装函数，实现功能，传入一个数，判断其是否是一个质数，并在主函数中打印判断结果*/
int func(int x){
  int i;
  for(i=2;i<x;i++){
    if(x%i==0){return 0;}
  }
  return 1;
}
int main(){
  int x;
  while(1){
  printf("please input one num\n");
  scanf("%d",&x);
  int flag=0;
  flag=func(x);
  if(flag==1){
    printf("素数\n");
  }else{
  printf("不是素数\n");}
}
  return 0;
}
