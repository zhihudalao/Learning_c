#include<stdio.h>
#include<time.h>
#include<stdlib.h>
/*现在有3个结构体，分别为战士，法师和怪物，
战士的属性为:血量，攻击力，防御力，速度和物理攻击
法师的属性为：血量，攻击力，防御力，速度和魔法攻击。
怪物的属性为：血量，攻击力，防御力和速度
要求1：
	设计一个程序，随机生成一个怪物，强度适中。区分战士和法师的攻击方式并提示用户。
	然后根据攻击力-防御=扣除血量的逻辑，进行战斗。
  战斗结束时，提示谁击杀了怪物，或者怪物击杀了谁。速度高的先打。（
  只需要战士和怪物战斗或者法师和怪物战斗，不需要战士+法师和怪物战斗）*/
typedef struct Warrior{
  int HP1;//生命值
  int ATK1;//攻击力
  int PHP1;//物理防御
  int SPE1;//速度
  int PHA1;//物理攻击
}Wa;
typedef struct Mage{
  int HP2;//生命值
  int ATK2;//攻击力
  int PHP2;//物理防御
  int SPE2;//速度
  int MAA2;//魔法攻击
}Ma;
typedef struct Monster{
  int HP3;//生命值
  int ATK3;//攻击力
  int PHP3;//物理防御
  int SPE3;//速度
}Mo;
int main(int argc,char**argv){
  srand(time(0));
  Mo mo[512];
  Wa wa[512];
  Ma ma[512];
  mo[1].HP3=rand()%50;
  mo[1].ATK3=rand()%50;
  mo[1].PHP3=rand()%50;
  mo[1].SPE3=rand()%50;
  printf("Hp:%d\nATK:%d\nPHP:%d\nSPE:%d\n",
  mo[1].HP3,mo[1].ATK3,mo[1].PHP3,mo[1].SPE3);
  wa[1].HP1=100;
  wa[1].ATK1=100;
  wa[1].PHP1=100;
  Wa[1].SPE1=100;
  wa[1].PHA1=100;
  printf("HP:%d\nATK:%d\nPHP:%d\nSPE:%d\n", );
  return 0;
}
