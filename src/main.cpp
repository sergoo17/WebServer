#include "HTTPServer/HTTPServer.h"
#include "Responses/HTTPResponse/HTTPResponse.h"
#include <string>

std::string mainPage(const HTTPRequest& request) {
    if (request.method == "GET")
    return Response::build("123", HTTPStatus::OK);
}

std::string icon(const HTTPRequest& request) {
    return Response::build("", HTTPStatus::NotFound);
}

int main() {
    HTTPServer server;
    server.router.add_route("/", mainPage);
    server.router.add_route("/favicon.ico", icon);
    server.run();
}