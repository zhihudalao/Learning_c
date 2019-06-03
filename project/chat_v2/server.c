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
#include "list.h"

List *g_pList = NULL;
//uint g_uiId = 1000;

void handleClientRegistRequest(PDU *pdu, int sockfd)
{
	if (NULL == pdu)
	{
		return;
	}	
	Node *node = mkNode();
	node->uiId = ++(g_pList->uiMaxId);
	strcpy(node->caPwd, pdu->caMsg);
	insert(g_pList, node);
	saveListToFile("usr.data", g_pList);

	pdu->uiTo = node->uiId;
	pdu->uiMsgType = MSG_TYPE_REGIST_RESPOND;
	write(sockfd, pdu, sizeof(PDU));
}

void handleClientLoginRequest(PDU *pdu, int sockfd)
{
	if (NULL == pdu)
	{
		return;
	}

	Node *node = findNodeById(g_pList, pdu->uiFrom);
	if (NULL == node)
	{
		strcpy(pdu->caMsg, "登录失败：id不存在");
		pdu->uiFrom = 0;
	}
	else
	{
		if (0 != strcmp(pdu->caMsg, node->caPwd))
		{
			pdu->uiFrom = 0;
			strcpy(pdu->caMsg, "登录失败：密码不对");	
		}
		else
		{
			if (node->sockfd > 0)
			{
				pdu->uiFrom = 0;
				strcpy(pdu->caMsg, "登录失败：该账号已经登录...\n");
			}
			else
			{
				//登陆成功保存客户端sockfd
				node->sockfd = sockfd;
			}
		}
	}
	pdu->uiMsgType = MSG_TYPE_LOGIN_RESPOND;
	write(sockfd, pdu, sizeof(PDU));
}
			
void handleClientQuitRequest(PDU *pdu, int sockfd)
{
	if (NULL == pdu)
	{
		return;
	}

	Node *node = findNodeById(g_pList, pdu->uiFrom);
	if (NULL != node)
	{
		node->sockfd = -1;
	}
}
			
void handleClientFriendRequest(int sockfd)
{
	PDU pdu;
	memset(&pdu, 0, sizeof(PDU));
	pdu.uiMsgType = MSG_TYPE_FRIEND_RESPOND;

	int i = 0;
	Node *node = g_pList->pFirstNode;
	while (NULL != node)
	{
		memcpy(pdu.caMsg+i*sizeof(uint), &(node->uiId), sizeof(uint));
		node = node->pNext;
		i++;
	}
	pdu.uiFrom = i;   //保存id的个数

	write(sockfd, &pdu, sizeof(PDU));
}

void *handleClient(void *arg)
{
	int sockfd = (int)arg;
	PDU pdu;
	uint uiId = 0;
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
			printf("客户端和服务器断开了连接...\n");
			Node *node = findNodeById(g_pList, uiId);
			if (NULL != node)
			{
				node->sockfd = -1;
			}
			break;
		}
		switch (pdu.uiMsgType)
		{
		case MSG_TYPE_REGIST_REQUEST:
			handleClientRegistRequest(&pdu, sockfd);
			break;
		case MSG_TYPE_LOGIN_REQUEST:
			uiId = pdu.uiFrom;
			handleClientLoginRequest(&pdu, sockfd);
			break;
		case MSG_TYPE_QUIT_REQUEST:
			handleClientQuitRequest(&pdu, sockfd);
			pthread_exit(NULL);
			break;
		case MSG_TYPE_FRIEND_REQUEST:
			handleClientFriendRequest(sockfd);
			break;
		default:
			break;
		}
	}

	return NULL;
}

int main(int argc, char *argv[])
{	
	g_pList = mkList();
	getListFromFile("usr.data", g_pList);

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
