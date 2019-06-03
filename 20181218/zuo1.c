#include<stdio.h>
#define N 10
/*从键盘输入10个数,用按降序排序并输出。(使用指针实现冒泡排序)*/
void input(int* arr,int len){
  for(int i=0;i<len;i++){
    scanf("%d",&arr[i]);
  }
}
void output(int* arr,int len){
  for(int j=0;j<len;j++){
    printf("%d ",arr[j]);
    }printf("\n");
}
void bubble(int* arr,int len){
  int i,j,temp;
  for(j=0;j<len-1;j++){
    for(i=0;i<len-j-1;i++){
      if(arr[i]<arr[i+1]){
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
      }
    }
  }
  printf("After ordering ,the rank is:\n");
  output(arr,N);
}
int main(int argc,char**argv){
  int arr[N];
  input(arr,N);
  output(arr,N);
  bubble(arr,N);
  return 0;
}
