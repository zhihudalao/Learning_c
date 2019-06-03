#ifndef FRUIT_FUNC_H_
#define FRUIT_FUNC_H_
#include "FruitLink.h"

/*
	功能：添加一个水果信息到链表中
	参数：head 链表头节点
	返回值：0 成功 1 失败
*/
int insert_fruit(Fruit* head);

/*
	功能：删除一个水果从链表中
	参数：head 链表头节点
	返回值：0 成功 1 失败
*/
int delete_fruit(Fruit* head);

#endif
