#include<stdio.h>

int main(int argc,char**argv){
  printf("%s\n",*(argv+2));
  printf("%c\n",*(*(argv+2)+1) );

  return 0;
}
