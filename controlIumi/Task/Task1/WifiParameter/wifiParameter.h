#ifndef WifiParameter_wifiParameter
#define WifiPArameter_wifiParameter

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(PORT_AP_STA);

bool initAPMode(){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(SSID_AP, PASS_AP);
    //WiFi.softAPConfig(IP_DEFAULT, GATEWAY_DEFAULT, SUBNET_DEFAULT);
    return(true);
}

bool initSTAMode(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID_STA, PASS_STA);

    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        return(false);
    }
    return(true);
}

IPAddress getLocalIP(){
    return(WiFi.localIP());
}


#endif