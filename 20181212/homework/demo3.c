#include<stdio.h>
/*求1到n之间的偶数的平方和*/
int main (int argc,char** argv){
int i,sum=0,n;
    scanf("%d",&n);
    for(i=2;i<=n;i+=2)
        sum+=i*i;
    printf("平方和为：%d\n",sum);
return 0;
}
