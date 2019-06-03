#include"head.h"
/*
函数名称：insertStu
函数功能：管理员添加学生
函数返回值：void
*/
void insertStu(stu_t* head){
  stu_t* newNode =(stu_t*)malloc(sizeof(stu_t));
  assert(head);
  memset( newNode ,0,sizeof(stu_t));
	stu_t*p=head;
	int id=0;
	printf("************************\n");
  printf("请输入学生姓名,语文成绩，数学成绩，英语成绩\n");
	printf("************************\n");
  scanf("%s",newNode->data.name);
	scanf("%d",&newNode->data.Chi);
	scanf("%d",&newNode->data.Math);
	scanf("%d",&newNode->data.Eng);
	strcpy(newNode->data.pswd,"123456");
  while(p->next!=NULL){
    p=p->next;
  }
	id=p->data.id;
	id++;
	newNode->data.id=id;
  p->next=newNode;
  newNode->prev=p;
  newNode->next=NULL;
}

/*
函数名：findStu
函数功能：管理员通过输入id号找到对应的学生p
函数返回值：将找到的学生所在结构体*p返回给外部
*/
stu_t* findStu(stu_t* head){
  stu_t*p=head->next;
  int id=0;
  printf("请输入学生id\n");
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

/*
函数名:updateStu
函数功能：通过调用查找函数，找到需要修改的学生的确切位置，然后使用该位置，直接找到该学
	生并修改信息
函数返回值：当找到学生并修改成功，返回1，反之则返回-1
*/

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

/*
函数名：printAllStu
函数功能：将结构体数组内所有代表学生个体的结构体打印出来
函数返回值：void
*/
void printAll(stu_t*head){
  stu_t*p=head->next;
  while(p!=NULL){
		printf("************************\n");
    printf("姓名：%s 学号： %d 语文成绩： %d 数学成绩： %d 英语成绩： %d\n",
		p->data.name,p->data.id,p->data.Chi,p->data.Math,p->data.Eng);
		printf("************************\n");
    p=p->next;
  }
}

/*
函数名：stuSort
函数功能：将学生结构体数组内所有学生结构体按照特定要求进行排序
函数返回值:void
*/
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

/*
函数名：removeStu
函数功能：删除学生
函数返回值：将学生结构体数组更新后的长度返回到外部
*/

void removeStu(stu_t*head){
  stu_t*target=findStu(head);
  if(target->next!=NULL){
    target->next->prev=target->prev;
  }
  target->prev->next=target->next;
  free(target);
}
/*
函数名：freeStu
函数功能：释放
函数返回值：void
*/
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
  char name[20];
  char pswd[20];
  int id=0;
  int chi=0;
  int math=0;
  int eng=0;
  int res=0;
	if(Rfp==NULL){
    printf("error\n");
		return ;
	}
  stu_t*p=head;
  while(p->next!=NULL){
    p=p->next;
  }//P是尾节点
	while(1){
    //fscanf(Rfp,"%s %d %d %d %d",newNode->data.name,&newNode->data.id,&newNode->data.Chi,&newNode->data.Math,&newNode->data.Eng);
    res=fscanf(Rfp,"%s %s %d %d %d %d",
    name,pswd,&id,&chi,&math,&eng);
    if(res!=6){break;}
    stu_t*newNode =(stu_t*)malloc(sizeof(stu_t));
    memset( newNode ,0,sizeof(stu_t));
    strcpy(newNode->data.name,name);
    strcpy(newNode->data.pswd,pswd);
    newNode->data.id=id;
    newNode->data.Chi=chi;
    newNode->data.Math=math;
    newNode->data.Eng=eng;
    p->next=newNode;
    newNode->next=NULL;
    newNode->prev=p;
	}

	fclose(Rfp);
}


