#include<stdio.h>

int fun(int a,int b){
  int i,sum=0,_a,_b;
  _a=(a<b)?a:b;
  _b=(a>b)?a:b;
  for(i=_a;i<=_b;i++){
    sum=i+sum;
  }
    printf("%d~%d之间的和为：%d \n",a,b,sum);

  return a;
}
int main(int argc,char**argv){
  int a,b;
  printf("请输入两个数\n");
  scanf("%d %d",&a,&b);
  while(getchar()!='\n');
  fun(a,b);
  return 0;
}
