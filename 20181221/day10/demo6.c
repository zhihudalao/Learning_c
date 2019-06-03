#include<stdio.h>
#include<string.h>

void myStrcat(char* str1,char* str2){
	int i=0;
	for(i=0;*(str1+i)!='\0';i++){}
	//i已经停在结束符上，意味着i是str1的真实长度
	for(int j=0;*(str2+j)!='\0';j++){
		*(str1+i)=*(str2+j);
		i++;
	}
	return ;
}

char* myStrcat1(char* str1,char* str2){
	int i=0,j=0;
	for(i=0;str1[i]!='\0';i++){}
	for(j=0;str2[j]!='\0';j++){}
	int newStr[i+j];
	//然后就是先将str1的内容赋值进去，再将str2的内容赋值进去，最后返回newStr
	return newStr;//这里是错误的，栈空间指针不能返回，只能返回堆空间的指针
}

int main(int argc,char** argv){
	char str1[512]="hello";
	char str2[512]="world";
	/*memcpy(str1+5,str2,6);//memcpy(str1,str2,n),这个函数会将str2中的n个字节上的内容，覆盖到str1上去。
	//helloworld\0
	printf("%s\n",str1);*/
	myStrcat(str1,str2);
	printf("%s\n",str1);
	return 0;
}
