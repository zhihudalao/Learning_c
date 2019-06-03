#include<stdio.h>
/*现有学生结构体Stu(包括:name,age)，有5个学生的数据，请找到年龄最大的人，并输出*/
struct stu{
  char name[20];
  int age[5];
};
int main(int argc,char**argv){
  int max=0,i,j;
  struct stu student[5]={
                    {"zhangsan",20},
                    {"lisi",21},
                    {"wangwu",25},
                    {"zhaoliu",23},
                    {"wangba",30}
                  };
  for(i=0;i<5;i++){
      if(*student[i].age>max){
        max=*student[i].age;
      }
  }
  for(j=0;j<5;j++){
    if(*student[j].age==max){
      break;
    }
  }
  printf("%s %d\n",student[j].name,*student[j].age);
  return 0;
}
