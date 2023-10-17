#include "HTTPResponse.h"

std::string Response::build(const std::string& content, HTTPStatus statusCode, HTTPVersion httpVersion) {
    std::string response;
    std::string httpProtocol = getStringHttpVersions(httpVersion);
    std::string statusDetail = getStatusDescription(statusCode);
    response = httpProtocol + " " + std::to_string(statusCode) + " " + statusDetail + "\r\n";
    response += "\r\n";
    response += content;
    return response;
}
