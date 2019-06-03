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
#include <sys/mman.h>
#include <signal.h>

/*
 售票员：关好门,发送开车信号给司机，让其开车    SIGUSR1
         接收司机的开门信号                     SIGUSR2
         忽略乘客拦车信号                       SIGINT
 

 司机：接收售票员开车信号   SIGUSR1
       发送开门信号         SIGUSR2
	   接收乘客拦车信号     SIGINT 
 */

pid_t pid = -1;

void conductor(int sig)  //售票员
{
	if (SIGUSR2 == sig)  // 开门信号
	{
		printf("售票员打开车门...\n");
		sleep(1);
		printf("乘客买票上车...\n");
		sleep(1);
		printf("售票员关好车门...\n");
		sleep(1);
		kill(getppid(), SIGUSR1);
	}
}

void driver(int sig)  //司机
{
	if (SIGINT == sig)  // 拦车信号
	{
		printf("有乘客拦车...\n");
		sleep(1);
		printf("司机停下车...\n");
		sleep(1);
		kill(pid, SIGUSR2);
		sleep(1);
	}
	else if (SIGUSR1 == sig)  //开车信号
	{
		printf("老司机开车，车辆行驶中...\n");	
	}
}

int main(int argc, char *argv[])
{
	pid = fork();
	if (pid > 0)  //司机
	{
		signal(SIGINT, driver);	
		signal(SIGUSR1, driver);
		while (1)
		{
			pause();
		}	
	}
	else if (0 == pid)  //售票员
	{
		signal(SIGUSR2, conductor);
		signal(SIGINT, SIG_IGN);

		//发车,售票员发送开车信号给司机
		kill(getppid(), SIGUSR1);
		while (1)
		{
			pause();
		}
	}
	else if (-1 == pid)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}	
		
	return 0;
}





