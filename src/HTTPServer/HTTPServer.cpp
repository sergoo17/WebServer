//
// Created by sergoo on 12.10.2023.
//

#include <future>
#include "HTTPServer.h"
#include "../ClientSocket/ClientSocket.h"

HTTPServer::HTTPServer(const int port) : port(port) {
}

void HTTPServer::handleRequest(int socket,
                               std::unordered_map<std::string, std::function<std::string(HTTPRequest)>> routers) {
    ClientSocket clientSocket(socket);
    std::string stringRequest = clientSocket.read();
    HTTPRequest request(stringRequest);
    std::string response = request.getResponse(std::move(routers));
    clientSocket.write(response);
}

void HTTPServer::run() const {
    TCPSocket socket(port);
    int serverSocket = socket.createSocket();

    while (true) {
        int clientSocket = static_cast<int>(accept(serverSocket, nullptr, nullptr));
        std::async(std::launch::async, handleRequest, clientSocket, router.routers);
    }
}
