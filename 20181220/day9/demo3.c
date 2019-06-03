#include<stdio.h>

void add(char** dataBase){

}

int main(int argc,char** argv){
	char name[50]="zhangsan";//数组name的名字就是一个地址，类型就是char*
	char* dataBase[512]={NULL};
	for(int i=0;i<512;i++){
		char newName[50]={'\0'}
		dataBase[i]=newName;
	}
	return 0;
}
