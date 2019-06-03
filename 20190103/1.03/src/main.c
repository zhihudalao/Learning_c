#include "link.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <math.h>

int cmp(int x, int y)
{
	return y - x;
}

int main(void)
{
	srand(time(0));
	link_t* head = create_link();
	assert(head);

	int i = 0;
	for(i = 0; i < 10; i++){
		insert_link(head, rand() % 100 + 1);
	}

	display_link(head);
	sort_link(head, head->next, head->prev, cmp);

	display_link(head);
	
	free_link(head);
/*
	int find_val = 0;
	printf("请输入查找的数据: ");
	scanf("%d", &find_val);
	link_t* f_p  = find_link(head, find_val);
	if(NULL == f_p){
		printf("链表中没有这个元素\n");
	}else{
		printf("找到该元素：%d\n", f_p->data);

		char choice = '\0';
		printf("是否需要删除该元素?y/n");
		scanf(" %c", &choice);
		if(choice == 'y' || choice == 'Y'){
			//删除找到的元素 0 成功 1 失败
			int ret = delete_link(head, find_val);
			if(!ret){
				printf("删除成功\n");
			}else{
				printf("删除失败\n");
			}
		}
	}
	*/

	return 0;
}
