#include<stdio.h>

int func(int n){
	if(n<=1){
		return 1;
	}
	/*func(n)=*/return func(n-1)+n;
}

double fun(double n){
	if(n<=1){
		return 1;
	}
	/*fun(n)=*/return fun(n-1)+1/n;
}

int main(int argc,char** argv){;

	return 0;
}
