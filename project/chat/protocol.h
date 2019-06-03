#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "public.h"

enum MSG_TYPE
{
	MSG_TYPE_MIN = 0,
	MSG_TYPE_REGIST_REQUEST,    //注册请求
	MSG_TYPE_REGIST_RESPOND,    //注册回复
	
	MSG_TYPE_LOGIN_REQUEST,     //登录请求   
	MSG_TYPE_LOGIN_RESPOND,     //登录回复
};

typedef struct PDU
{
	uint uiMsgType;       //消息类型
	uint uiFrom;          //谁发的
	uint uiTo;            //发送给谁
	char caMsg[128];	  //信息
}PDU;

PDU *mkPDU();

#endif
