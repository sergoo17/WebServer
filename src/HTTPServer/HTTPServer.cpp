//
// Created by sergoo on 12.10.2023.
//

#include "HTTPServer.h"
#include "../ClientSocket/ClientSocket.h"

void HTTPServer::run() {
    TCPSocket socket(8000);
    int serverSocket = socket.createSocket();

    while (true) {
        int clientSocketInt = static_cast<int>(accept(serverSocket, nullptr, nullptr));
        ClientSocket clientSocket(clientSocketInt);
        std::string stringRequest = clientSocket.read();
        HTTPRequest request(stringRequest);

        auto found = router.routers.find(request.path);
        if (found != router.routers.end()) {
            std::string response = router.routers[request.path](request);
            clientSocket.write(response);
        } else {

        }
    }
}
