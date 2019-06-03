#include<stdio.h>

int ifNo(int num){
	int res=0;
	int i=0;
	for(i=num;i!=0;i/=10){//12345
		res=res*10+i%10;
	}
	if(res==num){
		return res;
	}
	return -1;
}


int main(void){
	int num=0;
	scanf("%d",&num);
	int res=ifNo(num);
	if(res!=-1){
		printf("%d是一个回文数\n",res);
	}else{
		printf("%d不是回文数\n",num);
	}
	return 0;
}

