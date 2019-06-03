#include<stdio.h>
#include<string.h>
/*用户输入一行字符串，统计此字符串中每一个小写字母出现的次数
input a string: abckckchcAD  a:1  b:1  c:4  h:1  k:2*/
void main()
{
    char str[20];
    int i,num[256]={0};
    printf("please input string:");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
        num[(int)str[i]]++;
    for(i=0;i<256;i++)
        if(num[i]!=0)
            printf("%c:%d次\n",(char)i,num[i]);
}
