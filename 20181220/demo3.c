#include<stdio.h>

/*编写判断素数的函数，再调用该函数求出1000以内的所有素数？*/
int ifprime(int a){
  int i;
    for(i=2;i<a-1;i++){
      if(a%i==0){
        return 0;
      }
    }
    return a;
}

void mysum(){
  int j,a,sum;
  for(j=2;j<=1000;j++){
    a=ifprime(j);
    if(a!=0)
    sum=sum+a;
  }
  printf("%d\n",sum);
}
int  main(int* argc,char** argv){
  mysum();
  return 0;

}
