#include<stdio.h>

/*编写交换两个变量值的函数，并调用该函数交换主函数中两个变量的值（不能使用全局变量传递数据）*/
void exchange(int* a,int*b){
  *a=*a^*b;
  *b=*a^*b;
  *a=*a^*b;
  printf("%d  %d\n",*a,*b );
}
int main(int argc,char**argv){
  int a,b;
  int*p=&a;
  int*q=&b;
  printf("please input two num\n");
  scanf("%d%d",&a,&b);
  exchange(p,q);
  return 0;
}
