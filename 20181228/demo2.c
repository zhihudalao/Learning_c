#include<stdio.h>
#include<string.h>
/*练习题:完成一个注册登录功能，要求：
	①需要防重复注册功能
	②登录时，验证账号是否存在，验证密码是否正确，2次不正确输入验证码,5次不正确退出程序.*/
int volme=1024;
typedef struct Stu{
  char name[20];
  char pswd[20];
}stu_t;
int pos=0;
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
  int flag=0;
  scanf("%s",stuDB[pos].name);
  while(getchar()!='\n');
  flag=verify(stuDB,pos);
  if(flag==1){
  scanf("%s",stuDB[pos].pswd);
  while(getchar()!='\n');
  pos++;
  return pos;
  }else{
    return pos;
  }
}
void printStu(stu_t* stuDB,int len){
  int i=0;
  for(i=0;i<len;i++){
    printf("姓名：%s\n密码：%s\n",
    stuDB[i].name,stuDB[i].pswd);
  }
}
int ifname(stu_t*stuDB,int len,char* name){
  for(int i=0;i<len;i++){
    if(strcmp(stuDB[i].name,name)==0){
      return 1;
    }
  }
  printf("账号不存在\n");
  return -1;
}
/*
函数名称：ifpswd
函数功能：判断登陆pswd是否正确
函数返回值：正确1反之-1
*/
int ifpswd(stu_t*stuDB,int len,char* pswd){
  for(int i=0;i<len;i++){
    if(strcmp(stuDB[i].pswd,pswd)==0){
      return 1;
    }
  }
  printf("密码错误\n");
  return -1;
}
/*
函数名称：login
函数功能：学生登陆
函数返回值：无
*/
void login(stu_t*stuDB,int len){
  char name[20];
  int res=0;
  int res1=0;
  char pswd[20];
  printf("请输入账号\n");
  scanf("%s",name);
  res=ifname(stuDB,len,name);
  if(res==-1){return;}
  printf("请输入密码\n");
  scanf("%s",pswd);
  res1=ifpswd(stuDB,len,pswd);
  if(res1==-1){return;}
  printf("登陆成功\n");

}
int main(int argc,char**argv){
  stu_t stuDB[volme];
  FILE*fp=fopen("./login.txt","r");
  int i=0;
  while(!feof(fp)){
    fscanf(fp,"%s",stuDB[i].name);
    fscanf(fp,"%s",stuDB[i].pswd);
    i++;
  }
  fclose(fp);
  int choice=1;
	int len=i;
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
				len=insertStu(stuDB)+i;//使用len接受当前数组中有多少个元素，然后传入print函数中去，保证遍历次数的正确
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
  FILE*fpp=fopen("./login.txt","a");
  for(int i;i<pos+1;i++){
      fprintf(fpp, "%s\n",stuDB[i].name);
      fprintf(fpp, "%s\n",stuDB[i].pswd);
  }
  fclose(fp);
	return 0;
}
