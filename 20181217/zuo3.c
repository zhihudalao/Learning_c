/* 定义一个可以保存10个元素的一维数组，从终端输入10个元素，实现一个函数可以删除数组中指定的元素，如果不存在，提示删除失败！要求有函数设计。输出删除后数组中元素的值。 */
#include<stdio.h>
#include <stdlib.h>
#define N 10
int del(int a[],int n,int x){
  int i,j;
  for(i=0;i<n;i++){
    if(x==a[i]){
      break;
    }
  }
    if(i==10){
      printf("defeat\n");
    }else{
      for(j=i;j<9;j++){
        a[j]=a[j+1];
      }
      for(i=0;i<9;i++){
        printf("%3d",a[i] );
      }printf("\n");
    }
}

int main(int argc,char**argv){
  int a[10],i,j,x;
  for(i=0;i<10;i++){
    scanf("%d",&a[i]);
  }
  for(j=0;j<10;j++){
    printf("%d ",a[j]);
    }
  printf("\n");
  printf("please input one num that you want to delete\n");
  scanf("%d",&x);
  del(a,N,x);
  return 0;
}
