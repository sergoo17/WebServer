#include "TCPSocket.h"

TCPSocket::TCPSocket(unsigned short port): port(port) {
}

int TCPSocket::createSocket() {
    WSADATA wsaData;
    WORD DLLVersion = MAKEWORD(2, 2);
    int result = WSAStartup(DLLVersion, &wsaData);
    if(result != 0) {
        throw std::logic_error("WSAStartup not init");
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    result = getaddrinfo(nullptr, std::to_string(port).c_str(), &hints, &addrResult);
    if (result != 0) {
        throw std::logic_error("getaddrinfo failed");
    }

    serverSocket = (int)socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket <= 0) {
        throw std::logic_error("Socket creating failed");
    }

    result = bind(serverSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
    if (result < 0) {
        throw std::logic_error("Socket binding failed");
    }

    result = listen(serverSocket, SOMAXCONN);
    if (result < 0) {
        throw std::logic_error("Socket listing failed");
    }

    return serverSocket;
}

TCPSocket::~TCPSocket() {
    WSACleanup();
    closesocket(serverSocket);
    freeaddrinfo(addrResult);
}

