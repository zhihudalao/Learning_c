#ifndef CLIENT_H
#define CLIENT_H

#include "public.h"

int mkSocket();
void connectToServer(int sockfd);
void work(int sockfd);

#endif
