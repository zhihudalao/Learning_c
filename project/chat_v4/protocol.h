#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "public.h"

enum ENUM_MSG_TYPE
{
	ENUM_MSG_TYPE_MIN = 0,
	ENUM_MSG_TYPE_REGIST_REQUEST,       //注册请求
	ENUM_MSG_TYPE_REGIST_RESPOND,       //注册回复
	
	ENUM_MSG_TYPE_LOGIN_REQUEST,        //登录请求
	ENUM_MSG_TYPE_LOGIN_RESPOND,        //登录回复
	
	ENUM_MSG_TYPE_USR_LIST_REQUEST,     //用户列表请求
	ENUM_MSG_TYPE_USR_LIST_RESPOND,     //用户列表回复
	
	ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST, //私聊请求
	ENUM_MSG_TYPE_PRIVATE_CHAT_RESPOND, //私聊回复
	
	ENUM_MSG_TYPE_GROUP_CHAT_REQUEST,   //群聊请求
	ENUM_MSG_TYPE_GROUP_CHAT_RESPOND,   //群聊回复
	
	ENUM_MSG_TYPE_QUIT_REQUEST,         //退出请求
	ENUM_MSG_TYPE_QUIT_RESPOND,         //退出回复

	ENUM_MSG_TYPE_MAX = 0x00ffffff      //设置枚举占4字节
};

typedef struct PDU    //协议数据单元 protocol data unity
{
	uint uiPDULen;        //此次发送的数据总大小
	uint uiMsgType;       //数据类型
	uint uiFrom;          //谁发信息
	uint uiTo;            //发送给谁
	uint uiMsgLen;        //实际消息的大小  
	char caMsg[4];        //实际消息	
}PDU;

PDU* mkPDU(uint uiMsgLen);
void sendPDU(int sockfd, const PDU *pdu);
PDU *recvPDU(int sockfd);

#endif

