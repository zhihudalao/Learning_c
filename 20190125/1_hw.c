#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *run(void *arg)
{
	char *pData = (char*)arg;
	int cur = 0;
	while (1)
	{
		pthread_mutex_lock(&mutex);
		cur = strlen(pData);
		printf("str len = %d\n", cur);
		pthread_mutex_unlock(&mutex);
		
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	char caData[64] = {'\0'};

	pthread_t thread;
	pthread_create(&thread, NULL, run, caData);

	while (1)
	{
		pthread_mutex_lock(&mutex);
		scanf("%s", caData);
		pthread_mutex_unlock(&mutex);
		
		if (0 == strcmp("exit", caData))
		{
			pthread_cancel(thread);
			pthread_join(thread, NULL);
			break;
		}
		
		sleep(1);
	}

	return 0;
}
