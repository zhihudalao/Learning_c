#include "link.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <math.h>

typedef struct fruit{
	int 	id;
	char 	name[20];
	double 	price;
}fruit_t;

void print_integer(const void* _x)
{
	int *x = (int*)_x;
	printf("%d\n", *x);
}

void print_fruit(const void* _fruit)
{
	fruit_t* fruit = (fruit_t*)_fruit;
	printf("%d	%s	%g\n", fruit->id, fruit->name, fruit->price);
}

int cmp_fruit(const void* _x, const void* _y)
{
	fruit_t* x = (fruit_t*)_x;
	fruit_t* y = (fruit_t*)_y;

	return strcmp(x->name, y->name);
}

int cmp_price(const void* _x, const void* _y)
{
	fruit_t* x = (fruit_t*)_x;
	fruit_t* y = (fruit_t*)_y;

	return x->price - y->price;
}

int main1(void)
{
	link_t* head = create_link(sizeof(fruit_t));
	assert(head);
	
	fruit_t apple = {1, "apple", 3.4};
	fruit_t pear = {2, "pear", 8.8};
	fruit_t banana = {3, "banana", 5.6};
	fruit_t peach = {4, "peach", 7.1};

	insert_link(head, &apple);
	insert_link(head, &pear);
	insert_link(head, &banana);

	display_link(head, print_fruit);

/*
	link_t* p = find_link(head, &apple, cmp_fruit);
	if(NULL == p){
		printf("查找失败\n");
	}else{
		printf("查找成功\n");
		print_fruit(p->data);
		delete_link(head, &apple, cmp_fruit);
	}
	printf("-------------------------\n");
*/

	sort_link(head, head->next, head->prev, cmp_price);
	display_link(head, print_fruit);
	free_link(head);
	return 0;
}

//qsort
int cmp_integer(const void*x, const void* y)
{
	return *(int*)y - *(int*)x;
}

int main(void)
{
	link_t* head = create_link(sizeof(int));
	assert(head);

	int i = 0;
	for(i = 0; i < 10; i++){
		insert_link(head, &i);
	}

	int f_val = 8;
	display_link(head, print_integer);
	/*
	link_t* p = find_link(head, &f_val, cmp_integer);
	if(NULL == p){
		printf("查找失败\n");
	}else{
		printf("查找成功\n");
		print_integer(p->data);
		delete_link(head, &f_val, cmp_integer);
	}
	*/
	sort_link(head, head->next, head->prev, cmp_integer);
	display_link(head, print_integer);
	free_link(head);
	return 0;
}
