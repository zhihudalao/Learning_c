#include<stdio.h>

int main(int argc,char** argv){
	int arr[4][3]={
			{1,2,3},
			{4,5,6},
			{7,8,9},
			{0,1,2}
		};
	int i=0,j=0;
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
