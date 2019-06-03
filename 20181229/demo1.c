#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
  char name[20];
  int id;
  struct student* next;
}stu_t;
int main(int argc,char**argv){
  stu_t*st1=(stu_t*)calloc(1,sizeof(stu_t));
  stu_t*st2=(stu_t*)calloc(1,sizeof(stu_t));
  stu_t*st3=(stu_t*)calloc(1,sizeof(stu_t));
  strcpy((*st1).name,"zhangsan");
  (*st1).id=180701;
  (*st1).next=st2;
  st2->next=st1;
  printf("%s %d\n",st2->next->name,st2->next->id );
  return 0;
}
