#include<stdio.h>
#include<string.h>

int myStrlen(char* str){
	int count=0;
	for(int i=0;str[i]!='\0';i++){
		count++;
	}
	return count+1;
}

void myStrcpy(char* str1,char* str2){
	int i=0;
	for(i=0;str1[i]!='\0';i++){
		str1[i]='\0';
	}
	for(i=0;str2[i]!='\0';i++){
		str1[i]=str2[i];
	}

}

int myStrcmp(char* str1,char* str2){
	int i=0;
	for(i=0;str1[i]!='\0' || str2[i]!='\0';i++){
		if(str1[i]!=str2[i]){
			return str1[i]-str2[i];
		}
	}
	return 0;
}

char* myStrcat(char* str1,char* str2){
	int i=0;
	int j=0;
	for(i=0;*(str1+i)!='\0';i++){}
	while(1){
		if(*(str2+j)=='\0'){
			break;
		}
		*(str1+i)=*(str2+j);
		i++;
		j++;
	}
	return str1;
}

int main(int argc,char** argv){
	/*char str[512];	
	scanf("%s",str);
	printf("这个数组的长度为:%d\n",myStrlen(str));*/
	//strlen的功能为，测量传入数组的长度，注意，不会将结束符计算在内
	//strlen的实现思想：通过遍历整个数组，去寻找数组的结束符，当每一次循环没有找到结束符，则给先前申明的计数器+1，直到找到结束符，则返回计数器的值.
	char str1[11]="hello";
	char str2[11]="world";
	//strcpy(str1,str2);//将str2的内容赋值给str1
	/*memcpy(str1,str2,11);//将str2的内存上的内容依次覆盖到str1内存上，并且需要告诉覆盖多少个内容
	printf("%s\n",str1);*/
	//myStrcpy(str1,str2);
	myStrcat(str1,str2);
	printf("%s\n",str1);
	return 0;
}
/*
使用二维字符数组，完成一个注册功能，注意需要防重复注册。
就是说，我没注册一个账号（为字符串），就会将这个字符串保存到一个数组中去。该数组也叫字符串数组。

*/


















