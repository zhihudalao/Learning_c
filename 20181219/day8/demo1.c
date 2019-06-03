#include<stdio.h>

void mySort(int* arr){
	int i=0;
	int j=0;
	for(i=0;i<5;i++){
		for(j=0;j<4;j++){
			if(arr[j]<arr[j+1]){
				arr[j]=arr[j]^arr[j+1];
				arr[j+1]=arr[j]^arr[j+1];
				arr[j]=arr[j]^arr[j+1];
			}
		}
	}
}

void selectSort(int* arr){
	int i=0;
	int j=0;
	int max=0;
	for(i=0;i<5;i++){
		max=i;
		for(j=i;j<5;j++){
			if(arr[max]<arr[j]){
				max=j;
			}
		}
		if(arr[i]!=arr[max]){
			arr[i]=arr[i]^arr[max];
			arr[max]=arr[i]^arr[max];
			arr[i]=arr[i]^arr[max];	
		}	
	}
}

void printArr(int* arr,int len){
	int i=0;
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


int main(int argc,char** argv){
	int arr[5]={2,1,4,5,3};
	selectSort(arr);
	printArr(arr,5);
	return 0;
}
