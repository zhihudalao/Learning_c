#include<stdio.h>
#include <stdlib.h>
#define N 10
void input(int* arr,int len){
  for(int i=0;i<10;i++){
    scanf("%d",&arr[i]);
  }

}
void output(int* arr,int len){
  for(int j=0;j<len;j++){
    printf("%d ",arr[j]);
    }printf("\n");
}
int Nlen(int* arr,int len){
  if(len==10){
    printf("delete defeat\n");
  }else{
  output(arr,len);
  }
}


int del(int* arr){
  int i,count=0,x=0;
  printf("please input one num that you want to delete\n");
  scanf("%d",&x);
  printf("%d\n",x);
  for(i=0;i<N-count;i++){
    if(x==arr[i]){
      count++;
      for(int j=i;j<N-count;j++){
        arr[j]=arr[j+1];
      }
      i--;
    }
  }
Nlen(arr,N-count);
}

int main(int argc,char**argv){
  int arr[N];
  input(arr,N);
  output(arr,N);
  del(arr);
  return 0;
}
