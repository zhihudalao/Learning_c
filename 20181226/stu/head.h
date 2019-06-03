#ifndef _head_h
#define _head_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct Student{
	char name[50];
	int score;
	int id;
	int rank;
}stu_t;

int insertStu(stu_t* DB,int* len);
int findStu(stu_t* DB,int* len);
int updateStu(stu_t* DB,int* len);
void printAllStu(stu_t* DB,int* len);
void stuSort(stu_t* DB,int* len);
int removeStu(stu_t* DB,int* len);
void adminLogin();
void adminInterface(stu_t* DB,int* len);
void printStu(stu_t* DB,int* len);
void rankSort(stu_t* DB,int* len);
stu_t stuLogin(stu_t* DB,int* len);
void stuInterface(stu_t st,stu_t* DB,int* len);
void seachScore(stu_t* DB,stu_t st,int* len);
void seachRank(stu_t* DB,stu_t st,int* len);
void updateScore(stu_t* DB,stu_t st,int* len);
#endif
