#include "HTMLResponse.h"
#include "../../FileSystem/FileSystem.h"
#include <iostream>

std::string HTMLResponse::build(const std::string& htmlFile, HTTPStatus statusCode, HTTPVersion httpVersion) {
    std::string content = FileSystem::getFileContent(htmlFile);
    return Response::build(content, statusCode, httpVersion);
}
