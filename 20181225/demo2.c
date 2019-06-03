#include<stdio.h>
#include<string.h>
/*练习题:完成一个注册登录功能，要求：
	①需要防重复注册功能
	②登录时，验证账号是否存在，验证密码是否正确，2次不正确输入验证码,5次不正确退出程序.*/
int volme=1024;
typedef struct Stu{
  char name[20];
  char pswd[20];
  int id;
  int score;
}stu_t;
int verify(stu_t* stuDB,int len){
  int i;
  for(i=0;i<len;i++){
    if(strcmp(stuDB[len].name,stuDB[i].name)==0){
      printf("账号已存在\n");
      printf("请重新输入\n");
      return -1;
    }
  }
  return 1;
}
int insertStu(stu_t* stuDB){
  static int pos=0;
  static int id=180701;
  int flag=0;
  scanf("%s",stuDB[pos].name);
  while(getchar()!='\n');
  flag=verify(stuDB,pos);
  if(flag==1){
  scanf("%s",stuDB[pos].pswd);
  while(getchar()!='\n');
  scanf("%d",&stuDB[pos].score);
  while(getchar()!='\n');
  stuDB[pos].id=id;
  id++;
  pos++;
  return pos;
}else{return pos;}
}
void printStu(stu_t* stuDB,int len){
  int i=0;
  for(i=0;i<len;i++){
    printf("姓名：%s\n密码：%s\n学号：%d\n分数：%d\n",
    stuDB[i].name,stuDB[i].pswd,stuDB[i].id,stuDB[i].score );
  }
}
void login(stu_t*stuDB,int len){
  char name[20];
  int i,pswd;
  printf("请输入账号\n");
  scanf("%s",name);
  while(1){
    for(i=0;i<len+1;i++){
        if(*name==*stuDB[i].name){

        }
    }
  }
}
int main(int argc,char**argv){
  stu_t stuDB[volme];
  int choice=1;
	int len=0;
	while(choice){
		printf("*********************\n");
		printf("1:添加学生\n");
		printf("2:查看所有学生信息\n");
    printf("3:登陆\n");
		printf("0:退出\n");
		printf("请输入要执行的操作:");
		scanf("%d",&choice);
		while(getchar()!='\n');
		switch(choice){
			case 1:
				len=insertStu(stuDB);//使用len接受当前数组中有多少个元素，然后传入print函数中去，保证遍历次数的正确
				break;
			case 2:
				printStu(stuDB,len);
				break;
      case 3:
        login(stuDB,len);
        break;
			default:
				break;
		}
	}
	return 0;
}
