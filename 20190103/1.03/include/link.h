#ifndef LINK_H_
#define LINK_H_

/*链表结构的定义*/
typedef struct link{
	int 			data;			//值域
	struct link* 	next;			//后指针域
	struct link* 	prev;			//前指针域
}link_t;


/*创建链表*/
link_t* create_link(void);

/*添加节点*/
void insert_link(link_t* head, int _data);

/*遍历链表*/
void display_link(link_t* head);

/*释放所有节点*/
void free_link(link_t* head);

/*查找元素*/
link_t* find_link(link_t* head, int find_val);

/*删除元素*/
int delete_link(link_t* head, int delete_val);

/*对所有元素进行升序排序*/
void sort_link(link_t* head, link_t* start, link_t* end, int(*cmp)(int,int));
#endif
