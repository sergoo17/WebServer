#ifndef WEBSERVER_GETSOCKET_H
#define WEBSERVER_GETSOCKET_H
#pragma once
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string>

class TCPSocket {
public:
    int port;
    int listenSocket;

    ~TCPSocket();
    explicit TCPSocket(int port) : port(port), listenSocket(-1){

    }
    int createSocket();
};


#endif //WEBSERVER_GETSOCKET_H
