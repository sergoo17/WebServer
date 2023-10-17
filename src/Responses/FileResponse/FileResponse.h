//
// Created by sergoo on 17.10.2023.
//

#ifndef WEBSERVER_FILE_RESPONSE_H
#define WEBSERVER_FILE_RESPONSE_H

#include "../HTTPResponse/HTTPResponse.h"


class FileResponse {
public:
    static std::string build(const std::string& content,
                             HTTPStatus statusCode = HTTPStatus::OK,
                             HTTPVersion httpProtocol = HTTPVersion::HTTP_1_1);
};


#endif //WEBSERVER_FILE_RESPONSE_H
