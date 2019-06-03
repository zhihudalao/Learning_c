#include<stdio.h>
typedef struct Studsent{
   char name[50];
   int id;
}stu_t;
int main(int argc,char**argv){
  FILE*fp=fopen("./text.txt","r");
  stu_t str;
  fgets((char*)&str,sizeof(stu_t),fp);
  printf("%s\n",str.name);
  return 0;
}
