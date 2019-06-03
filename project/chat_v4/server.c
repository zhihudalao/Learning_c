#include "server.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>   //inet_addr
#include <arpa/inet.h>
#include <signal.h>
#include <pthread.h>
#include "usrLink.h"
#include "fileOpe.h"
#include "protocol.h"

UsrLink *g_pUsrLink = NULL;

int mkSocket()
{
	//AF_INET:使用ipv4协议来实现远程通讯
	//SOCK_STREAM:使用可靠传输
	//0:使用选择传输的默认协议(SOCK_STREAM-->tcp)
	//成功则返回新产生的socket的文件描述符，用于数据收发
	//失败返回-1
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == sockfd)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	return sockfd;
}

int mkBind(int sockfd)
{
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;     //使用ipv4协议通讯
	//inet_addr:将点分十进制字符串表示的ip转换成整数
//	servAddr.sin_addr.s_addr = inet_addr("192.168.87.137"); 
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	//htons:将本地字节序转换成网络字节序
	servAddr.sin_port = htons(8080);
	//将sockfd和指定的ip,port绑定，这样我们就可以通过sockfd
	//收发该ip,port上的数据
	if (-1 == bind(sockfd, (struct sockaddr*)&servAddr
				   , sizeof(servAddr)))
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}
	return 0;	
}

static void handleClientRegistRequest(int sockfd, PDU *pdu)
{
	if (NULL == pdu)
	{
		return;
	}
	//生成节点保存用户注册的id及密码并放入链表中
	UsrNode *node = mkUsrNode();
	node->uiId = g_pUsrLink->uiMaxId+1;
	strcpy(node->caPwd, pdu->caMsg);
	insertUsrLink(node, g_pUsrLink);
	//将链表保存到文件中
	saveUsrToFile(g_pUsrLink);

	//生成注册回复信息发送给客户端
	PDU *respdu = mkPDU(0);
	respdu->uiMsgType = ENUM_MSG_TYPE_REGIST_RESPOND;
	respdu->uiTo = node->uiId;
	sendPDU(sockfd, respdu);
	free(respdu);
	respdu = NULL;
}

static UsrNode* handleClientLoginRequest(int sockfd, PDU *pdu)
{
	UsrNode *retval = NULL;
	if (NULL == pdu)
	{
		return retval;
	}
	UsrNode *node = findUsrById(pdu->uiFrom, g_pUsrLink);
	PDU *respdu = NULL;
	char *tmp = NULL;
	if (NULL == node)
	{
		tmp = "ID不存在";
	}
	else 
	{
		if (0 == strcmp(node->caPwd, pdu->caMsg))
		{
			if (node->sockfd > 0)
			{
				tmp = "登录失败：该账号已登录";
			}
			else
			{
				tmp = "登录成功";
				node->sockfd = sockfd;
				retval = node;
			}
		}
		else
		{
			tmp = "登录失败，密码不匹配";
		}
	}
	respdu = mkPDU(strlen(tmp)+1);
	strcpy(respdu->caMsg, tmp);
	respdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_RESPOND;
	sendPDU(sockfd, respdu);
	free(respdu);
	respdu = NULL;

	return retval;
}

static void handleClientUsrListRequest(int sockfd)
{
	PDU *respdu = mkPDU(g_pUsrLink->uiLen*sizeof(uint));
	respdu->uiMsgType = ENUM_MSG_TYPE_USR_LIST_RESPOND;
	UsrNode *node = g_pUsrLink->pFirstNode;
	int i = 0;
	while (NULL != node)
	{
		memcpy(respdu->caMsg+i*sizeof(uint)
			   , &(node->uiId), sizeof(uint));
		node = node->pNext;
		i++;
	}
	sendPDU(sockfd, respdu);
	free(respdu);
	respdu = NULL;
}

