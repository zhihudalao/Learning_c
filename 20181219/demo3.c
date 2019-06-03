#include<stdio.h>
#define nameDB 4321
#define pswdDB 1234
/*编写一个简单的学生管理系统，要求：
	1）系统内置管理员账号密码，登录即可
	2）管理员能够添加学生信息，学生的信息必须要有①学生的学号②数学和语文成绩
	3）管理员能够对学生进行排序（根据任意成绩或者总成绩），添加（增加学生），删除学生，修改学生成绩*/
int ifname(int name){
  		if(name==nameDB){
  			return 1;
  		}
  	return -1;
  }
int ifPswd(int pswd){
  	if(pswd==pswdDB){
  		return 1;
  	}
  	return -1;
  }
int  login(){
  	int name=0,pswd=0;
    while(1){
  	printf("请输入账号:");
  	scanf("%d",&name);
  	while(getchar()!='\n');
  	int res=ifname(name);
  	if(res==-1){
  		printf("账号不存在\n");
  	}else{break;}
  }
    while(1){
  	printf("请输入密码:");
  	scanf("%d",&pswd);
  	while(getchar()!='\n');
  	int res2=ifPswd(pswd);
  	if(res2==1){
  		printf("登录成功\n");
      return 1;
  	}else{
  		printf("密码错误,请重新登录\n");
  	}
  }
}
void check(int* studentId,int* mathgrade,int* chinesegrade,int studentID){

  int i;
  for(i=0;i<512;i++){
    if(studentID==studentId[i]);
    break;
  }
  printf("%d\n",studentId[i]);
  printf("%d\n",mathgrade[i]);
  printf("%d\n",chinesegrade[i]);
}
void add(int* studentId,int* mathgrade,int* chinesegrade){

}
void delete(int* studentId,int* mathgrade,int* chinesegrade){

}
void change(int* studentId,int* mathgrade,int* chinesegrade){

}
void sort(int* studentId,int* mathgrade,int* chinesegrade){

}
void choice(int* studentId,int* mathgrade,int* chinesegrade){
  while(1){
    int studentID;
    printf("please input your choice\n");
    printf("1.check\n");
    printf("2.add\n");
    printf("3.delete\n");
    printf("4.change\n");
    printf("5.sort\n");
    printf("6.quit\n");
    int ch=0;
    scanf("%d",&ch);
    switch (ch) {
      case 1:
      printf("please input studentId\n");
      scanf("%d",&studentID);
      check(studentId,mathgrade,chinesegrade,studentID);
      break;
      case 2:
      add(studentId,mathgrade,chinesegrade);
      break;
      case 3:
      delete(studentId,mathgrade,chinesegrade);
      break;
      case 4:
      change(studentId,mathgrade,chinesegrade);
      break;
      case 5:
      sort(studentId,mathgrade,chinesegrade);
      break;
      default:
      return ;
    }
  }
}
int main(int argc,char**argv){
  int studentId[512]={0};
  int mathgrade[512]={0};
  int chinesegrade[512]={0};
  login();
  choice(studentId,mathgrade,chinesegrade);
  return 0;
}
