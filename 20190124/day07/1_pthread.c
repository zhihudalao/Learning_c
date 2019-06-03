/*
 线程：一个并发执行的流程，和创建它的进程共享运行空间
       及不和创建它的进程分离，所有资源共享

	   cpu最小的调度单元为线程，将创建线程的进程称之为主线程
	   主线程(进程)结束后，所有它创建的线程都结束

	   线程的正常结束不会对进程产生影响

	   亦将线程称之为轻量级的进程

	   若一个进程只有一个执行流程，则也可称之为线程
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *run(void *arg)
{
	char *pData = (char*)arg;
	int i = 0;
	while (1)
	{
		printf("%s --> %d\n", pData, ++i);
		sleep(1);
	}
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int ret = 0;
	//NULL表示使用系统默认的线程属性
	ret = pthread_create(&thread, NULL, run, argv[1]);
	if (0 != ret)
	{
		printf("创建线程失败 --> %s\n", strerror(ret));
		exit(EXIT_FAILURE);
	}

	int i = 0;
	while (1)
	{
		printf("main while --> %d\n", ++i);
		sleep(1);
	}

	return 0;
}







