#include "HTTPRequest.h"
#include "../Responses/FileResponse/FileResponse.h"
#include "../Responses/HTMLResponse/HTMLResponse.h"

HTTPRequest::HTTPRequest(const std::string& request) {
    parseRequest(request);
}

void HTTPRequest::parseRequest(const std::string& request) {
    if (!request.empty()) {
        size_t posRequest = request.find(escapeSymbols);
        if (posRequest == std::string::npos) {
            std::cerr << "Invalid Request: " << request << std::endl;
            return;
        }
        std::string RequestLine = request.substr(0, posRequest);
        std::string HeadersLines = request.substr(posRequest + escapeSymbols.size());

        parseRequestLine(RequestLine);
        parseHeadersLines(HeadersLines);
    }
}

void HTTPRequest::parseRequestLine(const std::string& request) {
    size_t posMethod = request.find(' ');
    size_t posPath = request.rfind(' ');
    if (posMethod != std::string::npos && posPath != std::string::npos) {
        method = request.substr(0, posMethod);
        path = request.substr(posMethod + 1, posPath - posMethod - 1);
        httpProtocol = request.substr(posPath + 1);
    } else {
        std::cerr << "Parse Request Section Error" << std::endl;
        return;
    }
}

void HTTPRequest::parseHeadersLines(const std::string& request) {
    size_t pos = 0;
    while (pos < request.size()) {
        size_t end = request.find("\r\n", pos);
        if (end == std::string::npos) {
            break;
        }

        size_t colon = request.find(':', pos);
        if (colon != std::string::npos && colon < end) {
            std::string key = request.substr(pos, colon - pos);
            std::string value = request.substr(colon + 2, end - colon - 2);
            headers[key] = value;
        }

        pos = end + 2;
    }
}

std::string HTTPRequest::getResponse(std::unordered_map<std::string, std::function<std::string(HTTPRequest)>> routers) {
    auto found = routers.find(path);
    std::string response;
    if (found != routers.end()) {
        response = routers[path](*this);
    } else if (path.starts_with("/static/")) {
        response = FileResponse::build(path);
    } else {
        response = HTMLResponse::build("404.html");
    }
    return response;
}
