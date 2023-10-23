#include <unordered_map>
#include "HTTPResponse.h"

std::string Response::build(const std::string& content, HTTPStatus statusCode, HTTPVersion httpVersion) {
    std::string response;
    std::string httpProtocol = getStringHttpVersions(httpVersion);
    std::string statusDetail = getStatusDescription(statusCode);
    response = httpProtocol + " " + std::to_string(statusCode) + " " + statusDetail + "\r\n";

    if (content.size() > 70000 && content.size() < 90000) {
        std::unordered_map<std::string, std::string> myMap;
        myMap["Content-Type"] = "application/wasm";

        for (const auto& pair : myMap) {
            response += pair.first + ": " + pair.second + "\r\n";
        }
    }

    response += "\r\n";
    response += content;
    return response;
}
