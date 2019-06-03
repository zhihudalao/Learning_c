#include<stdio.h>


int main(int argc,char** argv){
	int arr_1[5]={0};
	int arr_2[5]={1,2,3,4,5};
	/*for(int i=0;i<5;i++){
		printf("%d ",arr_2[i]);
	}
	printf("\n");*/
	//arr_1=arr_2; 
	//练习题：打印arr_1,出现结果为1 2 3 4 5
	for(int i=0;i<5;i++){
		arr_1[i]=arr_2[i];
		printf("%d\n ",arr_1[i]);
	}
	printf("\n");

	return 0;
}
