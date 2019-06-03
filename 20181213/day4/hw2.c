#include<stdio.h>


int main(int argc,char** argv){
	char ch='\0';
	printf("请输入一个英文单词:");
	scanf("%c",&ch);
	while(getchar()!='\n');
	if(ch=='T' || ch=='t' || ch=='S' || ch=='s'){
		char _ch='\0';
		printf("请再输入一个英文单词:");
		scanf("%c",&_ch);
		if(ch=='T' || ch=='t'){
			switch(_ch){
				case 'h':
					printf("礼拜四\n");
					break;
				case 'u':
					printf("礼拜二\n");
					break;
				default:
					printf("输入错误\n");
					break;	
			}
		}else{
			switch(_ch){
				case 'u':
					printf("礼拜天\n");
					break;
				case 'a':
					printf("礼拜六\n");
					break;
				default:
					printf("输入错误\n");
					break;	
			}
		}
	}else{
		switch(ch){
			case 'M':
				printf("礼拜一\n");
				break;
			case 'm':
				printf("礼拜一\n");
				break;
			case 'W':
				printf("礼拜三\n");
				break;
			case 'w':
				printf("礼拜三\n");
				break;
			case 'F':
				printf("礼拜五\n");
				break;
			case 'f':
				printf("礼拜五\n");
				break;
		}
	}
	return 0;
}
