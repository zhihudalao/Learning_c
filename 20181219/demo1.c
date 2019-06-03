#include<stdio.h>
#define N 10
void input(int* a,int len){
  printf("please input %d numbs\n",len);
  for(int i=0;i<len;i++){
    scanf("%d",&a[i]);
  }
}
void output(int* a,int len){
  for(int i=0;i<len;i++){
    printf("%2d",a[i]);
  }
printf("\n");
}
void mobblesort(int* a,int len){
  int i,j;
  for(i=0;i<len;i++){
    for(j=0;j<len-1;j++){
      if(a[j]<a[j+1]){
        a[j]=a[j]^a[j+1];
        a[j+1]=a[j]^a[j+1];
        a[j]=a[j]^a[j+1];
      }
    }
  }
  output(a,len);
}
int main(int argc,char**argv){
  int a[N];
  input(a,N);
  output(a,N);
  mobblesort(a,N);
  return 0;
}
