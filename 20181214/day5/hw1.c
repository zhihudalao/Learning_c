#include<stdio.h>

int main(int argc,char** argv){

	int n=0;
	int res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		res=0;//这里是重要点
		for(int j=1;j<i;j++){
			if(i%j==0){
				res=res+j;
			}
		}
		if(res==i){
			printf("%d ",i);
		}
	}
	printf("\n");

	
	return 0;
}
