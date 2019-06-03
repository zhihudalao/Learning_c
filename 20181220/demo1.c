#include<stdio.h>
#include<string.h>
int mystrlen(char*str){
  int count;
  for(int i;str[i]!='\0';i++){
    count++;
  }
  return count;
}
int mystrcmp(char*str,char*str2){
  int res,i;
  for(i=0;str[i]!='\0'||str2[i]!='\0';i++){
    if(str[i]!=str2[i]){
      res=str[i]-str2[i];
      return res;
    }
  }
  return 0;
}

int main(int argc,char**argv){
  char str[10];
  char str2[10];
  scanf("%s",str);
  scanf("%s",str2 );
  //strcpy(str,str2);
  //memcpy(str,str2,5);
  strcat(str,str2);
  printf("%s ",str);
  printf("%s\n",str2 );
  printf("%lu\n",sizeof(str) );
  printf("%lu\n",strlen(str) );
  int res=strcmp(str,str2);
  printf("%d\n",res);
  printf("%d\n",mystrcmp(str,str2));
  return 0;
}
