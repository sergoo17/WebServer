#include "HTTPMethods.h"

std::string getStringHttpMethod(HTTPMethod method) {
    switch (method) {
        case HTTPMethod::GET:
            return "GET";
        case HTTPMethod::POST:
            return "POST";
        case HTTPMethod::PUT:
            return "PUT";
        case HTTPMethod::DELETE_:
            return "DELETE";
        case HTTPMethod::PATCH:
            return "PATCH";
        case HTTPMethod::HEAD:
            return "HEAD";
        case HTTPMethod::OPTIONS:
            return "OPTIONS";
        case HTTPMethod::TRACE:
            return "TRACE";
        case HTTPMethod::CONNECT:
            return "CONNECT";
        case HTTPMethod::INVALID:
            return "INVALID";
        default:
            return "";
    }
}