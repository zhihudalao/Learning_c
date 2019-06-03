#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*假定系统中存在一个账号name=1234,密码password=4321
通过封装函数的方法，实现一个简单登录系统
要求：账号验证无次数限制，密码验证5次错误则直接退出程序，错误2次以上，要求输入验证码，验证码随机生成。当账号密码/验证码都正确的时候，提示登录成功即可
附加要求：密码输入时，隐藏密码。*/
int mat(int _name,int _password){
  int name=1234;
  int password=4321;
  if(_name==name&&_password==password){
  return 0;
  } else if(_name==name&&_password!=password){
  return 1;
  } else if(_name!=name){
  return 2;
  }
}
int code(int a){
  srand(time(0));
  int b=rand()%100;
  printf("%d\n",b);
  printf("please input code\n");
  scanf("%d",&a);
  if(a==b){
    return 0;
  }else{return 1;}
}
int main(int argc,char**argv){
  int flag,i,j;
  int name=0;
  int password=0;
  int _flag=0;
  int a;
  while(1){
    printf("please input name\n");
    scanf("%d",&name);
    while(getchar()!='\n');
    flag=mat(name,password);
    if(flag==2){
      printf("Please re-enter your name\n");
    }else{
      printf("please input password\n");
      scanf("%d",&password);
      if(flag==0){
        printf("land successfully\n");
        return 0;
      }else{
      for(i=0;i<5;i++){
        for(j=0;j<2;j++){
          if(flag==1){
            printf("Please re-enter your password\n");
            scanf("%d",&password);
            flag=mat(name,password);
          }
          printf("please input code\n");
          _flag=code(a);
          if(_flag==0){
            printf("code is right\n");
            printf("Please re-enter your password\n");
            scanf("%d",&password);
            flag=mat(name,password);
            if(flag==0){
              printf("land successfully\n");
              return 0;
          }
        }
      }
      }
    }
  }
}
  return 0;
}
