#ifndef HTTP_METHODS_H
#define HTTP_METHODS_H

#include <string>

enum class HTTPMethod {
    GET,
    POST,
    PUT,
    DELETE_,
    PATCH,
    HEAD,
    OPTIONS,
    TRACE,
    CONNECT,
    INVALID
};

std::string getStringHttpMethod(HTTPMethod method);

#endif //HTTP_METHODS_H
