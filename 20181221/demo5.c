#include<stdio.h>
#include<string.h>
int mystrcat(){}
int main(int argc,char**argv){
  char arr1[10]="hello";
  char arr2[5]="world";
  printf("%s\n",strcat(arr1,arr2));
  /*memcpy(arr1+5,arr2,5);
  printf("%s\n",arr1);*/

  return 0;
}
