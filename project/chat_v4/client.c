#include "client.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>   //inet_addr
#include <arpa/inet.h>
#include "protocol.h"
#include <pthread.h>

//用来保存登录的id
uint g_uiId = 0;

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

void connectToServer(int sockfd)
{
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;     //使用ipv4协议通讯
	//inet_addr:将点分十进制字符串表示的ip转换成整数
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	//htons:将本地字节序转换成网络字节序
	servAddr.sin_port = htons(8080);

	int ret = -1;
	ret = connect(sockfd, (struct sockaddr*)&servAddr
				  , sizeof(servAddr));
	if (-1 == ret)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
}

static int getIntFromSTDIN()
{
	char caBuf[512] = {'\0'};
	read(STDIN_FILENO, caBuf, 512);
	char *p = strchr(caBuf, '\n');
	if (NULL != p)
	{
		*p = '\0';
	}	
	else
	{
		caBuf[511] = '\0';
		while ('\n' != getchar()){}
	}
	int choice = 0;
	sscanf(caBuf, "%d", &choice);
	return choice;
}

static int loginRegistFace()
{
	printf("  ^_^\n");
	printf("1,登录\n");
	printf("2,注册\n");
	printf("0,退出\n");
	printf("请输入选项:\n");
	int choice = getIntFromSTDIN();
	return choice;
}

static void getStrFromSTDIN(char *caData, int iLen)
{
	read(STDIN_FILENO, caData, iLen);
	char *p = strchr(caData, '\n');
	if (NULL != p)
	{
		*p = '\0';
	}
	else
	{
		caData[iLen-1] = '\0';
		while ('\n' != getchar()){}
	}
}

static void regist(int sockfd)
{
	//生成注册请求信息发送给服务器
	PDU *pdu = mkPDU(PWD_LEN);
	printf("请输入注册密码:\n");
	getStrFromSTDIN(pdu->caMsg, PWD_LEN);
	pdu->uiMsgType = ENUM_MSG_TYPE_REGIST_REQUEST;
	sendPDU(sockfd, pdu);
	free(pdu);
	pdu = NULL;

	//接收服务器的注册回复信息
	pdu = recvPDU(sockfd);
	if (ENUM_MSG_TYPE_REGIST_RESPOND == pdu->uiMsgType
		&& pdu->uiTo > 0)
	{
		printf("注册成功，获得ID --> %u\n", pdu->uiTo);
	}
	else
	{
		printf("注册失败\n");
	}
	free(pdu);
	pdu = NULL;
}

static int login(int sockfd)
{
	PDU *pdu = mkPDU(PWD_LEN);
	printf("请输入ID:\n");
	pdu->uiFrom = getIntFromSTDIN();
	g_uiId = pdu->uiFrom;              //记录登陆的id
	printf("请输入登录密码:\n");
	getStrFromSTDIN(pdu->caMsg, PWD_LEN);
	pdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_REQUEST;
	sendPDU(sockfd, pdu);
	free(pdu);
	pdu = NULL;
	
	//接收服务器的注册回复信息
	int retval = 0;
	pdu = recvPDU(sockfd);
	if (ENUM_MSG_TYPE_LOGIN_RESPOND == pdu->uiMsgType)
	{
		printf("%s\n", pdu->caMsg);
		if (0 == strcmp("登录成功", pdu->caMsg))
		{
			retval = 1;
		}
	}
	free(pdu);
	pdu = NULL;

	return retval;
}

static int loginRegist(int sockfd)
{
	int choice = -1;
	int retval = 0;
	while (1)
	{
		choice = loginRegistFace();
		switch (choice)
		{
		case 1:  //login
			retval = login(sockfd);
			break;
		case 2:  //regist
			regist(sockfd);
			break;
		case 0:  //exit
			break;
		default: //input error;
			printf("输入选项有误...\n");
			break;
		}
		if (1 == retval)
		{
			break;
		}
	}
}

static int chatFace()
{
	printf("   ^_^\n");
	printf("1,获得用户列表\n");
	printf("2,私聊\n");
	printf("3,群联\n");
	printf("0,退出\n");
	printf("请输入选项:\n");
	int choice = getIntFromSTDIN();
	return choice;
}

