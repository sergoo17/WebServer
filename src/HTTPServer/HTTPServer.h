#ifndef WEBSERVER_HTTPSERVER_H
#define WEBSERVER_HTTPSERVER_H
#include "../TCPSocket/TCPSocket.h"
#include "../Router/Router.h"


class HTTPServer {
public:
    explicit HTTPServer(const int port);
    Router router;
    int port = 8000;
    void run() const;
};


#endif //WEBSERVER_HTTPSERVER_H
