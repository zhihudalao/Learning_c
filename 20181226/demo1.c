#include<stdio.h>
#include<string.h>
/*今天作业：使用结构体数组完成学生管理系统
要求①管理员能够添加学生，学生结构体含有属性，姓名，ID（要求自增），学生登录时的密码，语数外成绩
      ②学生能够将自己的id作为账号，管理员给定的初始密码登录，登录完成后可以查看自己的三科成绩及排名，并且可以修改自己的登录密码
     ③管理员可以修改学生成绩，按总成绩对学生排名，可以查找单个学生*/
int volme=1024;
int pos=0;//数组下标
typedef struct Stu{
  char name[20];
  char pswd[20];
  int id;
  int chinese;
  int math;
  int english;
}stu_t;//创建结构体

/*
函数名称：insertStu
函数功能：管理员添加学生
函数返回值：将数组内有多少学生返回外部
*/
int insertStu(stu_t* stuDB){
  static int id=180701;
  int flag=0;
  printf("请输入姓名\n");
  scanf("%s",stuDB[pos].name);
  while(getchar()!='\n');
  printf("请输入密码\n");
  scanf("%s",stuDB[pos].pswd);
  while(getchar()!='\n');
  printf("请输入语文成绩\n");
  scanf("%d",&stuDB[pos].chinese);
  while(getchar()!='\n');
  printf("请输入数学成绩\n");
  scanf("%d",&stuDB[pos].math);
  while(getchar()!='\n');
  printf("请输入英语成绩\n");
  scanf("%d",&stuDB[pos].english);
  while(getchar()!='\n');
  stuDB[pos].id=id;
  id++;
  pos++;
  return pos;
}
/*
函数名称：printStu
函数功能：管理员打印学生
函数返回值：无
*/
void printStu(stu_t* stuDB,int len){
  int i=0;
  for(i=0;i<len;i++){
    printf("**************************************************\n");
    printf("排名: %d\n姓名: %s\n密码: %s\n学号: %d\n语文: %d\n数学: %d\n英语: %d\n",
    i+1,stuDB[i].name,stuDB[i].pswd,stuDB[i].id,stuDB[i].chinese,stuDB[i].math,
  stuDB[i].english );
  }
}
/*
函数名称：findStu
函数功能：管理员输入id找到学生
函数返回值：将找到的学生坐在数组中的下标位置返回外部
*/
int findStu(stu_t*stuDB,int len ){
  int id_=0;
  int i=0;
  printf("请输入学生ID\n");
  scanf("%d",&id_);
  while(getchar()!='\n');
  for(i=0;i<len;i++){
    if(stuDB[i].id==id_){
      return i;
    }
  }
  printf("该学生不存在\n");
  return -1;
}
/*
函数名称：findidStu
函数功能：管理员输入id找到学生
函数返回值：wu
*/
void findidStu(stu_t*stuDB,int len){
  int i;
  i=findStu(stuDB,len);
  if(i!=-1){
  printf("**************************************************\n");
  printf("排名: %d\n姓名: %s\n密码: %s\n学号: %d\n语文: %d\n数学: %d\n英语: %d\n",
  i+1,stuDB[i].name,stuDB[i].pswd,stuDB[i].id,stuDB[i].chinese,stuDB[i].math,
stuDB[i].english );
}
}
/*
函数名称：updateStu
函数功能：管理员输入id找到学生,找到后修改学生信息
函数返回值：修改成功返回1,反之-1
*/
int updateStu(stu_t* stuDB,int len){
  int res=findStu(stuDB,len);
  if(res==-1){
    return -1;
  }
  printf("请输入语文成绩\n");
  scanf("%d",&stuDB[res].chinese);
  while(getchar()!='\n');
  printf("请输入数学成绩\n");
  scanf("%d",&stuDB[res].math);
  while(getchar()!='\n');
  printf("请输入英语成绩\n");
  scanf("%d",&stuDB[res].english);
  while(getchar()!='\n');
}
/*
函数名称：removeStu
函数功能：管理员输入id找到学生,找到后删除学生信息
函数返回值：修改成功返回1,反之-1
*/
int removeStu(stu_t*stuDB,int len ){
  int res=findStu(stuDB,len);
  if(res==-1){return -1;}
  int i=0;
  for(i=res;i<len-1;i++){
    stuDB[i]=stuDB[i+1];
  }
  stu_t temp={0,0,0,0,0,0};
  stuDB[i]=temp;
  pos--;
  printStu(stuDB,pos);
  return pos;

}
/*
函数名称：stuSort
函数功能：管理员对学生排序，输出排名
函数返回值：无
*/
void stuSort(stu_t*stuDB,int len){
  stu_t temp;
  for(int i=0;i<len;i++){
    for(int j=0;j<len-1;j++){
      if((stuDB[j].chinese)<(stuDB[j+1].chinese)){
        temp=stuDB[j];
        stuDB[j]=stuDB[j+1];
        stuDB[j+1]=temp;
      }
    }
  }
  printStu(stuDB,len);
}
/*
函数名称：ifname
函数功能：判断登陆id是否正确
函数返回值：正确1反之-1
*/
int ifname(stu_t*stuDB,int len,int name){
  for(int i=0;i<len;i++){
    if(stuDB[i].id==name){
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
  int name=0;
  int res=0;
  int res1=0;
  char pswd[20];
  printf("请输入账号\n");
  scanf("%d",&name);
  res=ifname(stuDB,len,name);
  if(res==-1){return;}
  printf("请输入密码\n");
  scanf("%s",pswd);
  res1=ifpswd(stuDB,len,pswd);
  if(res1==-1){return;}
  findidStu(stuDB,len);

}
/*
函数名称：updatepswd
函数功能：学生修改密码
函数返回值：无
*/
int updatepswd(stu_t*stuDB,int len){
  int res;
  res=findStu(stuDB,len);
  printf("请输入修改后的密码\n");
  scanf("%s",stuDB[res].pswd);

}
int main(int argc,char**argv){
  stu_t stuDB[volme];
  int choice=1;
	int len=0;
	while(choice){
		printf("**************************************************\n");
		printf("1:管理员添加学生\n");
		printf("2:管理员查看所有学生信息\n");
    printf("3:管理员查看一个学生信息\n");
    printf("4:管理员修改一个学生信息\n");
    printf("5:管理员删除一个学生信息\n");
    printf("6:管理员排序排名输出\n");
    printf("7:学生登陆\n");
    printf("8:学生修改密码\n");
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
        findidStu(stuDB,len);
        break;
      case 4:
        updateStu(stuDB,len);
        break;
      case 5:
        len=removeStu(stuDB,len);
        break;
      case 6:
        stuSort(stuDB,len);
        break;
      case 7:
        login(stuDB,len);
        break;
      case 8:
        updatepswd(stuDB,len);
        break;

			default:
				break;
		}
	}
	return 0;
}
