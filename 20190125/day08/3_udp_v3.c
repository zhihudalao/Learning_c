#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

void *run(void *arg)
{
	int sockfd = (int)arg;
	char caMsg[64] = {'\0'};
	struct sockaddr_in servaddr;
	int iLen = sizeof(servaddr);
	while (1)
	{
		memset(caMsg, 0, sizeof(caMsg));
		recvfrom(sockfd, caMsg, sizeof(caMsg), 0
			     , (struct sockaddr *)&servaddr, &iLen);
		printf("recv server msg --> %s\n", caMsg);
	}
	return NULL;
}

int main(int argc, char *argv[])
{	
	//AF_INET:ipv4
	//不可靠传输:SOCK_DGRAM   --> udp
	//0表示使用默认的传输协议
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == sockfd)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

	pthread_t thread;
	//创建线程专门用来接收服务器的信息
	pthread_create(&thread, NULL, run, (void*)sockfd);

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;   //使用ipv4协议
	//将点分十进制字符串表示的ip转换成整型存放
	//servaddr.sin_addr.s_addr = inet_addr("192.168.87.137");
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//将本地字节序转换成网络字节序
	servaddr.sin_port = htons(8888);
	memset(servaddr.sin_zero, 0, 8);

	char caMsg[64] = {'\0'};
	int iLen = sizeof(servaddr);
	while (1)
	{
		printf("请输入消息:\n");
		scanf("%s", caMsg);
		if (0 == strcmp("exit", caMsg))
		{
			pthread_cancel(thread);
			pthread_join(thread, NULL);
			break;
		}
		//通过socket往指定ip，port上发送数据
		sendto(sockfd, caMsg, strlen(caMsg), 0
			   , (struct sockaddr *)&servaddr, sizeof(servaddr));

	}


	return 0;
}
