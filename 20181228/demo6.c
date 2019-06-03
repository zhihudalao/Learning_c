#include<stdio.h>
typedef struct Student{
  int id;
  char name[20];
  int age;
  int sal;
}stu_t;
void printStu(stu_t* stuDB){
  int i=0;
  for(i=0;i<4;i++){
    printf("ID：%d\n姓名：%s\n年龄： %d\n收入： %d\n",
    stuDB[i].id,stuDB[i].name,stuDB[i].age,stuDB[i].sal);
  }
}
void stuSort(stu_t*stuDB){
  stu_t temp;
  for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
      if((stuDB[j].age)>(stuDB[j+1].age)){
        temp=stuDB[j];
        stuDB[j]=stuDB[j+1];
        stuDB[j+1]=temp;
      }
    }
  }
  printStu(stuDB);
}
void read(stu_t* stuDB){
  char arr[512];
  FILE*fp=fopen("./counter.txt","r");
  fgets(arr,512,fp);
  int i=0;
  while(!feof(fp)){
    fscanf(fp,"%d\n",&stuDB[i].id);
    fscanf(fp,"%s\n",stuDB[i].name);
    fscanf(fp,"%d\n",&stuDB[i].age);
    fscanf(fp,"%d\n",&stuDB[i].sal);
    i++;
  }
  fclose(fp);
}
int main(int argc,char**argv){
  stu_t stuDB[512];
  read(stuDB);
  stuSort(stuDB);
  return 0;
}
