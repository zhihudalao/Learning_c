#include<stdio.h>
#include<stdlib.h>
/*定义一个可以保存10个元素的整型数组，从终端上输入给数组赋值，最后求出数组中所有元素的和并输出。（要求输入和计算所有元素的和要有函数设计）*/
int main(int argc,char**argv){
  int a[10];
  int i=0,j=0;
  for(i=0;i<10;i++){
    scanf("%d",&a[i]);
  }
  int sum=0;
  for(j=0;j<10;j++){
    printf("%d ",a[j]);
    sum=a[j]+sum;
    }
  printf("\n");
  printf("%d\n",sum);
  return 0;
}
