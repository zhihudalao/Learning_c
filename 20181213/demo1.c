#include<stdio.h>
/*有一只猴子，第一天摘了一批桃子，然后吃掉一半，扔掉一个烂桃子，第二天，又吃掉剩余的一半，扔掉一个烂桃子，往复如此6天，在第六天发现，只剩1个桃子。问，这只猴子第一天摘了多少个桃子*/
int main(int argc,char** argv){
  int i=0,j=1;
  for(;i<6;i++){
    j=(j+1)*2;
  }
  printf("总共有%d个桃\n",j );
  return 0;
}
