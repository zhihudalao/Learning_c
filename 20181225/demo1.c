#include<stdio.h>
struct tu{
  int a;
  char b;
};
  typedef struct Stu{
    int a[25];
    double b;
    int c[25];
  }Stu;
int main(int argc,char**argv){
  Stu stu;
  printf("%lu\n",sizeof(tu));
  return 0;
}
