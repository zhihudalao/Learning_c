#include<stdio.h>
#define N 6
#define P 6
/*程序内有int型数组，分别叫nameDB和pswdDB，他们分别用来保存账号和密码信息。
	现在要求，编写一个注册登录功能，注册时，输入账号密码，保存到2个DB中去。注意需要有防重复注册功能。
	登录要求验证账号存在，密码正确即可*/
int signin(int* nameDB,int* pswdDB){
  printf("Please enter your registration account\n");
  int name;
  scanf("%d",&name);
  
  printf("Please enter your registration password\n");
  for(int i=0;i<P;i++){
    scanf("%d",&pswdDB[i]);
  }
}
int verify(int* nameDB,int* pswdDB){

}
int login(int* nameDB,int* pswdDB){

  printf("Please enter your login account\n");
}
int choice(int* nameDB,int* pswdDB){
  int ch=0;
  printf("please input your choice\n");
  printf("1.log in\n");
  printf("2.sign in\n");
  scanf("%d",&ch);
  switch (ch) {
    case 1:signin(nameDB,pswdDB);
    break;
    case 2:login(nameDB,pswdDB);
    break;
    default:printf("reselect\n");
    break;
  }
}
int main(int argc,char**argv){
  int nameDB[512]={0};
  int pswdDB[512]={0};
  choice(nameDB,pswdDB);
  return 0;
}
