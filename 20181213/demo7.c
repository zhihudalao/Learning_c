#include<stdio.h>
//下楼梯
int main(int argc,char**argv){
  int a=1,b=1,sum=0,i=0,n=0;
  printf("请输入楼梯数\n");
  scanf("%d",&n);
  for(i=1;i<n;i++){
    sum=a+b;
    a=b;
    b=sum ;
  }
  if(n==1||n==2){
    sum=1;
  }
  printf("有%d下楼方式\n",sum);
  return 0;
}
