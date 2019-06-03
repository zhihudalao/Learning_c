#include<stdio.h>
/*通过递归求一个数的阶乘*/
int func(int n){
  if(n<=1){return 1;}
 else {return (n*func(n-1));}
}
int main(int argc,char**argv){
  int r,n;
  printf("please input one num\n");
  scanf("%d", &n);
  r=func(n);
  printf("%d!=%d\n",n,r );
  return 0;
}
