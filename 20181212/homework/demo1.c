#include<stdio.h>

/*编写一个程序，输入年份和月份，判断该年是否是闰年，并根据给出的月份判断是什么季节，该月有多少天*/
int main (int argc,char** argv){
    int year,month;
    scanf("%d%d",&year,&month);
    if((year%4==0 && year%100!=0) || year%400==0){
        printf("闰年");
      }else{ printf("不是闰年\n");}
    switch(month)
    {
        case 1:   printf("春季,31天");
                  break;
        case 2:   if((year%4==0 && year%100!=0) || year%400==0)
                            printf("春季,29天");
                      else
                            printf("春季,28天");
                      break;
        case 3:   printf("春季,31天");
                  break;
        case 4:   printf("夏季,30天");
                  break;
        case 5:   printf("夏季,31天");
                  break;
        case 6:   printf("夏季,30天");
                  break;
        case 7:   printf("秋季,31天");
                  break;
        case 8:   printf("秋季,31天");
                  break;
        case 9:   printf("秋季,30天");
                  break;
        case 10:  printf("冬季,31天");
                  break;
        case 11:  printf("冬季,30天");
                  break;
        case 12:  printf("冬季,31天");
                  break;
    }
    printf("\n");
  return 0;
}
