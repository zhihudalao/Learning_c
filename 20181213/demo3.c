#include<stdio.h>
/*	键盘输入一个整型数，长度不限，将其逆序输出。
	例如键盘输入123456789，输出987654321*/
int main(int argc,char** argv){
  /*int a,i;
  printf("please input one num\n");
  scanf("%d",&a);
  while (a!=0) {
    printf("%d",a%10 );
    a=a/10;
  }
  printf("\n");*/
  int a=0;
  int res=0;
  scanf("%d",&a);
  while(a!=0){
    res=res*10+a%10;
    a=a/10;
  }
  printf("%d\n",res );
  return 0;
}
