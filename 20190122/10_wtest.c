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
	//0:读写
	void * addr = shmat(shmid, NULL, 0);
	if ((void *)-1 == addr)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	
	STU stu[5] = {{1001, "jack", 90}
			      , {1002, "rose", 89}
				  , {1003, "mary", 98}
	              , {1004, "pitter", 87}
	              , {1005, "kitty", 78}};

	memcpy(addr, stu, sizeof(stu));

	shmdt(addr);

	return 0;
}





