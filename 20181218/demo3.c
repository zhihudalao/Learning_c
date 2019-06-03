/* 定义一个可以保存10个元素的一维数组，从终端输入10个元素，实现一个函数可以删除数组中指定的元素，如果不存在，提示删除失败！要求有函数设计。输出删除后数组中元素的值。 */
#include<stdio.h>
#include <stdlib.h>
#define N 10
void input(int* arr){
  for(int i=0;i<10;i++){
    scanf("%d",&arr[i]);
  }

}
void output(int* arr){
  for(int j=0;j<10;j++){
    printf("%d ",arr[j]);
    }printf("\n");
}
int check(int* arr){
  int i,x=0;
  printf("please input one num that you want to delete\n");
  scanf("%d",&x);
  printf("%d\n",x);
  for(i=0;i<N;i++){
    if(x==arr[i]){
      return i;
    }
  }return -1;
}
int del(int* arr,int flag){
    int j=0;

      for(j=flag;j<N-1;j++){
        arr[j]=arr[j+1];
      }
      for(int i=0;i<N-1;i++){
        printf("%3d",arr[i]);
      }printf("\n");

}
int main(int argc,char**argv){
  int arr[N];
  input(arr);
  output(arr);
  int flag;
  flag=check(arr);
  if(flag==-1){
    printf("delete defeat\n");
  }else{del(arr,flag);}
  return 0;
}
