//
// Created by sergoo on 16.10.2023.
//

#ifndef WEBSERVER_FILESYSTEM_H
#define WEBSERVER_FILESYSTEM_H
#include <string>
#include <fstream>

class FileSystem {
public:

   static std::string getFileContent(const std::string &fileName);



};


#endif //WEBSERVER_FILESYSTEM_H
