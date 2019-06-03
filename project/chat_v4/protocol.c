#include "protocol.h"

PDU* mkPDU(uint uiMsgLen)
{
	uint uiPDULen = sizeof(PDU)-4*sizeof(char)+uiMsgLen;
	PDU *pdu = (PDU*)malloc(uiPDULen);
	if (NULL == pdu)
	{
		printf("mallco pdu failed");
		exit(EXIT_FAILURE);
	}
	memset(pdu, 0, uiPDULen);
	pdu->uiPDULen = uiPDULen;
	pdu->uiMsgLen = uiMsgLen;

	return pdu;
}

void sendPDU(int sockfd, const PDU *pdu)
{
	if (NULL == pdu)
	{
		return;
	}
	uint uiLeft = pdu->uiPDULen;  //还剩余多少数据要发送
	uint uiSended = 0;            //已经发送了多少数据
	ssize_t ret = 0;
	while (1)
	{
		if (uiLeft > 4096)
		{
			ret = write(sockfd, (char*)pdu+uiSended, 4096);
		}
		else 
		{
			ret = write(sockfd, (char*)pdu+uiSended, uiLeft);
		}
		if (-1 == ret)
		{
			if (EINTR == errno)
			{
				continue;
			}
			perror("write");
			exit(EXIT_FAILURE);
		}

		uiLeft -= ret;
		uiSended += ret;
		if (0 == uiLeft)
		{
			break;
		}
	}
}

PDU *recvPDU(int sockfd)
{
	uint uiPDULen = 0;
	ssize_t ret = 0;
	//先接收第一个字段的数据用于确定数据的总的大小
	ret = read(sockfd, &uiPDULen, sizeof(uint));
	if (0 == ret)
	{
		return NULL;
	}
	uint uiMsgLen = uiPDULen-(sizeof(PDU)-4*sizeof(char));
	//申请空间用于接收剩余的数据
	PDU *pdu = mkPDU(uiMsgLen);

	uint uiLeft = uiPDULen-sizeof(uint);
	uint uiRecved = sizeof(uint);	
	while (1)
	{
		if (uiLeft > 4096)
		{
			ret = read(sockfd, (char*)pdu+uiRecved, 4096);
		}
		else
		{
			ret = read(sockfd, (char*)pdu+uiRecved, uiLeft);
		}
		if (-1 == ret)
		{
			if (EINTR == errno)
			{
				continue;
			}
			perror("recv msg");
			exit(EXIT_FAILURE);
		}
		if (0 == ret)
		{
			break;
		}
		uiLeft -= ret;
		uiRecved += ret;
		if (0 == uiLeft)
		{
			break;
		}
	}

	return pdu;
}













