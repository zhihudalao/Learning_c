#include<stdio.h>

int main(int argc,char**argv){
 FILE* fp=fopen("./text.txt","r");
 char str[512]={0};
 fgets(str,512,fp);
 printf("%s\n",str);
 fclose(fp);
  return 0;
}
