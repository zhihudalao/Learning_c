#include<stdio.h>
#include<math.h>
/*编写一个程序使循方式，测char类数据取值的范围*/
int main(int argc,char**argv){
  char a='\0';
  char max,min;
  for(a=0,max=a-1;a>max;a++){
    max=a;
  }
  for(a=0,min=a+1;a<min;a--){
    min=a;
  }
  printf("%d  %d\n",max,min);

  return 0;
}
