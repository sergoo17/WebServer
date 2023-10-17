#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <functional>


class HTTPRequest {
public:
    std::string method;
    std::string path;
    std::string httpProtocol;
    std::map<std::string, std::string> headers;
    std::string escapeSymbols = "\r\n";
    explicit HTTPRequest(const std::string& request);
    std::string getResponse(std::unordered_map<std::string, std::function<std::string(HTTPRequest)>> routers);
private:
    void parseRequest(const std::string& request);
    void parseRequestLine(const std::string& request);
    void parseHeadersLines(const std::string& request);
};


#endif //HTTP_REQUEST_H
