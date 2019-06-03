#include<stdio.h>

int main(int argc,char**argv){
  char str1[6]="hello";
  char str2[6]="world";
  char* str[10];
  for(int i=0;i<10;i++){
    char temp='\0';
    str[i]=&temp;
  }
  str[0]=str1;
  str[1]=str2;
  printf("%s %s\n",*(str),*(str+1));
  const char*p1="helloworld";
  char a='0';
  char* const p2=&a;
  p1="hello";//p1常量指针，可以改变指向
  *p2='5';//p2是指针常量，内容可以改变
  printf("%c\n",*p2);
  return 0;
}
