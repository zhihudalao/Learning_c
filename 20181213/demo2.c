#include<stdio.h>
/*键盘输入两数字，他们最公约数最公倍数*/
int main(int argc,char** argv){
  int a,b,i,m,n,k;
  printf("please input two num\n");
  scanf("%d %d",&a,&b);
  m=(a<b)?a:b;
  for(i=m;i>0;i--){
    if(a%i==0&&b%i==0){
        printf("%d&%d的最大公约数为%d\n",a,b,i );
        break;
    }
  }
  k=a*b;
  n=(a>b)?a:b;
  for(i=n;i<=k;i++){
    if(i%a==0&&i%b==0){
        printf("%d&%d的最小公倍数为%d\n",a,b,i );
        break;
      }
  }
  return 0;
}
