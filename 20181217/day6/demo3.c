#include<stdio.h>

int func(int a){
	if(a<=0){
		return 0;
	}
	func();
	return 0;
}

int main(int argc,char** argv){
	int a=10;
	func(a);
	return 0;
}
