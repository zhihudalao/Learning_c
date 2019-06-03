#include<stdio.h>

int main(int argc,char** argv){
	printf("%s\n",*(argv+1));
	printf("%c\n",*(*(argv+1)+1));
	return 0;
}
