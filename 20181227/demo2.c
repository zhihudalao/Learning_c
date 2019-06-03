#include<stdio.h>
#include<stdlib.h>
/*在堆上分配一个学生结构体，键盘输入学生的编号、姓名、成绩，并输出（注意内存泄露）。*/
typedef struct Student{
  int id;
  char name[20];
  int score;
}stu_t;
int main(int argc,char**argv){
  stu_t* stu=(stu_t*)calloc(30,sizeof(stu_t));
  printf("请输学生的编号姓名成绩\n");
  for(int i=0;i<5;i++){
    scanf("%d",&stu[i].id);
    scanf("%s",stu[i].name);
    scanf("%d",&stu[i].score);
  }
  for(int i=0;i<5;i++){
    printf("%d ",stu[i].id);
    printf("%s ",stu[i].name);
    printf("%d\n",stu[i].score);
  }
  free(stu);
  return 0;
}
