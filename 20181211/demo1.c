#include<stdio.h>
#include<ctype.h>
#include<math.h>
int main(void){
	/*int a=0;
	short b=0;
	long c=0;
	printf("int:  %lu\n",sizeof(int) );
	printf("short:  %lu\n",sizeof(short) );
	printf("long:  %lu\n",sizeof(long));
	char d='9';
	int e=9;
	printf("%d\n",(d-'0')==e);	*/

	/*char a=getchar();
	if(a>=48&&a<=57){printf("0\n");
	}else if(a>=97&&a<=122){printf("%c\n",a-32 );
	}else if(a>=65&&a<=90){printf("%c\n",a+32 );
	}else {printf("1\n");}*/
	/*int a=110;
	printf("a=%d\n",a );
	printf("a at    %p\n",&a );
	printf("a+1 at  %p\n",&a+1 );
	double b=5.2;
	printf("%d\n",a%(int)b );
	printf("%d\n",++a);
	printf("%d\n",2%5);*/

	/*int a=2,b=5;
	a+=a%b+b+++a++;
	b+=a+++b+++b/a ;
	printf("c:%d\n",a);
	printf("d:%d\n",b );*/
	int a,b,c,area;
	scanf("%d%d%d",&a,&b,&c);
	printf("a:%d b:%d c:%d\n",a,b,c );
	if(a+b<=c||b+c<=a||a+c<=b){
		printf("error\n");
	}
	else if(a==b==c){
		printf("dengbian\n");
		}
	else if(a==b||b==c||a==c){
		printf("dengyao\n");
		}
	else if(c==sqrt(a*a+b*b)||a==sqrt(b*b+c*c)||b==sqrt(a*a+c*c)){
		printf("zhijiao\n");
	}
	else {printf("common\n");}
	

	return 0;
}