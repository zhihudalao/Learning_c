#ifndef _head_h
#define _head_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef struct Data{
  char name[20];
  char pswd[20];
  int id;
	int Chi;
	int Eng;
	int Math;
}data;//数据表
typedef struct student{
  struct student* prev;
  data data;
  struct student* next;
}stu_t;

void insertStu(stu_t* head);
stu_t* findStu(stu_t* head);
void updataStu(stu_t*head);
void printAll(stu_t*head);
void stuSort(stu_t*head);
void removeStu(stu_t*head);
void freeStu(stu_t*head);
void loadStu(stu_t*head);
void saveStu(stu_t*head);
void adminLogin();
void adminInterface(stu_t*head);
void printStu(stu_t* head);
void stuInterface(stu_t* head);
void adminInterface(stu_t*head);
int stuLogin(stu_t* head);
int ifpswd(stu_t*head);
int ifname(stu_t*head);
void seachScore(stu_t* head,int id);
/*void rankSort(stu_t* DB,int* len);*/
void seachRank(stu_t* head,int id);
void updatepswd(stu_t* head,int id);
#endif
