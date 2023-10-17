//
// Created by sergoo on 17.10.2023.
//

#include "FileResponse.h"
#include "../../FileSystem/FileSystem.h"
#include <filesystem>

std::string FileResponse::build(const std::string& file, HTTPStatus statusCode, HTTPVersion httpProtocol) {
    std::string content;
    if (file.starts_with("/static/") && std::filesystem::exists(".." + file)) {
//        std::string filePath = file.substr(file.find('/', 1) + 1);
        content = FileSystem::getFileContent(file, "..");
    } else {
        content = "";
        statusCode = HTTPStatus::NotFound;
    }
    return Response::build(content, statusCode, httpProtocol);
}
