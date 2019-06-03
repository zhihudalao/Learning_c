#include<stdio.h>

int main(int argc,char**argv){
int i,j,sum,a;
printf("请输入一个数\n");
scanf("%d",&a);
int flag;
for (i = 2; i <=a; i++) {
  flag=0;
  sum=1;
  for(j=2;j<=i/2;j++){
    if(i%j==0)
    sum+=j;
  }
  if(sum==i){
    flag=1;
  }
}
if(flag==0){
  printf("不是完数\n");
}else{printf("完数\n");}
  return 0;
}
