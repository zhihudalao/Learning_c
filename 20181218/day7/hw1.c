#include<stdio.h>

int main(int argc,char** argv){
	int pos=0;
	printf("请输入这个数组的长度:");
	scanf("%d",&pos);
	while(getchar()!='\n');
	int arr1[pos];
	printf("请输入这个数组中的%d个元素:\n",pos);
	for(int i=0;i<pos;i++){
		scanf("%d",&arr1[i]);
		while(getchar()!='\n');
	}
	printf("请输入需要删除的元素:");
	int target=0;
	scanf("%d",&target);
	while(getchar()!='\n');
	int flag=0;
	int j=0;
	for(j=0;j<pos;j++){
		if(target==arr1[j]){
			flag=1;
			break;
		}
	}
	int pos2=pos-1;
	int arr2[pos2];
	if(flag==1){
		int k=0;
		for(k=j;k<pos-1;k++){
			arr1[k]=arr1[k+1];
		}
		arr1[k]=0;
		for(int i=0;i<pos2;i++){
			arr2[i]=arr1[i];
		}
	}else{
		printf("元素不存在\n");
	}
	for(int i=0;i<pos2;i++){
		printf("%d ",arr2[i]);
	}
	printf("\n");
	return 0;
}
/*
以上例题，封装函数去完成，需要添加一个功能，查找到多个符合的元素，需要将他们一并删除。
*/



















