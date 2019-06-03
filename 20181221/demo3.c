#include<stdio.h>

int main(int argc,char**argv){
  int arr_1[5]={0,1,2,3,4};
  int arr_2[5]={5,6,7,8,9};
  int* arr1[2]={arr_1,arr_2};
  int** p=arr1;
  printf("%d\n",*(*(p+1)+1));
  int arr2[2][5]={
    {0,1,2,3,4},
    {5,6,7,8,9}
  };
  int(*q)[5]=arr2;//二维数组指针申明

  printf("%d\n", **q+7);
  printf("%d\n", *(*(q+1)+2));
  printf("%d\n", q[1][2]);
  return 0;
}
