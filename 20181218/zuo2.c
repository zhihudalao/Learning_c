#include<stdio.h>
#define N 5
/*定义一个5个元素的一维数组(arr)，从键盘输入5个元素的值存到该数组，实现冒泡排序并输出，初始化，排序，输出功能要求分函数写*/
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
  int i,j,temp,pos;
  for(i=0;i<len-1;i++){
    pos=i;
    for(j=i+1;j<N;j++){
      if(arr[j]<arr[pos]){
        pos=j;
      }
    }
    if(pos!=i){
      temp=arr[pos];
      arr[pos]=arr[i];
      arr[i]=temp;
    }
  }
  printf("After ordering ,the rank is:\n");
  output(arr,N);
}
int main(int argc,char**argv){
  int arr[N];
  while(1){
    input(arr,N);
    output(arr,N);
    bubble(arr,N);
    }
  return 0;
}
