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
 服务员：有顾客光临            SIGINT   --> "ctrl+c"
         发送做菜信号给厨师    SIGUSR1
		 接收厨师的上菜信号    SIGUSR2
		 接收顾客的结账信号    SIGTSTP  --> "ctrl+z"
		 接收下班信号          SIGQUIT  --> "ctrl+\"
		 通知厨师下班          SIGALRM
		 接收厨师结束信号      SIGCHLD
 

 厨师：接收服务员做菜信号      SIGUSR1
       发送上菜信号给服务员    SIGUSR2
	   接收服务员的下班信号    SIGALRM 
 */

pid_t pid = -1;

void waiter(int sig)  //服务员
{
	if (SIGINT == sig)    //顾客到来
	{
		printf("有顾客到来，服务员接待...\n");
		sleep(1);
		printf("顾客点菜...\n");
		sleep(1);
		printf("服务员通知厨师做菜...\n");
		sleep(1);
		kill(pid, SIGUSR1);
	}
	else if (SIGUSR2 == sig)   //上菜
	{
		printf("服务员上菜...\n");
	}
	else if (SIGTSTP == sig)   //顾客结账
	{
		printf("顾客结账...\n");
		sleep(1);
		printf("服务员说，欢迎下次光临并收拾餐具...\n");
	}
	else if (SIGQUIT == sig)   //下班
	{
		printf("时间到了，服务员收到老板下班通知...\n");
		sleep(1);
		printf("服务员收拾收拾并通知厨师下班...\n");
		sleep(1);
		kill(pid, SIGALRM);
	}
	else if (SIGCHLD == sig)
	{
		wait(NULL);
		printf("服务员关好水电门，下班...\n");
		exit(EXIT_SUCCESS);
	}
}

void cook(int sig)  //厨师
{
	if (SIGUSR1 == sig)   //做菜
	{
		printf("厨师努力做菜中...\n");
		sleep(2);
		printf("厨师做好菜，通知服务员上菜...\n");
		sleep(1);
		kill(getppid(), SIGUSR2);
	}
	else if (SIGALRM == sig)
	{
		printf("厨师整理后厨，下班爽歪歪...\n");
		sleep(1);
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char *argv[])
{
	pid = fork();
	if (pid > 0)  //服务员
	{
		signal(SIGINT, waiter);	     //有顾客到来
		signal(SIGUSR2, waiter);	 //上菜
		signal(SIGTSTP, waiter);	 //结账
		signal(SIGQUIT, waiter);	 //下班
		signal(SIGCHLD, waiter);	 //回收子进程
		printf("服务员说，新的一天，新的开始，加油，\\^_^//\n");
		while (1)
		{
			pause();
		}	
	}
	else if (0 == pid)  //厨师
	{
		signal(SIGUSR1, cook);      //做菜信号
		signal(SIGALRM, cook);      //下班信号
		signal(SIGINT, SIG_IGN);    //忽略顾客到来信号
		signal(SIGTSTP, SIG_IGN);   //忽略顾客结账信号

		printf("厨师说，杀猪宰羊，干起来...呦呵...\n");
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





