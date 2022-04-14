#include "sockets.h"

int main(void) 
{
    int clientSocket;
    struct sockaddr_in clientAddr;
    char messageSent[100] = "Ce message provient du client !";

    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    fill_addr(&clientAddr, inet_addr(IP), htons(PORT), AF_INET);

    if (connect(clientSocket, (struct sockaddr*) &clientAddr, sizeof(clientAddr)) == -1) {
        perror("connect()");
        exit(EXIT_FAILURE);
    }

    if (send(clientSocket, messageSent, sizeof(messageSent), 0) == -1) {
        perror("send()");
        exit(EXIT_FAILURE);
    }

    close(clientSocket);

    return 0;
}
