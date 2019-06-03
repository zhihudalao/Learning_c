#include<stdio.h>

int main(int argc,char** argv){
	FILE* fp=fopen("./text.txt","r");
	int arr[7]={0};
	int i=0;
	int res=0;
	while(EOF!=fscanf(fp,"%d",&arr[i])){
		
		printf("res=%d\n",res);
		i++;
		//if(res!=1){break;}
	}
	fclose(fp);
	for(i=0;i<8;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
