#include "HTTPServer/HTTPServer.h"
#include "Responses/HTMLResponse/HTMLResponse.h"
#include "Responses/FileResponse/FileResponse.h"
#include <string>

std::string mainPage(const HTTPRequest& request) {
    return HTMLResponse::build("index.html");
}

std::string icon(const HTTPRequest& request) {
    return FileResponse::build("/static/favicon/favicon.ico");
}

int main() {
    HTTPServer server(8000);
    server.router.add_route("/", mainPage);
    server.router.add_route("/favicon.ico", icon);
    server.run();
}