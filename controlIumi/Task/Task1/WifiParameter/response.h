#ifndef WifiParameter_response
#define WifiParamater_response

void root(AsyncWebServerRequest *request){
  request->send(200, "text/plain", "pagina root");
}

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Dato no Valido");
}

#endif