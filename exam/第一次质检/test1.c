#include<stdio.h>


int main(int argc,char** argv){
	char a=0;
	char b=a+1;
	int max=0,min=0;
	while(1){
		if(a>b){
			break;
		}
		a++;
		b++;
		max++;
	}
	a=0;
	b=a-1;
	while(1){
		if(a<b){
			break;
		}
		a--;
		b--;
		min--;
	}
	printf("%d %d",max,min);
	return 0;
}
