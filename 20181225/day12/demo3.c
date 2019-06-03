#include<stdio.h>

enum type{
	TYPE_REGIST,
	TYPE_LOGIN,
	TYPE_CHAT
};

/*typedef struct stu{
	int a;
	int b;
	int c;
}stu_t;*/

typedef union stu{
	int a;
	int b;
	int c;
}stu_t;

int main(void){
	/*stu_t st;
	st.a=1;
	printf("%d\n",st.a);
	st.b=2;
	printf("%d %d\n",st.a,st.b);
	st.c=3;
	printf("%d %d %d\n",st.a,st.b,st.c);
	printf("size of stu_t:%lu\n",sizeof(stu_t));*/
	printf("%d\n",TYPE_REGIST);
	return 0;
}
