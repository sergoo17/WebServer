#ifndef HTML_RESPONSE_H
#define HTML_RESPONSE_H


#include <string>
#include <filesystem>
#include "../HTTPResponse/HTTPResponse.h"

class HTMLResponse {
public:
    static std::string build(const std::string& content,
                             HTTPStatus statusCode = HTTPStatus::OK,
                             HTTPVersion httpProtocol = HTTPVersion::HTTP_1_1);
};


#endif //HTML_RESPONSE_H
