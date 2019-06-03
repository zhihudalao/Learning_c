#include<stdio.h>

int main(int argc,char**argv){
  int arr_1[5]={0};
  int arr_2[5]={1,2,3,4,5};
  for (int i=0;i<5;i++){
    printf("%d",arr_2[i]);
  }
  printf("\n");
  for(int j=0;j<5;j++){
    arr_1[j]=arr_2[j];
  }
  for (int i=0;i<5;i++){
    printf("%d",arr_1[i]);
  }
  printf("\n");
  return 0;
}
