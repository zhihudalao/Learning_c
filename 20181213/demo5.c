#include<stdio.h>
/*   2)求1~100之内所有质数的和*/
int main(int argc,char** argv){
  int i,j,sum=0,n=0;
  printf("请输入一个数\n");
  scanf("%d",&n);
  int flag;
  for(j=2;j<n+1;j++){
    flag=0;
    for(i=2;i<j;i++){
      if(j%i==0){
        flag=1;
      }
    }

    if(flag==0){
      sum=sum+j;
    }
  }
  printf("1~%d之间质数和：%d\n",n,sum);
  return 0;
}
