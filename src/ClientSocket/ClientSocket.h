//
// Created by sergoo on 16.10.2023.
//

#ifndef WEBSERVER_CLIENT_SOCKET_H
#define WEBSERVER_CLIENT_SOCKET_H
#include <string>
#include "winsock2.h"


class ClientSocket {
public:
    explicit ClientSocket(int socket);
    ~ClientSocket();
    int socket;
    static const int BUFFER_SIZE = 4096;
    std::string read() const;
    void write(const std::string& response) const;
};


#endif //WEBSERVER_CLIENT_SOCKET_H
