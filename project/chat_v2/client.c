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
#include "protocol.h"

uint g_uiId = 0;

int registAndLoginFace()
{
	printf("  ^_^\n");
	printf("1，登录\n");
	printf("2，注册\n");
	printf("0，退出\n");
	printf("请输入操作选项:\n");
	int iNum = -1;
	scanf("%d", &iNum);
	while ('\n' != getchar()){}
	
	return iNum;
}

void regist(int sockfd)
{
	PDU pdu;
	printf("请输入注册密码：\n");
	scanf("%s", pdu.caMsg);
	pdu.uiMsgType = MSG_TYPE_REGIST_REQUEST;
	write(sockfd, &pdu, sizeof(PDU));

	read(sockfd, &pdu, sizeof(PDU));
	printf("注册成功，获得ID --> %u\n", pdu.uiTo);
}

int login(int sockfd)
{
	PDU pdu;
	pdu.uiMsgType = MSG_TYPE_LOGIN_REQUEST;
	printf("请输入id：\n");
	scanf("%u", &pdu.uiFrom);
	g_uiId = pdu.uiFrom;     //保存登录的Id
	printf("请输入密码：\n");
	scanf("%s", pdu.caMsg);

	write(sockfd, &pdu, sizeof(PDU));
	
	read(sockfd, &pdu, sizeof(PDU));
	if (MSG_TYPE_LOGIN_RESPOND == pdu.uiMsgType)
	{
		if (0 == pdu.uiFrom)
		{
			printf("%s\n", pdu.caMsg);
			return -1;
		}
		printf("登录成功...\n");
		return 0;
	}
	return -1;
}

void quit(int sockfd, int isLogin)
{
	if (0 == isLogin)
	{
		PDU pdu;
		pdu.uiFrom = g_uiId;
		pdu.uiMsgType = MSG_TYPE_QUIT_REQUEST;

		write(sockfd, &pdu, sizeof(PDU));

		sleep(2);
	}
	close(sockfd);
	exit(EXIT_SUCCESS);
}

int chatFace()
{
	printf("    ^_^\n");
	printf("1，获得在线好友列表\n");
	printf("2，私聊\n");
	printf("3，群聊\n");
	printf("0，退出\n");
	printf("请输入操作选项:\n");
	int iNum = 0;
	scanf("%d", &iNum);
	return iNum;
}

void friendRespond(const PDU *pdu)
{
	if (NULL == pdu)
	{
		return;
	}

	int i = 0;
	uint uiId = 0;
	printf("好友列表：\n");
	for (; i<pdu->uiFrom; i++)
	{
		memcpy(&uiId, pdu->caMsg+i*sizeof(uint), sizeof(uint));
		printf("  %u\n", uiId);
	}
}

void *handleServer(void *arg)
{
	int sockfd = (int)arg;
	PDU pdu;
	ssize_t ret = -1;
	while (1)
	{
		ret = read(sockfd, &pdu, sizeof(PDU));
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
			printf("和服务器断开连接...\n");
			break;
		}

		switch (pdu.uiMsgType)
		{
		case MSG_TYPE_FRIEND_RESPOND:
			friendRespond(&pdu);
			break;
		}

	}
}

void getOnlineFriend(int sockfd)
{
	PDU pdu;
	pdu.uiMsgType = MSG_TYPE_FRIEND_REQUEST;
	write(sockfd, &pdu, sizeof(PDU));
}

void chat(int sockfd)
{
	//创建线程专门用于接收服务器的信息
	pthread_t thread;
	pthread_create(&thread, NULL, handleServer, (void*)sockfd);
	int ret = -1;
	while (1)
	{
		ret = chatFace();
		switch (ret)
		{
		case 1:     //online friend
			getOnlineFriend(sockfd);
			break;
		case 2:     //private chat
			break;
		case 3:     //group chat
			break;
		case 0:     //quit
			break;
		default:
			break;
		}	
	}
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
	//servaddr.sin_addr.s_addr = inet_addr("192.168.87.137");
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//将本地字节序转换成网络字节序
	servaddr.sin_port = htons(8888);
	memset(servaddr.sin_zero, 0, 8);

	int ret = -1;
	ret = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	if (-1 == ret)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	printf("connect to server ok\n");

//	pthread_t thread;
//	pthread_create(&thread, NULL, handleServer, (void*)sockfd);
	
	int isLogin = -1;
	while (1)
	{
		ret = registAndLoginFace();
		switch (ret)
		{
		case 1:      //login
			isLogin = login(sockfd);
			break;	
		case 2:      //regist
			regist(sockfd);
			break;	  
		case 0:      //quit
			quit(sockfd, isLogin);
			break;	  
		default:
			//go through
			break;	
		}
		if (0 == isLogin)
		{
			break;
		}
	}

	chat(sockfd);

	return 0;
}
