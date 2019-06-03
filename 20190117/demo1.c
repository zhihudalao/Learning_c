#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
//int stat(const char *pathname, struct stat *buf);
//off_t     st_size;
typedef struct sta{
  char  Name[512];
  off_t size;
}Sta;
void sort(Sta* sta,int  num){
  Sta tmp;
  int i,j;
  for(i=0;i<num-1;i++){
    for(j=0;j<num-1;j++){
      if(sta[j].size>sta[j+1].size){
        tmp=sta[j];
        sta[j]=sta[j+1];
        sta[j+1]=tmp;
      }
    }
  }
}
void show(Sta* sta,int num){
  int i=0;
  for(i=0;i<num;i++){
    printf("%s--->%ld\n",sta[i].Name,sta[i].size );
  }
}
int main(int argc,char**argv){
  if(argc<2){
    printf("参数不正确\n");
    return 1;
  }
  Sta* sta=(Sta*) malloc((argc-1)* sizeof(sta));
  struct stat s;
  int i=0;
  for (i=1; i<argc; i++)
	{
		strcpy(sta[i-1].Name, argv[i]);
		stat(argv[i], &s);
		sta[i-1].size = s.st_size;
	}
	show(sta, argc-1);

	sort(sta, argc-1);

	printf("---------------------\n");
	show(sta, argc-1);


  return 0;
}
