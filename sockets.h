#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h> 
#include <unistd.h> 
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <string.h> 

#define PORT 2345
#define IP "127.0.0.1"

void fill_addr(struct sockaddr_in* addr, in_addr_t ip, uint16_t port, int family)
{
    addr->sin_addr.s_addr = ip;
    addr->sin_port = port;
    addr->sin_family = family;
}
