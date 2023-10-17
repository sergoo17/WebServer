//
// Created by sergoo on 16.10.2023.
//

#ifndef WEBSERVER_ROUTER_H
#define WEBSERVER_ROUTER_H

#include <unordered_map>
#include <string>
#include <functional>
#include "../HTTPRequest/HTTPRequest.h"


class Router {
public:
    std::unordered_map<std::string, std::function<std::string(HTTPRequest)>> routers;
    void add_route(const std::string& path, std::function<std::string(HTTPRequest)> callback);

};


#endif //WEBSERVER_ROUTER_H
