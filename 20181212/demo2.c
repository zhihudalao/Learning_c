#include<stdio.h>

int main(int argc,char** argv){
	/*int choice=0;
	printf("请输入选项");
	scanf("%d",&choice);
	while(getchar()!='\n');
	switch(choice){
		case 1:
			{int x=0;
			printf("一\n");
			break;}
		case 2:
			printf("二\n");
			break;
		default:
			printf("0\n");
			break;		
		}*/
	int i=5,j=10;
	while(i<j){
			switch(i){
					case 5:
						i++;
						break;
					case 6:
						i+=3;
						j++;
						
					case 7:
						i--;
						break;
					default:
						i++;
						break;
					
				
			}
	}
	printf("i,j=%d,%d\n",i,j);
	

	return 0;	
}
