//
// Created by vargmen on 16.10.23.
//

#include "ClientSocket.h"

ClientSocket::ClientSocket(int socket) : clientSocket(socket){

}


std::string ClientSocket::read_some() const
{
    char buffer[4096] = {0};
    recv(clientSocket, buffer, 4096, 0);
    return buffer;
}
void ClientSocket::write_some(const std::string& response) const
{
    send(clientSocket, response.c_str(), static_cast<int>(response.size()), 0);

}

ClientSocket::~ClientSocket(){
    close(clientSocket);
}