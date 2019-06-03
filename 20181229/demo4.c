#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Data{
  char name[20];
  int id;
}data;//数据表
typedef struct student{
  struct student* prev;
  data data;
  struct student* next;
}stu_t;

void insertStu(stu_t* head){
  stu_t* newNode =(stu_t*)malloc(sizeof(stu_t));
  memset( newNode ,0,sizeof(stu_t));
  printf("请输入学生ID和姓名\n");
  scanf("%d",&newNode->data.id);
  scanf("%s",newNode->data.name);
  stu_t*p=head;
  while(p->next!=NULL){
    p=p->next;
  }
  p->next=newNode;
  newNode->prev=p;
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
  printf("请输入学生ID和姓名\n");
  scanf("%d",&target->data.id);
  scanf("%s",target->data.name);
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
  stu_t*target=findStu(head);
  if(target->next!=NULL){
    target->next->prev=target->prev;
  }
  target->prev->next=target->next;
  free(target);
}

void freeStu(stu_t*head){
  stu_t*p=head;
  while(p->next!=NULL){
    p=p->next;
    free(p->prev);
  }
  free(p);
}

void loadStu(stu_t*head){
	FILE* Rfp=fopen("./login.txt","r");
  stu_t* newNode =(stu_t*)malloc(sizeof(stu_t));
  memset( newNode ,0,sizeof(stu_t));

	if(Rfp==NULL){
    printf("error\n");
		return ;
	}
  int res;
  res=fscanf(Rfp,"%s",newNode->data.name);
  while(res!=-1)
  fscanf(Rfp,"%s",newNode->data.name);
  fscanf(Rfp,"%d",&newNode->data.id);
  stu_t*p=head;
  while(p->next!=NULL){
    p=p->next;
  }
  p->next=newNode;
  newNode->prev=p;
  newNode->next=NULL;
	fclose(Rfp);
}

void saveStu(stu_t*head){
	FILE* Wfp=fopen("./login.txt","w");
  stu_t*p=head->next;
  while(p!=NULL){
    fprintf(Wfp,"%s %d\n",p->data.name,p->data.id);
    p=p->next;
  }

	fclose(Wfp);
}

int main(int argc,char**argv){
  stu_t*head=(stu_t*)malloc(sizeof(stu_t));
  memset(head,0,sizeof(stu_t));
  loadStu(head);
  int ch=1;
  while(ch){
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
      case 0:
        saveStu(head);
        freeStu(head);
        break;
    }
  }

  return 0;
}
