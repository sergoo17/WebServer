cmake_minimum_required(VERSION 3.26)
project(WebServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        WebServer
        src/main.cpp
        src/HTTPServer/HTTPServer.cpp
        src/HTTPServer/HTTPServer.h
        src/TCPSocket/TCPSocket.cpp
        src/TCPSocket/TCPSocket.h
        src/ClientSocket/ClientSocket.cpp
        src/ClientSocket/ClientSocket.h
        src/HTTPRequest/HTTPRequest.cpp
        src/HTTPRequest/HTTPRequest.h
        src/Router/Router.cpp
        src/Router/Router.h
        src/FileSystem/FileSystem.cpp
        src/FileSystem/FileSystem.h
        src/Responses/HTMLResponse/HTMLResponse.cpp
        src/Responses/HTMLResponse/HTMLResponse.h
        src/Responses/HTTPResponse/HTTPResponse.cpp
        src/Responses/HTTPResponse/HTTPResponse.h
        src/Enums/HTTPStatus.cpp
        src/Enums/HTTPStatus.h
        src/Enums/HTTPVersions.cpp
        src/Enums/HTTPVersions.h
        src/Enums/HTTPMethods.cpp
        src/Enums/HTTPMethods.h
        src/Responses/FileResponse/FileResponse.cpp
        src/Responses/FileResponse/FileResponse.h
)

if(WIN32)
    target_link_libraries(WebServer wsock32 ws2_32)
endif()
