#include "client.h"

int main(int argc, char *argv[])
{
	int sockfd = mkSocket();
	connectToServer(sockfd);
	work(sockfd);

	return 0;
}
