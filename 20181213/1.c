#include<stdio.h>

int prine(int n){
  int j;
  for(j=2;j<=n/2;j++){
    if(n%j==0){return 0;}
  }
  return 1;
}
int main(int argc,char**argv){
  int i,sum=0;
  for(i=3;i<1000;i++){
    if(prine(i)==1){
      sum+=i;
    }
  }
  printf("%d\n",sum );
  return 0;
}
