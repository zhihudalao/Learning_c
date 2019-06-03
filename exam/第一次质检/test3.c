#include<stdio.h>

int myStrcmp(char* str1,char* str2){
	int i=0;
	for(i=0;str1[i]!='\0' || str2[i]!='\0';i++){
		if(str1[i]!=str2[i]){
			return str1[i]-str2[i];
		}
	}
	return str1[i]-str2[i];
}

int main(void){
	char str1[512];
	char str2[512];
	scanf("%s %s",str1,str2);
	while(getchar()!='\n');
	printf("%d\n",myStrcmp(str1,str2));
	return 0;
}
