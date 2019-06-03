#include<stdio.h>

int main(int argc,char**argv){
  int *p;
  p=10;//这是个野指针
  int *p=NULL;
  p=10;//这是个空指针
  char *p="helloworld";
  p[0]='H';//这是个常量指针 不可被修改

  return 0;
}
