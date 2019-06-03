#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include<stdlib.h>
int main(int argc,char** argv){
	int sockfd=socket(AF_INET,SOCK_DGRAM,0 );
	if(-1==sockfd){
		perror("socket");
		exit(EXIT_FAILURE);
	}
struct sockaddr_in servaddr;
servaddr.sin_family=AF_INET;
	return 0;
}
