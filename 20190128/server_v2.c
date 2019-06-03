#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

void *handleClient(void *arg)
{
	int sockfd = (int)arg;
	char caMsg[64] = {'\0'};
	ssize_t ret = -1;
	while (1)
	{
		memset(caMsg, 0, sizeof(caMsg));
		ret = read(sockfd, caMsg, sizeof(caMsg));
		if (-1 == ret)
		{
			if (EINTR == errno)
			{
				continue;
			}
			break;
		}
		else if (0 == ret)
		{
			printf("客户端和服务器断开了连接...\n");
			break;
		}
		printf("recv msg --> %s\n", caMsg);

		strcat(caMsg, " ^_^ ");
		write(sockfd, caMsg, strlen(caMsg));
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	//AF_INET:ipv4
	//不可靠传输:SOCK_STREAM   --> tcp
	//0表示使用默认的传输协议
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == sockfd)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;   //使用ipv4协议
	//将点分十进制字符串表示的ip转换成整型存放
	//servaddr.sin_addr.s_addr = inet_addr("192.168.1.92");
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//将本地字节序转换成网络字节序
	servaddr.sin_port = htons(8888);
	memset(servaddr.sin_zero, 0, 8);

	bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	//让sockfd处于监听状态
	//20 --> 客户端连接队列的大小
	listen(sockfd, 20);

	struct sockaddr_in clientaddr;
	int iLen = sizeof(clientaddr);
	int clientSockfd = -1;
	pthread_t thread;
	while (1)
	{
		//接收客户端的连接，若没有客户端连接则阻塞等待
		clientSockfd = accept(sockfd, (struct sockaddr*)&clientaddr
						      , &iLen);	
		if (-1 == clientSockfd)
		{
			perror("accept");
			continue;
		}
		printf("ip:%s, port:%d, sockfd:%d\n"
			   , inet_ntoa(clientaddr.sin_addr)
			   , ntohs(clientaddr.sin_port)
			   , clientSockfd);

		//创建线程专门用于和客户端进行数据收发
		pthread_create(&thread, NULL, handleClient
					   , (void*)clientSockfd);

	}


	return 0;
}
