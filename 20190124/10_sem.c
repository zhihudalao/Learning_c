/*
  信号量表示资源的可用数

 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define PRO_NUM 5     //生产者数量
#define CUS_NUM 20    //消费者数量
#define DISH_NUM 10   //共享盘子数量

char g_caDish[DISH_NUM] = {'\0'}; //盘子

pthread_mutex_t mutex[DISH_NUM];

pthread_mutex_t pro_mutex;
pthread_mutex_t cus_mutex;

sem_t empty;     //表示空盘子的数量
sem_t full;      //表示装有食物盘子的数量

int g_iProNum = 0;
void *product(void *arg) 
{
	int num = (int)arg;
	int tmp = 0;
	while (1)
	{
		//1,检查empty的值是否大于0，
		//2,若等于0则表示没有空盘子可供生产，则阻塞等待(睡眠)
		//3,若大于0,则表示有空盘子可供生产，则自动将empty的值减一
		//表示使用了一个资源,程序继续往下执行
		sem_wait(&empty);
		
		pthread_mutex_lock(&pro_mutex);
		tmp = g_iProNum;
		g_iProNum = (g_iProNum+1)%DISH_NUM;
		pthread_mutex_unlock(&pro_mutex);

		pthread_mutex_lock(mutex+tmp);
		srand((unsigned int)time(NULL));
		g_caDish[tmp] = rand()%26+'A';		
		printf("第%d个厨师往第%d个盘子中生产了%c食物\n"
			   , num+1, tmp+1, g_caDish[tmp]);
		pthread_mutex_unlock(mutex+tmp);

		//1,将full信号量的值加一
		//2,通知(唤醒)其他等待full信号量的线程
		sem_post(&full);

		sleep(1);
	}

	return NULL;
}

int g_iCusNum = 0;
void *customer(void *arg) 
{
	int num = (int)arg;
	int tmp = 0;
	while (1)
	{
		sem_wait(&full);
		
		pthread_mutex_lock(&cus_mutex);
		tmp = g_iCusNum;
		g_iCusNum = (g_iCusNum+1)%DISH_NUM;
		pthread_mutex_unlock(&cus_mutex);
		
		pthread_mutex_lock(mutex+tmp);
		
		printf("第%d个消费者吃了第%d个盘子中的%c食物\n"
			   , num+1, tmp+1, g_caDish[tmp]);
		g_caDish[tmp] = '\0';
	
		pthread_mutex_unlock(mutex+tmp);

		sem_post(&empty);

		sleep(2);
	}

	return NULL;
}

int main(void)
{
	//初始化空盘子信号量的值为8
	sem_init(&empty, 0, DISH_NUM);
	//含有食物盘子的信号量的值为0
	sem_init(&full, 0, 0);

	//创建生产者线程
	pthread_t pro[PRO_NUM];
	int i = 0;
	for (; i<PRO_NUM; i++)
	{
		pthread_create(pro+i, NULL, product, (void*)i);
	}

	//创建消费者线程
	pthread_t cus[CUS_NUM];
	for (i=0; i<CUS_NUM; i++)
	{
		pthread_create(cus+i, NULL, customer, (void*)i);
	}
	
	for (i=0; i<PRO_NUM; i++)
	{
		pthread_join(pro[i], NULL);
	}

	for (i=0; i<CUS_NUM; i++)
	{
		pthread_join(cus[i], NULL);
	}

	return 0;
}






