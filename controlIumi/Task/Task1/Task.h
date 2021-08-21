#ifndef task1_task
#define task1_task

#include "trigger.h"
#include "WifiParameter/wifiParameter.h"
#include "WifiParameter/response.h"
#include "WifiParameter/request.h"

#ifdef enable_task1

void task1_function(){
    Serial.println("Inicializa Tarea #1");
    if(isFileExist(CREDENTIALS_SPIFFS)){
        String credential = readFile(CREDENTIALS_SPIFFS);
        String ssid = credential.substring(0, credential.indexOf(";"));
        String pass = credential.substring(credential.indexOf(";")+1);
        bool connected = initSTAMode(ssid, pass);
        if(!connected){
            Serial.println("Credenciales no validas o Wifi inaccesible! Reseteando Parametros...");
            deleteFile(CREDENTIALS_SPIFFS);
            delay(100);
            ESP.restart();
        }
        else{
            Serial.print("Wifi Inicializado con IP:");
            Serial.println(getLocalIP());
        }
    }
    else{
        if(initAPMode()) 
            Serial.println("Wifi AP inicializado correctamente");
        else
            Serial.println("Wifi AP no inicializado");
    }
    Serial.println("INICIALIZANDO SERVICIOS");
    initRequestServices();
    Serial.println("Servicios asincronos montados satisfactoriamente");

}
#endif
#endif

