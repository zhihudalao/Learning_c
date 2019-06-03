#include<stdio.h>

int main(int argc,char** argv){
	int choice=0;
	printf("请输入选项:");
	scanf("%d",&choice);
	while(getchar()!='\n');
	switch(choice){
		case 1:{
			int x=0;
			printf("一\n");
			break;}
		case 2:
			printf("二\n");
			break;
		default:
			printf("零\n");
			break;
	}
	return 0;
}

