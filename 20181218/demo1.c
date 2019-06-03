#include<stdio.h>

int main(int argc,char**argv){
  int arr[5]={0};
  int arr_1[5]={1,2,3,4,5,};
  int* arr1[]={arr,arr_1};
  printf("%ld\n",sizeof (arr) );
  printf("%ld\n",sizeof arr1 );
  printf("%ld\n",sizeof arr_1);
  return 0;
}
