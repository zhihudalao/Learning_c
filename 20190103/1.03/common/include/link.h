#ifndef LINK_H_
#define LINK_H_

/*通用链表结构的定义*/
typedef struct link{
	void*			data;			//值域
	struct link* 	next;			//后指针域
	struct link* 	prev;			//前指针域
	int 			size;			//定义值域的大小
}link_t;


/*创建链表*/
link_t* create_link(int size);

/*添加节点*/
void insert_link(link_t* head, void* _data);

/*遍历链表*/
void display_link(link_t* head, void(*print)(const void*));



/*释放所有节点*/
void free_link(link_t* head);

/*查找元素*/
link_t* find_link(link_t* head, const void* data, 
							int(*cmp)(const void*, const void*));

/*删除元素*/
int delete_link(link_t* head, const void* data, 
							int (*cmp)(const void*, const void*));

/*对所有元素进行升序排序*/
void sort_link(link_t* head, link_t* start, link_t* end, 
		int(*cmp)(const void*,const void*));
#endif
