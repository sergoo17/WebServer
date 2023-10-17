//
// Created by sergoo on 16.10.2023.
//

#include "FileSystem.h"

std::string FileSystem::getFileContent(const std::string &fileName) {
    std::string sourcePath = "../templates/";
    std::ifstream file(sourcePath + fileName, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        throw std::logic_error("Error find file: " + fileName);
    }
    std::string content;
    std::streamsize size = file.tellg();
    content.resize(size);
    file.seekg(0, std::ios::beg);
    file.read(&content[0], size);
    file.close();
    return content;
}