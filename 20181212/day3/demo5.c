#include<stdio.h>

int main(int argc,char** argv){
	int i=5,j=10;
	while(i<j){
		switch(i){
			case 5:
				i++;
				break;
			case 6:
				i+=3;
				j++;
				break;
			case 7:
				i--;
				break;
			case 8:
				i+=2;
				break;
			case 9:
				i+=2;
				j+=1;
				break;
			default:
				i++;
				break;
		}
	}
	printf("i,j=%d,%d\n",i,j);
	return 0;
}
