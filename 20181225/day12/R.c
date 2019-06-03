#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Warrior{
	int hp;
	int atk;
	int def;
	int spd;
	int (*p)();
}War;

typedef struct Mage{
	int hp;
	int atk;
	int def;
	int spd;
	int (*p)();
}Mag;

typedef struct Monster{
	int hp;
	int atk;
	int def;
	int spd;
	int (*p)();
}Mon;

int DB[2]={0};

int battle(War war,Mon mon){
		int ch=0;
		//monster lv↑
		mon.hp+=10;
		mon.atk+=3;
		mon.def+=3;
		mon.spd+=2;
		//warrior lv↑
		war.spd+=1;
		printf("获得2点技能点");
		printf("1:+8 hp\n");
		printf("2:+3 atk\n");
		printf("3:+3 def\n");
		printf("4:+1 spd\n");
		printf("请输入您的选择:");
		for(int i=0;i<2;i++){
			scanf("%d",&ch);
			switch(ch){
				case 1:
					war.hp+=6;
					break;
				case 2:
					war.atk+=3;
					break;
				case 3:
					war.def+=3;
					break;
				case 4:
					war.spd+=1;
					break;
				default:
					break;
			}
		}
	
	if(war.spd>mon.spd){
		while(1){
			printf("英雄  攻击了   怪物\n");
			if(war.atk<mon.def){
			}else{mon.hp-=(war.atk-mon.def);}
			printf("怪物HP:%d\n",mon.hp);
			if(mon.hp<=0){
				return 1;
			}
			printf("怪物  攻击了   英雄\n");
			if(mon.atk<war.def){
			}else{war.hp-=(mon.atk-war.def);}
			printf("英雄HP:%d\n",war.hp);
			if(war.hp<=0){
				return -1;
			}
		}
	}else{
		while(1){
			
			printf("怪物  攻击了   英雄\n");
			if(mon.atk<war.def){
			}else{war.hp-=(mon.atk-war.def);}
			printf("英雄HP:%d\n",war.hp);
			if(war.hp<=0){
				return -1;
			}
			printf("英雄  攻击了   怪物\n");
			if(war.atk<mon.def){
			}else{mon.hp-=(war.atk-mon.def);}
			printf("怪物HP:%d\n",mon.hp);
			if(mon.hp<=0){
				printf("英雄HP:%d\n",war.hp);
				return 1;
			}

		}
	}
}

int main(int argc,char** argv){
	srand(time(0));
	War war={20,5,10,5,NULL};
	Mag mag={10,10,5,15,NULL};
	Mon mon;
	mon.hp=rand()%5+5;
	mon.atk=rand()%3+2;
	mon.def=rand()%2+2;
	mon.spd=rand()%10+5;
	int res=0;
	while(1){
		res=battle(war,mon);
		if(res==-1){break;}
		printf("怪物被击败");
	}
	
	return 0;
}

/*
现在有3个结构体，分别为战士，法师和怪物，战士的属性为血量，攻击力，防御力，速度和物理攻击
法师的属性为：血量，攻击力，防御力，速度和魔法攻击。
怪物的属性为：血量，攻击力，防御力和速度
要求1：
	设计一个程序，随机生成一个怪物，强度适中。区分战士和法师的攻击方式并提示用户。
	然后根据攻击力-防御=扣除血量的逻辑，进行战斗。战斗结束时，提示谁击杀了怪物，或者怪物击杀了谁。速度高的先打。（只需要战士和怪物战斗或者法师和怪物战斗，不需要战士+法师和怪物战斗）
要求2：
	设计一个通关系统。每通过一关，怪物强度增加，HP+6，其他所有属性+3。英雄则固定获得+1速度，并且获得2点技能点，选择分配技能点，一点技能点对应8点HP，3点ATK，3点DEF和1点spd。
*/
