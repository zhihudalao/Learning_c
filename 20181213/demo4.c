#include<stdio.h>
/*	 1)键盘输入一个数字，判断他是不是质数
*/
int main(int argc,char** argv){
  printf("请输入一个数\n");
  int a,i;
  scanf("%d",&a );
  for(i=2;i<a;i++){
    if(a%i==0){
      printf("不是质数\n");
      return 0;
    }
  }
  printf("质数\n");
  return 0;
}
