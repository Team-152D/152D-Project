#ifndef NET_H
#define	NET_H

#define _WIN32_WINNT 0x0501 //assert compatible windows version
#include <winsock2.h>
#include <ws2tcpip.h>

int server();
int client(char*);
void endNet(int);

#endif	/* NET_H */