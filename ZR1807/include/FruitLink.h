#ifndef FRUITLINK_H_
#define FRUITLINK_H_


struct fruit{
	char 	name[20];
	double 	price;
};

//链表节点的定义
typedef struct fruit_link{
	struct fruit		fruit;			//值域
	struct fruit_link* 	next;			//指针域
}Fruit;	



/*
	功能：创建水果链表的头节点
	参数：无
	返回值：返回头节点
*/
Fruit* create_link(void);

/*
	功能：添加一个新的节点到链表中
	参数：head 链表头节点 newNode 新节点的指针
	返回值 0 成功 1 失败
*/
int append_link(Fruit* head, Fruit* newNode);

/*
	功能：通过名字检测水果是否存在
	参数：head 头节点  name 要检测的名字
	返回值：0 成功 1 失败
*/
int find_fruit_by_name(Fruit* head, const char* name);



/*
	功能：删除一个节点
	参数：head 头节点  name 要删除的水果名
	返回值：0 成功 1 失败
*/
int remove_node(Fruit* head, const char* name);

//修改水果信息

/*
	功能：释放链表所有节点
	参数：head 头节点
	返回值：无
*/
void free_link(Fruit* head);

/*
	功能：打印所有水果信息
	参数：head 头节点
	返回值：无
*/
void display_link(Fruit*head);


/*
	功能：对链表的所有水果排序
	参数：head 头节点
	返回值：无
*/
void sort_fruit(Fruit* head);

//加载所有水果信息到内存中



/*
	功能：读取所有水果信息到内存中
	参数：head 头节点
	返回值：无
*/
void load_fruits(Fruit* head);

/*
	功能：将所有水果的信息保存到文件之中
	参数：head 头节点
	返回值：无
*/
void save_fruits(Fruit* head);


#endif
