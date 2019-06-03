#include<stdio.h>
#include<string.h>
/*使用二维字符数组，完成一个注册功能，注意需要防重复注册。
就是说，我没注册一个账号（为字符串），就会将这个字符串保存到一个数组中去。该数组也叫字符串数组。*/
void add(char** database){

}

int main(int argc,char**argv){
  char name[50]={'\0'};
  char* database[512]={NULL};
  for(int i=0;i<512;i++){
    char newName[50]={'\0'};
    database[i]=newName;
    printf("%s\n",database);
  }
  return 0;
}
