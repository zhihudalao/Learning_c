#include<stdio.h>
/*从键盘输入十个整数存入一维数组中，使用函数求出它们的和并输出（要求用指针访问数组元素）*/
void input(int* arr){
  printf("please input ten num\n");
  for(int i=0;i<10;i++){
    scanf("%d",&arr[i]);
  }
}
void output(int*arr){
  for(int i=0;i<10;i++){
    printf("%4d",arr[i]);
  }
  printf("\n");
}
int mysum(int*arr){
  int res=0;
  for(int i=0;i<10;i++){
    res=res+arr[i];
  }
  printf("%d\n",res);
}
int main(int argc,char**argv){
  int arr[10];
  input(arr);
  output(arr);
  mysum(arr);
  return 0;
}
