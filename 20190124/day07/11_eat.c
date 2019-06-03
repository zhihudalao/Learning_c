#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define NUM 5

union semun
{
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;
	unsigned short  *array;
	struct seminfo  *__buf;
};

int semid = 0;

void getChopsticks(int num)
{
	int left = num;
	int right = (num+1)%NUM;

	struct sembuf sem[2] = {{left, -1, 0}, {right, -1, 0}};
	semop(semid, sem, 2);
}

void putChopsticks(int num)
{
	int left = num;
	int right = (num+1)%NUM;

	struct sembuf sem[2] = {{left, 1, 0}, {right, 1, 0}};
	semop(semid, sem, 2);
}


void *eatAndThink(void *arg) 
{
	int num = (int)arg;
	while (1)
	{
		printf("第%d个哲学家思考中...\n", num+1);
		sleep(1);
		getChopsticks(num);
		printf("第%d个哲学家获得筷子吃饭...\n", num+1);
		sleep(1);
		putChopsticks(num);
		printf("第%d个哲学家放下筷子...\n", num+1);
		sleep(1);
	}

	return NULL;
}

int main(void)
{
	semid = semget(0x00123, NUM, IPC_CREAT|0664);
	union semun usval;
	usval.val = 1;

	int i = 0;
	for (; i<NUM; i++)
	{
		semctl(semid, i, SETVAL, usval);
	}

	pthread_t et[NUM];
	for (i=0; i<NUM; i++)
	{
		pthread_create(et+i, NULL, eatAndThink, (void*)i);
	}

	for (i=0; i<NUM; i++)
	{
		pthread_join(et[i], NULL);
	}

	return 0;
}






