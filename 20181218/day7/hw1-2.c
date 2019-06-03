#include<stdio.h>

void arrIn(int* arr,int len){
	int i=0;
	for(i=0;i<len;i++){
		scanf("%d",&arr[i]);
	}
}

void arrOut(int* arr,int len){
	for(int i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int getPos(int* arr,int len,int n){
	int i=0;//循环变量
	for(i=0;i<len;i++){
		if(n==arr[i]){
			return i;
		}
	}
	return -1;
}

int removePos(int* arr,int len,int n){
	static int i=0;
	int pos=getPos(arr,len,n);
	int j=0;//循环变量
	if(pos==-1){
		return -1;
	}
	for(j=pos;j<len;j++){
		arr[j]=arr[j+1];
	}
	arr[j]=0;
	i++;

	return len-i;
}

void creatArr(int* tarArr,int* arr,int len){
	int i=0;
	for(i=0;i<len;i++){
		tarArr[i]=arr[i];
	}
}

int main(int argc,char** argv){
	int arr[5];
	arrIn(arr,5);
	int newLen=0;
	int mid=0;
	int n=0;
	printf("请输入目标数值:");
	scanf("%d",&n);
	while(getchar()!='\n');
	while(1){
		newLen=removePos(arr,5,n);
		if(newLen==-1){
			break;
		}
		mid=newLen;
	}
	if(mid<=0){mid=5;}
	int newArr[mid];
	creatArr(newArr,arr,mid);
	//arrOut(arr,5);
	arrOut(newArr,mid);
	return 0;
}
















