#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void myQsort(int* arr,int left,int right){
	int l=left;
	int r=right;
	int key=arr[left];
	int mid=0;
	if(left>right){return ;}
	while(l<r){
		while(l!=r){
			if(arr[r]<key){
				break;
			}
			r--;
		}
		while(l!=r){
			if(arr[l]>key){
				break;
			}
			l++;
		}
		mid=arr[l];
		arr[l]=arr[r];
		arr[r]=mid;
	}
	//此时l和r在同一位置
	arr[left]=arr[l];
	arr[l]=key;
	myQsort(arr,left,l-1);//l和r都停在key值上
	myQsort(arr,l+1,right);
}

void bubbleSort(int* arr,int len){
	int i=0,j=0;
	for(i=0;i<len;i++){
		for(j=0;j<len-1;j++){
			if(arr[j]>arr[j+1]){
				arr[j]=arr[j]^arr[j+1];
				arr[j+1]=arr[j]^arr[j+1];
				arr[j]=arr[j]^arr[j+1];
			}
		}
	}
}

void selectSort(int* arr,int len){
	int i=0,j=0;
	int min=0;
	for(i=0;i<len;i++){
		min=i;
		for(j=i;j<len;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		if(arr[i]!=arr[min]){
			arr[i]=arr[i]^arr[min];
			arr[min]=arr[i]^arr[min];
			arr[i]=arr[i]^arr[min];
		}
	}
}	

int main(int argc,char** argv){
	srand(time(0));
	int len=100000;
	int i=0;
	int arr[len];
	for(i=0;i<len;i++){
		arr[i]=rand()%len;
	}
	myQsort(arr,0,len-1);
	//bubbleSort(arr,len);
	//selectSort(arr,len);
	for(i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
