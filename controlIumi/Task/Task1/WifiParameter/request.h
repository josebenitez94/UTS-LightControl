#ifndef WifiParameter_request
#define WifiParameter_request

void root(AsyncWebServerRequest *request);
void notFound(AsyncWebServerRequest *request);

void initRequestServices(){
    server.on("/", HTTP_GET, root);
    server.onNotFound(notFound);
    server.begin();
}

#endif