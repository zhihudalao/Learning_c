#include<stdio.h>

int main(int argc,char** argv){
	char str[5];
	char str2[5];
	scanf("%s",str);
	while(getchar()!='\n');
	scanf("%s",str);
	while(getchar()!='\n');
	/*char str[6]={'h','e','l','l','o'};
	char str2[6]="world";*/
	/*for(int i=0;str[i]!='\0';i++){
		printf("%c",str[i]);
	}
	printf("\n");

	for(int i=0;i<5;i++){
		printf("%c",str2[i]);
	}
	printf("\n");*/
	printf("%s\n",str);
	//printf("%s\n",str2);
	return 0;
}
