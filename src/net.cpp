#include <cstdio>
#include <iostream>
#include "net.h"
using namespace std;

#define MYPORT "65531"

int server(){
    WSADATA wsaData; 
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
      fprintf(stderr, "WSAStartup failed.\n");
      exit(1);
    }
        
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    struct addrinfo hints, *res;
    SOCKET sockfd, new_fd; 
    sockfd= new_fd= INVALID_SOCKET;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; //IPv4
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // fill in my IP for me
   
    if(getaddrinfo(NULL, MYPORT, &hints, &res)!=0){
        cout<<"getaddrinfo Failed.";
        WSACleanup();
        exit(1);
    }

    // make a listen socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(sockfd== INVALID_SOCKET){
        cout<<"\nCreating listen socket failed: "<<WSAGetLastError();
        freeaddrinfo(res);
        WSACleanup();
        exit(1);
    }
    
    //bind the socket
    if(bind(sockfd, res->ai_addr, res->ai_addrlen)==SOCKET_ERROR){
        cout<<"\nBinding listen socket failed: "<<WSAGetLastError();
        freeaddrinfo(res);
        WSACleanup();
        exit(1);
    }
    
    freeaddrinfo(res); 
 
    //listen on the socket
    if(listen(sockfd, 5)==SOCKET_ERROR){
        cout<<"\nListening failed: "<<WSAGetLastError();
        closesocket(sockfd);
        WSACleanup();
        exit(1);
    }

    //accept an incoming connection:
    addr_size = sizeof(their_addr);
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
    closesocket(sockfd);
    if(new_fd==INVALID_SOCKET){
        cout<<"Could not accept: "<<WSAGetLastError();
        closesocket(new_fd);
        WSACleanup();
        exit(1);
    }
    return new_fd;
}

int client(char *server){ 
    cout<<"\nClient understands server IP as: "<<server;
    
    WSADATA wsaData; 
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
      fprintf(stderr, "\nWSAStartup failed.\n");
      exit(1);
    }
    
    struct addrinfo hints, *res;
    SOCKET sockfd= INVALID_SOCKET;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    
    if(getaddrinfo(server, MYPORT, &hints, &res)!=0){
        cout<<"\ngetaddrinfo Failed.";
        WSACleanup();
        exit(1);
    }
     
    //create send socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(sockfd== INVALID_SOCKET){
        cout<<"\nCreating socket failed: "<<WSAGetLastError();
        freeaddrinfo(res);
        WSACleanup();
        exit(1);
    }
    
    //connect to server
    if(connect(sockfd, res->ai_addr, res->ai_addrlen)==SOCKET_ERROR){
        cout<<"\nConnecting failed: "<<WSAGetLastError();
        freeaddrinfo(res);
        closesocket(sockfd);
        WSACleanup();
        exit(1);       
    }   freeaddrinfo(res);
    
    return sockfd;
}

void endNet(int sockfd){
    closesocket(sockfd);
    WSACleanup();
}