#include<stdio.h>
#include<math.h>
int fun(int m){
  int i,n;
  n=sqrt(m);
  for(i=2;i<=n;i++){
    if(m%i==0){return 0;}
  }
  return 1;
}
int main(int argc,char**argv){
  int i;
  for(i=3;i<=1000;i++){
    if(fun(i)){
      printf("%5d",i);
    }
  }

  return 0;
}
