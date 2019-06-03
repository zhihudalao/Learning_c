#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct STU
{
	int iId;
	char caName[32];
	float fScore;
}STU;

int main(int argc, char *argv[])
{
	int shmid = shmget(0x00123, 4096, IPC_CREAT|0664);
	if (-1 == shmid)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}

	printf("shmid = %d\n", shmid);

	//SHM_RDONLY:只读
	void * addr = shmat(shmid, NULL, SHM_RDONLY);
	if ((void *)-1 == addr)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	
	STU stu;
	//获得第一个学生信息
	memcpy(&stu, addr, sizeof(stu));
	printf("id:%d, name:%s, score:%.2f\n"
		   , stu.iId, stu.caName, stu.fScore);
	
	//获得第五个学生信息
	memcpy(&stu, (STU*)addr+4, sizeof(stu));
	//memcpy(&stu, (char*)addr+4*sizeof(STU), sizeof(stu));
	printf("id:%d, name:%s, score:%.2f\n"
		   , stu.iId, stu.caName, stu.fScore);

	//获得第二个学生信息
	memcpy(&stu, (STU*)addr+1, sizeof(stu));
	printf("id:%d, name:%s, score:%.2f\n"
		   , stu.iId, stu.caName, stu.fScore);

	shmdt(addr);

	return 0;
}





