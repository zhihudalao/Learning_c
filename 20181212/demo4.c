#include<stdio.h>

int main(int argc,char** argv){
	int a=31,b=4;//11111
	printf("%d\n",a&b);
	printf("%d\n",a|b);
	printf("%d\n",~b);
	printf("%d\n",a^b);
	printf("%d\n",a<<b);
	printf("%d\n",a&=~(1<<2));//
	printf("%d\n",~(1<<2));//11011
	printf("%d\n",1<<2);

	
	
	
	
return 0;	
}
