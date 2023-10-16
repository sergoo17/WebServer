#ifndef WEBSERVER_TCP_SOCKET_H
#define WEBSERVER_TCP_SOCKET_H

#include <stdexcept>
#include <iostream>
#include "winsock2.h"
#include "ws2tcpip.h"


class TCPSocket {
public:
    explicit TCPSocket(unsigned short port);
    ~TCPSocket();
    unsigned short port;
    int createSocket();
    int serverSocket{};

    ADDRINFO hints{};
    ADDRINFO *addrResult{};
};


#endif //WEBSERVER_TCP_SOCKET_H
