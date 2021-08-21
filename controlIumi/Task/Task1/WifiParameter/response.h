#ifndef WifiParameter_response
#define WifiParamater_response

#include "registroRed.h"

void root(AsyncWebServerRequest *request){
  request->send(200, "text/plain", "pagina root");
}

void RegisterNetwork(AsyncWebServerRequest *request){
  request->send(200, "text/html", index_html);
}

void Network(AsyncWebServerRequest *request){
  request->send(200, "text/plain", "OK, Cambiando Parametros");
  if (request->hasParam("ssid")) {
    String ssid = request->getParam("ssid")->value();
    String pass = request->getParam("password")->value();
    String credentials = ssid + ";" + pass;
    writeFile(CREDENTIALS_SPIFFS, credentials);
    delay(500);
    ESP.restart();
  }
}

void MacSystem(AsyncWebServerRequest *request){
  String mac = WiFi.macAddress();
  request->send(200, "text/plain", mac);
}

void ResetESP(AsyncWebServerRequest *request){
  request->send(200, "text/plain", "OK, Reseteando Parametros");
  deleteFile(CREDENTIALS_SPIFFS);
  delay(1000);
  ESP.restart();
}

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Dato no Valido");
}

#endif