//
// Created by sergoo on 16.10.2023.
//

#include <utility>
#include "Router.h"

void Router::add_route(const std::string &path, std::function<std::string(HTTPRequest)> callback) {
    routers[path] = std::move(callback);
}
