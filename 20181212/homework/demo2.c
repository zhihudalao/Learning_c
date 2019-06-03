#include<stdio.h>
/*请输入星期几的第一个字母, 来判断一下是星期几? 如果第一个字母一样，则继续判断第二个字母。(4’) Mon: Tues: Wed: Thur: Fri: Sat:Sun*/
int main (int argc,char** argv){
  char a = '0';
  char b = '0';
  printf("请输入当前星期数的首字母:\n");
  scanf("%c", &a);
  getchar();
  if (a == 'm') {
      printf("星期一\n");
      } else if (a == 'w') {
        printf("星期三\n");
      } else if (a == 'f') {
        printf("星期五\n");
      } else if(a=='t'){
        printf("请输入当前星期数的第二个字母:\n");
        scanf("%c", &b);
        getchar();
        if (b == 'h') {
          printf("星期二\n");
        } else if (b == 'u') {
          printf("星期四\n");
        }
      }else if(a=='s'){
        printf("请输入当前星期数的第二个字母:\n");
        scanf("%c", &b);
        getchar();
        if (b == 'a') {
          printf("星期六\n");
        } else if (b == 'u') {
          printf("星期日\n");
        }
      }
return 0;
}