static void getUsrList(int sockfd)
{
	PDU *pdu = mkPDU(0);
	pdu->uiMsgType = ENUM_MSG_TYPE_USR_LIST_REQUEST;
	sendPDU(sockfd, pdu);
	free(pdu);
	pdu = NULL;
}

static void privateChat(int sockfd)
{
	char caMsg[4096] = {'\0'};
	uint uiPerId = 0;   //对方id
	printf("请输入对方的ID:\n");
	uiPerId = getIntFromSTDIN();

	printf("请输入聊天消息:\n");
	getStrFromSTDIN(caMsg, 4096);

	PDU *pdu = mkPDU(strlen(caMsg)+1);
	pdu->uiFrom = g_uiId;
	pdu->uiTo = uiPerId;
	strcpy(pdu->caMsg, caMsg);
	pdu->uiMsgType = ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST;
	sendPDU(sockfd, pdu);
	free(pdu);
	pdu = NULL;
}

static void groupChat(int sockfd)
{
	char caMsg[4096] = {'\0'};
	printf("请输入群聊消息:\n");
	getStrFromSTDIN(caMsg, 4096);
	PDU *pdu = mkPDU(strlen(caMsg)+1);
	strcpy(pdu->caMsg, caMsg);
	pdu->uiFrom = g_uiId;
	pdu->uiMsgType = ENUM_MSG_TYPE_GROUP_CHAT_REQUEST;
	sendPDU(sockfd, pdu);
	free(pdu);
	pdu = NULL;
}

static void quitChat(int sockfd)
{
	PDU *pdu = mkPDU(0);
	pdu->uiFrom = g_uiId;
	pdu->uiMsgType = ENUM_MSG_TYPE_QUIT_REQUEST;
	sendPDU(sockfd, pdu);
	free(pdu);
	pdu = NULL;
}

static void chat(int sockfd)
{
	int choice = 0;
	while (1)
	{
		choice = chatFace();
		switch (choice)
		{
		case 1:       //获得用户列表
			getUsrList(sockfd);
			break;
		case 2:       //私聊
			privateChat(sockfd);
			break; 
		case 3:       //群聊
			groupChat(sockfd);
			break;  
		case 0:       //退出
			quitChat(sockfd);
			break;
		default:
			printf("选项输入有误.\n");
			break;
		}
	}
}

static void handleServerUsrListRespond(PDU *pdu)
{
	if (NULL == pdu)
	{
		return;
	}
	uint uiId = 0;
	uint uiCount = (pdu->uiMsgLen)/sizeof(uint);
	int i = 0;
	printf("获得用户列表：\n");
	for (; i<uiCount; i++)
	{
		memcpy(&uiId, pdu->caMsg+i*sizeof(uint), sizeof(uint));
		printf("\t%u\n", uiId);
	}
}

void *handleServer(void *arg)
{
	int sockfd = (int)arg;
	PDU *pdu = NULL;
	while (1)
	{
		pdu = recvPDU(sockfd);
		if (NULL == pdu)
		{
			printf("服务器断开连接\n");
			exit(EXIT_FAILURE);
		}
		switch (pdu->uiMsgType)
		{
		case ENUM_MSG_TYPE_USR_LIST_RESPOND:
			handleServerUsrListRespond(pdu);	
			break;
		case ENUM_MSG_TYPE_PRIVATE_CHAT_RESPOND:
			printf("%s\n", pdu->caMsg);
			break;
		case ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:
		case ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:
			printf("%u says: %s\n", pdu->uiFrom, pdu->caMsg);
			break;
		case ENUM_MSG_TYPE_QUIT_RESPOND:
			exit(EXIT_SUCCESS);
		default:
			break;
		}
		free(pdu);
		pdu = NULL;
	}
}

void work(int sockfd)
{
	loginRegist(sockfd);	
	//创建线程专门处理服务器发过来的信息
	pthread_t thr;
	pthread_create(&thr, NULL, handleServer, (void*)sockfd);

	chat(sockfd);
	pthread_join(thr, NULL);
}









