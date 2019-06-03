#include<stdio.h>
#include<stdlib.h>
/*请编写一个函数void printPrime(int m,int k,int arr[]){
,该函数的功能是：将大于整数m且紧靠m的k个素数存入数组arr中。
其中k表示数组arr的所指的数组中素数的个数，最后输出该数组中的k个素数*/
int prime(int m, int k, int arr[])
{
    int i;
    int notprime(int n);
    for(i = m; k > 0; i++){
        if(!notprime(i)){      //只要非素数函数返回0, k减少一个值
            k--;
            arr[k] = i;
        }
    }
}
int notprime(int n)       /* 非素数函数，找出非素数的数字*/
{
    int i, j, flag = 0;

    for(i = 2; i < n+1; i++){
        for(j = 2; j < n; j++)
            if(i * j == n){
                flag = 1;
                break;
            }
        if(flag)
            break;
    }
    return flag;
}
int main(void)
{
    int i, m, k;
    int a[k];
    printf("请输入整数M\n");
    scanf("%d", &m);
    printf("请输入素数个数K\n");
    scanf("%d", &k);
    prime(m, k, a);
    printf("这%d个素数分别是：", k);
    for(i = 0; i < k; i++)
        printf(" %d ",a[i]);
    printf("\n");
}
