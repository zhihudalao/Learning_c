#include<stdio.h>
void add(int** P,int** Q){
  (**P)=(**P)+(**Q);
}

int main(int argc,char**argv){
  int a=5,b=10;
  int*p=&a;
  int*q=&b;
  int** P=&(p);
  int** Q=&(q);
  add(P,Q);
  printf("%d\n",a);
  return 0;
}
