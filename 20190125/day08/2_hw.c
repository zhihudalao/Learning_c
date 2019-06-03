#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

int g_iData = 0;   //共享资源
sem_t sem;
pthread_mutex_t mutex;

void *run(void *arg)
{	
	sem_wait(&sem);
	while (1)
	{
		pthread_mutex_lock(&mutex);
		printf("thread --> %d\n", ++g_iData);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}

	return NULL;
}

int main(void)
{
	sem_init(&sem, 0, 0);

	pthread_t thread;
	pthread_create(&thread, NULL, run, NULL);

	while (1)
	{
		pthread_mutex_lock(&mutex);
		++g_iData;
		if (3 == g_iData)
		{
			sem_post(&sem);
		}
		printf("main --> %d\n", g_iData);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}

	return 0;
}
