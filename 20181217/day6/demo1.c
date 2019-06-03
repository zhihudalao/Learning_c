#include<stdio.h>
#define add 20
void func(){
	static int a=1;
	printf("%d\n",a);
	a++;
}

int main(int argc,char** argv){
	int i=0;
	for(i=0;i<5;i++){
		func();
	}
	return 0;
}
