#ifndef FILE_OPE_H
#define FILE_OPE_H

#include "public.h"
#include "usrLink.h"

//打开文件
int openFile(const char *path, int flags);

//将用户链表保存到文件中
void saveUsrToFile(const UsrLink *link);

//将文件中的用户信息读取出来放到链表中
void getUsrFromFile(UsrLink *link);


#endif
