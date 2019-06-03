#include "controller.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "view.h"
#include "FruitLink.h"
#include "fruit_func.h"

/*
	功能：水果界面的管理
	参数：head 头节点
	返回值：无
*/
void fruit_control(Fruit* head)
{
	int choice = 0;
	while(1){
		menu_fruit();
		scanf("%d", &choice);
		switch(choice){
			case 1:			//显示
				display_link(head);
				break;
			case 2:			//添加
				if(0 == insert_fruit(head)){
					printf("添加成功\n");
				}else{
					printf("添加失败\n");
				}
				break;
			case 3:			//删除
				if(0 == delete_fruit(head)){
					printf("删除成功\n");
				}else{
					printf("删除失败\n");
				}
				break;
			case 4:			//排序（价格）
				sort_fruit(head);
				break;
			case 0:			//排序（价格）
				return ;
			default:		//出错
				break;
				
		}
	}

}

