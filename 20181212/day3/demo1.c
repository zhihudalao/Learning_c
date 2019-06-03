#include<stdio.h>
#include <stdlib.h>
#include<time.h>
/*
有一个整型数12345，将他逆序后赋值给一个变量，然后将他输出
*/

int main(int argc,char** argv){
	srand(time(0));
	int a=rand()%100;
	int b=rand()%100;
	int c=rand()%100;
	int d=rand()%100;
	printf("中间号码为:%d-%d-%d-%d\n",a,b,c,d);
	int _a=0,_b=0,_c=0,_d=0;
	printf("请输入要购买的彩票的4个号码:");
	scanf("%d %d %d %d",&_a,&_b,&_c,&_d);
	while(getchar()!='\n');
	printf("选定的号码为:%d-%d-%d-%d\n",_a,_b,_c,_d);
	if(a==_a&&b==_b&&c==_c&&d==_d){
		printf("恭喜中了特等奖!\n");
	}else if((a==_a&&b==_b&&c==_c&&d!=_d)||(a==_a&&b==_b&&c!=_c&&d==_d)||(a==_a&&b!=_b&&c==_c&&d==_d)||(a!=_a&&b==_b&&c==_c&&d==_d)){
		printf("恭喜中了一等奖!\n");
	}else if((a==_a&&b==_b&&c!=_c&&d!=_d)||(a==_a&&b!=_b&&c==_c&&d!=_d)||(a!=_a&&b==_b&&c==_c&&d!=_d)||(a==_a&&b!=_b&&c!=_c&&d==_d)||(a!=_a&&b==_b&&c!=_c&&d==_d)||(a!=_a&&b!=_b&&c==_c&&d==_d)){
		printf("恭喜中了二等奖!\n");
	}else{
		printf("抱歉，您没有中奖\n");
	}
	return 0;
}
