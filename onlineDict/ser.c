//
// Created by Lc on 2018/8/16.
//

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IP "0"
#define PORT 8888
#define MAXSIZE 1024
#define LISTEN_NUM 16

int netInit();

int main()
{
    int sockfd = netInit();
}

int netInit()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > sockfd)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0 , sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(IP);
    addr.sin_port = htons(PORT);

    if (0 > bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)))
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (0 > listen(sockfd, LISTEN_NUM))
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}