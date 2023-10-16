#ifndef WEBSERVER_HTTPSERVER_H
#define WEBSERVER_HTTPSERVER_H
#include "../TCPSocket/TCPSocket.h"
#include "../Router/Router.h"


class HTTPServer {
public:
    Router router;
    void run();
};


#endif //WEBSERVER_HTTPSERVER_H
