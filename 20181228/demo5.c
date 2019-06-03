#include<stdio.h>
/*练习题，使用fgets和fputs实现shell指令的cp功能*/
int main(int argc,char**argv){
  if(argc!=3){return 0;}
  FILE* fp=fopen(argv[1],"r");
  FILE* fp1=fopen(argv[2],"w");
  char arr[512];
  while(1){
    if(fgets(arr,512,fp)==NULL){break;}
    fputs(arr,fp1);
  }
  fclose(fp);
  fclose(fp1);
  return 0;
}
