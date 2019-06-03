#include <stdio.h>
#include <stdlib.h>
/*3个学生各学4门课，计算总平均分，并输出第n个学生成绩。*/
int aver(int *p,int n){
    int aver,sum=0;
    int *p_end;
    p_end=p+n-1;
    for(; p<=p_end; p++)
    {
        sum=sum+(*p);
    }
    aver=sum/n;
    printf("average=%4d\n",aver);
    return 0;
}

int search(int (*p)[4],int n){
    int i;
    printf("NO.%d :\n",n+1);
    for(i=0; i<4; i++)
    {
        printf("%4d",*(*(p+n)+i));
    }
    printf("\n");
    return 0;
}
int main(){
    int score[3][4]= {{65,67,79,60},{80,87,90,81},{90,99,100,98}};
    aver(*score,12);
    search(score,2);
    return 0;
}
