#include "sockets.h"

int main(void)
{
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    unsigned int clientSize = sizeof(clientAddr);
    int serverSocket, newSocket;
    char* clientIP = malloc(sizeof(IP));
    char messageReceived[100];

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    fill_addr(&serverAddr, inet_addr(IP), htons(PORT), AF_INET);

    if (bind(serverSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) == -1) {
        perror("bind()");
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "\nListening on %d...\n", PORT);
    if (listen(serverSocket, 10) == -1) {
        perror("listen()");
        exit(EXIT_FAILURE);
    }

    newSocket = accept(serverSocket, (struct sockaddr*) &clientAddr, &clientSize);
    if (newSocket != -1) {
        clientIP = strcat(clientIP, inet_ntoa(clientAddr.sin_addr));
        fprintf(stderr, "\nNouvelle Connection\nIp : %s\n", clientIP);
        recv(newSocket, messageReceived, sizeof(messageReceived), 0);
        printf("Message : \"%s\"\n", messageReceived);
    } else {
        perror("accept()");
        exit(EXIT_FAILURE);
    }

    free(clientIP);
    close(serverSocket);
    
    return 0;
}
