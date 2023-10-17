#ifndef RESPONSE_H
#define RESPONSE_H

#include "../../Enums/HTTPMethods.h"
#include "../../Enums/HTTPStatus.h"
#include "../../Enums/HTTPVersions.h"

class Response {
public:
    static std::string build(const std::string& content,
                             HTTPStatus statusCode = HTTPStatus::OK,
                             HTTPVersion httpProtocol = HTTPVersion::HTTP_1_1);
};

#endif //RESPONSE_H
