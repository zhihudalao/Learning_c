#include<stdio.h>
#include<stdlib.h>
/*定义一个长度为10的动态数组，要求键盘赋值，去掉其中最大的2个数和最小的2个数，求剩余数据的平均值*/
int main(int argc,char**argv){
  int*p=(int*)calloc(10, sizeof(int));
  printf("please input ten nums\n");
  for(int i=0;i<10;i++){
    scanf("%d",p+i);
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<9;j++){
      if(p[j]<p[j+1]){
        p[j]=p[j]^p[j+1];
        p[j+1]=p[j]^p[j+1];
        p[j]=p[j]^p[j+1];
      }
    }
  }
  for(int i=0;i<10;i++){
    printf("%d ",p[i]);
  }
  printf("\n");
  p[0]=0;p[1]=0;p[8]=0;p[9]=0;
  float sum=0;
  for(int i=0;i<10;i++){
    sum=p[i]+sum;
  }
  printf("平均值：%lg\n",sum/6);
  free(p);
  return 0;
}
