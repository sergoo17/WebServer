//
// Created by sergoo on 16.10.2023.
//

#include "ClientSocket.h"

ClientSocket::ClientSocket(int socket) : socket(socket) {
}

ClientSocket::~ClientSocket() {
    closesocket(socket);
}

std::string ClientSocket::read() const {
    char buffer[BUFFER_SIZE] = {0};
    recv(socket, buffer, BUFFER_SIZE, 0);
    return buffer;
}

void ClientSocket::write(const std::string& response) const {
    send(socket, response.c_str(), static_cast<int>(response.size()), 0);
}
