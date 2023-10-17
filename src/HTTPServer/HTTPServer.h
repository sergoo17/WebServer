#ifndef WEBSERVER_HTTPSERVER_H
#define WEBSERVER_HTTPSERVER_H
#include "../TCPSocket/TCPSocket.h"
#include "../Router/Router.h"


class HTTPServer {
public:
    Router router;
    explicit HTTPServer(int port);
    void run() const;
    static void handleRequest(int socket,
                              std::unordered_map<std::string, std::function<std::string(HTTPRequest)>> routers);
private:
    int port = 8000;
};


#endif //WEBSERVER_HTTPSERVER_H
