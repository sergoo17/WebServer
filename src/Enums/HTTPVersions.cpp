#include "HTTPVersions.h"

std::string getStringHttpVersions(HTTPVersion version) {
    switch (version) {
        case HTTPVersion::HTTP_1_0:
            return "HTTP/1.0";
        case HTTPVersion::HTTP_1_1:
            return "HTTP/1.1";
        case HTTPVersion::HTTP_2_0:
            return "HTTP/2.0";
        case HTTPVersion::HTTP_3_0:
            return "HTTP/3.0";
        default:
            return "";
    }
}