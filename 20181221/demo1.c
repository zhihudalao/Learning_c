#include<stdio.h>

int main(int argc,char**argv){
  int a=10;
  int*p=&a;
  int**p1=&p;
  printf("%p\n",p1);
  printf("%p\n",&p);
  **p1=20;
  printf("%d\n",**(p1));
  return 0;
}
