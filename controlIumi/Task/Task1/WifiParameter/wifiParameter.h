#ifndef WifiParameter_wifiParameter
#define WifiPArameter_wifiParameter

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <HTTPClient.h>

AsyncWebServer server(PORT_AP_STA);

bool initAPMode(){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(SSID_AP, PASS_AP);
    //WiFi.softAPConfig(IP_DEFAULT, GATEWAY_DEFAULT, SUBNET_DEFAULT);
    return(true);
}

bool initSTAMode(String ssid, String pass){
    int contWifiConnect=0;
    
    for(int i=0;i<INTENT_UNTIL_RESET;i++){
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid.c_str(), pass.c_str());
        bool statusLed = true;

        while ((WiFi.status() != WL_CONNECTED) || (contWifiConnect < INTENT_CONNECT_TIME)) {
            digitalWrite(LED_BLUE, statusLed);
            Serial.print('.');
            delay(1000);
            contWifiConnect++;
            statusLed = !statusLed;
            if(WiFi.status() == WL_CONNECTED) 
                break;
        }
        digitalWrite(LED_BLUE, LOW);
        if(contWifiConnect == INTENT_CONNECT_TIME){
            Serial.println("Ha fallado la conexion, quedan "+String(INTENT_UNTIL_RESET-i) + "Intentos");
            contWifiConnect=0;
        }
        else{
            return(true);
        }
    }
    return(false);
}

IPAddress getLocalIP(){
    return(WiFi.localIP());
}


#endif