void saveStu(stu_t*head){
	FILE* Wfp=fopen("./login.txt","w");
	if(Wfp==NULL){
    printf("error\n");
		return ;
	}
  stu_t*p=head->next;//头节点
  while(p!=NULL){
    fprintf(Wfp,"%s %s %d %d %d %d\n",
    p->data.name,p->data.pswd,p->data.id,p->data.Chi,p->data.Math,p->data.Eng);
    p=p->next;
  }

	fclose(Wfp);
}
/*
函数名：adminLogin
函数功能：管理员登录用
返回值：void
*/
void adminLogin(){
	char name[50]="admin123";
	char pswd[50]="123456";
	char _name[50];
	char _pswd[50];
	int flag=0;
	while(1){
		printf("************************\n");
		printf("请输入账号:");
		scanf("%s",_name);
		while(getchar()!='\n');
		printf("请输入密码:");

		scanf("%s",_pswd);
		while(getchar()!='\n');
		if(strcmp(name,_name)==0 && strcmp(pswd,_pswd)==0){
			flag=1;
		}
		if(flag==1){
			break;
		}
		printf("账号或密码错误\n");
	}
}

/*
函数名：printStu
函数功能：打印单个学生信息
返回值：void
*/
void printStu(stu_t* head){
	stu_t*p=findStu(head);
	printf("********************\n");
  printf("姓名：%s 学号： %d 语文成绩： %d 数学成绩： %d 英语成绩： %d\n",
  p->data.name,p->data.id,p->data.Chi,p->data.Math,p->data.Eng);
}

/*
函数名：stuLogin
函数功能：学生登录时使用
函数返回值：学生登录成功后，确切的将学生本身返回给外部 stu_t
*/
int ifname(stu_t*head){
  stu_t*p=head->next;
  int name;
  printf("请输入账号:");
  scanf("%d",&name);
  while(getchar()!='\n');
  if(name==0){return 0;}
  while(p!=NULL){
    if(p->data.id==name){
      printf("账号正确\n");
      return name;
    }
    p=p->next;
  }
  printf("账号不存在\n");
  return -1;
}
int ifpswd(stu_t*head){
  stu_t*p=head->next;
  char pswd[50];
  printf("请输入密码:");
  scanf("%s",pswd);
  while(getchar()!='\n');
  while(p!=NULL){
    if(strcmp(p->data.pswd,pswd)==0){

      return 1;
    }
    p=p->next;
  }
  printf("密码错误\n");
  return -1;
}
int stuLogin(stu_t* head){
  int flag,flag1;
	while(1){
    flag=ifname(head);
    if(flag!=-1){
      flag1=ifpswd(head);
      if(flag1==1){printf("密码正确登陆成功\n");}
      return flag;
    }else if(flag==0){
      return 0;
    }
	}
}

/*
函数名：seachScore
函数功能：查看学生的成绩
函数返回值：void
*/
void seachScore(stu_t*head,int id){
  stu_t*p=head->next;
  while(p!=NULL){
    if(p->data.id==id){
      printf("********************\n");
      printf("姓名：%s 学号： %d 语文成绩： %d 数学成绩： %d 英语成绩： %d\n",
      p->data.name,p->data.id,p->data.Chi,p->data.Math,p->data.Eng);
      return ;
    }
    p=p->next;
  }
  return ;
}

/*
函数名：seachRank
函数功能：查看学生的排名
函数返回值：void
*/
void seachRank(stu_t* head,int id){
	/*int i=0;
	for(i=0;i<*len;i++){
		if(DB[i].id==st.id){
			printf("成绩：%d\n",DB[i].rank);
		}
	}*/
}

/*
函数名：updateScore
函数功能：修改成绩
函数返回值：void
*/
void updatepswd(stu_t* head,int id){
  stu_t*p=head->next;
  char newPswd[20];
  printf("请输入新的密码:");
	scanf("%s",newPswd);
	while(getchar()!='\n');
  while(p!=NULL){
    if(p->data.id==id){
      strcpy(p->data.pswd,newPswd);
      printf("修改成功\n");
      return ;
    }
    p=p->next;
  }
  return ;
}
