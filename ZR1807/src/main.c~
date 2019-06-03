#include "FruitLink.h"
#include "controller.h"

int main(void)
{
	//创建链表
	Fruit* head = create_link();
	
	//加载
	load_fruits(head);
	
	fruit_control(head);
	
	//保存
	save_fruits(head);
	
	//销毁所有节点
	free_link(head);

	return 0;
}
