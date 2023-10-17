#include "TCPSocket.h"

int TCPSocket::createSocket()
{
    listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocket == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return -1;
    }

    // Bind the socket to the given port
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(listenSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Failed to bind the socket to port " << port << std::endl;
        close(listenSocket);
        return -1;
    }

    // Listen for incoming connections
    if (listen(listenSocket, 5) == -1) {
        std::cerr << "Failed to listen on the socket." << std::endl;
        close(listenSocket);
        return -1;
    }

    return listenSocket;
}

TCPSocket::~TCPSocket() {

        close(listenSocket);


}