#include "HTMLResponse.h"
#include <iostream>

std::string HTMLResponse::build(const std::string& htmlFile, HTTPStatus statusCode, HTTPVersion httpVersion) {
    return Response::build("content", statusCode, httpVersion);
}
