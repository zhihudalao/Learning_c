#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*尾插法*/
typedef struct Data{
  char name[20];
  int id;
}data;
typedef struct student{
  data data;
  struct student* next;
}stu_t;
void insertStu(stu_t* head){
  stu_t* newNode =(stu_t*)malloc(sizeof(stu_t));
  memset( newNode ,0,sizeof(stu_t));
  printf("请输入学生姓名id\n");
  scanf("%s %d",newNode->data.name,&newNode->data.id);
  stu_t*p=head;
  while(p->next!=NULL){
    p=p->next;
  }
  p->next=newNode;
  newNode->next=NULL;
}
void printAll(stu_t*head){
  stu_t*p=head->next;
  while(p!=NULL){
    printf("%s %d\n",p->data.name,p->data.id);
    p=p->next;
  }
}
stu_t* findStu(stu_t* head){
  stu_t*p=head->next;
  int id=0;
  printf("please input student id\n");
  scanf("%d",&id);
  while(getchar()!='\n');
  while(p!=NULL){
    if(p->data.id==id){
      return p;
    }
    p=p->next;
  }
  return NULL;
}
void updataStu(stu_t*head){
  stu_t*target=findStu(head);
  if(target==NULL){
    printf("不存在\n");
    return;
  }
  strcpy(target->data.name,"lisi");
}
void stuSort(stu_t*head){
  stu_t*p=head->next;
  int flag=0;
  data temp;
  while(1){
    flag=0;
    p=head->next;
    while(p->next!=NULL){
      if(p->data.id>p->next->data.id){
        temp=p->data;
        p->data=p->next->data;
        p->next->data=temp;
        flag=1;
      }
      p=p->next;
    }
    if(flag==0){
      break;
    }
  }
}
void removeStu(stu_t*head){
  int id=0;
  printf("请输入要删除学生的id\n");
  scanf("%d",&id);
  while(getchar()!='\n');
  stu_t*p=head->next;
  stu_t*temp=NULL;
  while (p->next!=NULL) {
    if(p->next->data.id==id){
      temp=p->next;
      p->next=p->next->next;
      free(temp);
    }else{p=p->next;}

  }
}
void freeStu(stu_t*head){
  stu_t*p=head;
  stu_t*temp=NULL;
  while(p->next!=NULL){
    temp=p;
    p=p->next;
    free(temp);
  }
  free(p);
}
int main(int argc,char**argv){
  stu_t*head=(stu_t*)malloc(sizeof(stu_t));
  memset(head,0,sizeof(stu_t));
  int ch=0;
  while(1){
    printf("1:添加学生\n");
    printf("2:修改学生\n");
    printf("3:排序\n");
    printf("4:删除学生\n");
    printf("5:打印所有学生\n");
    printf("请选择\n");
    scanf("%d",&ch);
    switch (ch) {
      case 1:insertStu(head);
      break;
      case 2:updataStu(head);
      break;
      case 3:stuSort(head);
      break;
      case 4:removeStu(head);
      break;
      case 5:printAll(head);
      break;
      case 0:freeStu(head);
      return 0;
    }
  }
  return 0;
}