static void handleClientPrivateChatRequest(int sockfd, PDU *pdu)
{
	if (NULL == pdu)
	{
		return;
	}
	
	UsrNode *node = findUsrById(pdu->uiTo, g_pUsrLink);
	char *tmp = NULL;
	PDU *respdu = NULL;
	if (NULL == node)
	{
		tmp = "聊天对象不存在";
	}
	else
	{
		if (0 == node->sockfd)
		{
			tmp = "信息发送失败：聊天对象不在线";
		}
		else
		{
			tmp = "对方已收到信息";
			//服务器将信息转发给对方
			sendPDU(node->sockfd, pdu);
		}
	}
	respdu = mkPDU(strlen(tmp)+1);
	strcpy(respdu->caMsg, tmp);
	respdu->uiMsgType = ENUM_MSG_TYPE_PRIVATE_CHAT_RESPOND;
	sendPDU(sockfd, respdu);
	free(respdu);
	respdu = NULL;
}

static void handleClientGroupChatRequest(int sockfd, PDU *pdu)
{
	if (NULL == pdu)
	{
		return;
	}
	UsrNode *node = g_pUsrLink->pFirstNode;
	while (NULL != node)
	{
		if (node->sockfd > 0)
		{
			sendPDU(node->sockfd, pdu);
		}
		node = node->pNext;
	}
}

static void handleClientQuitRequest(int sockfd, PDU *pdu)
{
	if (NULL == pdu)
	{
		return;
	}
	UsrNode *node = findUsrById(pdu->uiFrom, g_pUsrLink);
	if (NULL != node && sockfd == node->sockfd)
	{
		node->sockfd = 0;	
	}
	PDU *respdu = mkPDU(0);
	respdu->uiMsgType = ENUM_MSG_TYPE_QUIT_RESPOND;
	sendPDU(sockfd, respdu);
	free(respdu);
	respdu = NULL;
}

void *handleClient(void *arg)
{
	int sockfd = (int)arg;
	PDU *pdu = NULL;
	UsrNode *node = NULL;
	//循环接收客户端的信息
	while (1)
	{
		pdu = recvPDU(sockfd);
		if (NULL == pdu)
		{
			printf("客户端断开连接\n");
			if (NULL != node)
			{
				node->sockfd = 0;
			}
			break;
		}
		switch (pdu->uiMsgType)
		{
		case ENUM_MSG_TYPE_REGIST_REQUEST:
			handleClientRegistRequest(sockfd, pdu);
			break;
		case ENUM_MSG_TYPE_LOGIN_REQUEST:
			node = handleClientLoginRequest(sockfd, pdu);
			break;
		case ENUM_MSG_TYPE_USR_LIST_REQUEST:
			handleClientUsrListRequest(sockfd);
			break;
		case ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:
			handleClientPrivateChatRequest(sockfd, pdu);
			break;
		case ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:
			handleClientGroupChatRequest(sockfd, pdu);
			break;
		case ENUM_MSG_TYPE_QUIT_REQUEST:
			handleClientQuitRequest(sockfd, pdu);
			pthread_exit(NULL);
		default:
			break;
		}
		free(pdu);
		pdu = NULL;	
	}
}

// ./server
int main(int argc, char *argv[])
{
	//将用户信息从文件中读取出来
	g_pUsrLink = mkUsrLink();
	getUsrFromFile(g_pUsrLink);

	int sockfd = mkSocket();
	mkBind(sockfd);
	//将sockfd设置为监听状态
	//20:表示客户端连接缓冲队列的大小
	listen(sockfd, 20);

	struct sockaddr_in clientAddr;
	int iLen = sizeof(clientAddr);
	int newsockfd = -1;
	pthread_t thr;
	while (1)
	{
		//若没有客户端连接，则阻塞等待
		//接收从sockfd监听到的客户端
		//会自动的将连接过来的客户端的ip,port等信息放入clientAddr中
		//成功会自动创建一个socket，专门用于服务器和该客户端数据交互
		newsockfd = accept(sockfd, (struct sockaddr*)&clientAddr
					        , &iLen);	
		if (-1 == newsockfd)
		{
			perror("accept");
			continue;
		}
		printf("client-->ip:%s, port:%d, newsockfd:%d\n"
			   , inet_ntoa(clientAddr.sin_addr)
			   , ntohs(clientAddr.sin_port)
			   , newsockfd);

		pthread_create(&thr, NULL, handleClient, (void*)newsockfd);

	}

	return 0;
}


