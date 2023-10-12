cmake_minimum_required(VERSION 3.26)
project(WebServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        WebServer
        src/main.cpp
)

if(WIN32)
    target_link_libraries(ServerSiryogiAndVityi wsock32 ws2_32)
endif()
