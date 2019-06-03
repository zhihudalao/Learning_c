#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*头插法*/
typedef struct student{
  char name[20];
  int id;
  struct student* next;
}stu_t;
void insertStu(stu_t* head){
  stu_t* newNode =(stu_t*)malloc(sizeof(stu_t));
  memset( newNode ,0,sizeof(stu_t));
  strcpy(newNode->name,"zhangsan");
  newNode->id=180701;
  newNode->next=head->next;
  /*newNode->prev=head;
  head->next->prev=newNode;*/
  head->next=newNode;
}
int main(int argc,char**argv){
  stu_t*head=(stu_t*)malloc(sizeof(stu_t));
  memset(head,0,sizeof(stu_t));
  insertStu( head);
  printf("%s %d\n",head->next->name,head->next->id);
  return 0;
}
