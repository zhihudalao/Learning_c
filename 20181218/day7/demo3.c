#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int argc,char** argv){
/*
	系统随机生成4个中奖号码放入数组中，然后手动输入4个号码去匹配，
	特等奖：4个全中
	1等奖：中3
	2等奖：中2
*/
	srand(time(0));
	int count=0;
	int arr[4]={0};
	for(int i=0;i<4;i++){
		arr[i]=rand()%100;
		printf("%d ",arr[i]);
	}
	printf("\n");
	int _arr[4]={0};
	for(int i=0;i<4;i++){
		scanf("%d",&_arr[i]);
	}
	for(int i=0;i<4;i++){
		if(arr[i]==_arr[i]){
			count++;
		}
	}
	if(count==4){
		printf("特等奖！\n");
	}else if(count==3){
		printf("1等奖！\n");
	}else if(count==2){
		printf("2等奖！\n");
	}else{
		printf("没中奖\n");
	}
	return 0;
}
