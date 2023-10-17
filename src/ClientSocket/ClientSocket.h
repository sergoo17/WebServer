//
// Created by vargmen on 16.10.23.
//

#ifndef WEBSERVER_CLIENTSOCKET_H
#define WEBSERVER_CLIENTSOCKET_H
#pragma once
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>


class ClientSocket {
public:
    explicit ClientSocket(int socket);
    ~ClientSocket();
    [[nodiscard]] std::string read_some() const;
    void write_some(const std::string& response) const;

    int clientSocket;
};


#endif //WEBSERVER_CLIENTSOCKET_H
