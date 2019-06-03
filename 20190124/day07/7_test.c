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

typedef struct STU
{
	int iId;
	char caName[32];
	float fScore;
}STU;

void *run(void *arg)
{
	STU *stu = (STU*)arg;
	printf("id:%d, name:%s, score:%.2f\n"
		   , stu->iId, stu->caName, stu->fScore);

	return (void*)888;
}

int main(int argc, char *argv[])
{
	STU stu = {1001, "jack", 89.5};
	pthread_t thread;
	int ret = 0;
	//NULL表示使用系统默认的线程属性
	ret = pthread_create(&thread, NULL, run, (void*)&stu);
	if (0 != ret)
	{
		printf("创建线程失败 --> %s\n", strerror(ret));
		exit(EXIT_FAILURE);
	}

	void *retval = NULL;
	pthread_join(thread, &retval);
	printf("main: 线程退出，返回值 --> %d\n", (int)retval);


	return 0;
}







