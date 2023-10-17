//
// Created by sergoo on 12.10.2023.
//

#include "HTTPServer.h"
#include "../ClientSocket/ClientSocket.h"
#include "../Responses/HTMLResponse/HTMLResponse.h"

HTTPServer::HTTPServer(const int port) : port(port) {
}

void HTTPServer::run() const {
    TCPSocket socket(port);
    int serverSocket = socket.createSocket();

    while (true) {
        int clientSocketInt = static_cast<int>(accept(serverSocket, nullptr, nullptr));
        ClientSocket clientSocket(clientSocketInt);
        std::string stringRequest = clientSocket.read();
        HTTPRequest request(stringRequest);
        std::string response = request.getResponse(router.routers);
        clientSocket.write(response);
    }
}