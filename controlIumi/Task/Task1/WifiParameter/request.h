#ifndef WifiParameter_request
#define WifiParameter_request

void initRequestServices(){
    server.on("/", HTTP_GET, root);
    server.on("/REGISTER", HTTP_GET, RegisterNetwork);
    server.on("/ROUTER", HTTP_GET, Network);
    server.on("/MAC", HTTP_GET, MacSystem);
    server.on("/RESET", HTTP_GET, ResetESP);
    server.onNotFound(notFound);
    server.begin();
}

#endif