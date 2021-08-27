#ifndef task1_task
#define task1_task

#include "trigger.h"
#include "WifiParameter/wifiParameter.h"
#include "WifiParameter/response.h"
#include "WifiParameter/request.h"

#ifdef enable_task1

void task1_function(){
    Serial.println("Inicializa Tarea #1 :: WIFI CONNECTION");
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);

    if(isFileExist(CREDENTIALS_SPIFFS)){
        String credential = readFile(CREDENTIALS_SPIFFS);
        String ssid = credential.substring(0, credential.indexOf(";"));
        String pass = credential.substring(credential.indexOf(";")+1);
        bool connected = initSTAMode(ssid, pass);
        if(!connected){
            Serial.println("Credenciales no validas o Wifi inaccesible! Reseteando Parametros...");
            deleteFile(CREDENTIALS_SPIFFS);
            digitalWrite(LED_RED, HIGH);
            delay(2000);
            digitalWrite(LED_RED, LOW);
            ESP.restart();
        }
        else{
            Serial.print("Wifi Inicializado con IP:");
            Serial.println(getLocalIP());
            setModeLed(CONNECTION_OK);
            delay(2000);
        }
    }
    else{
        if(initAPMode()){ 
            setModeLed(MODE_AP);
            Serial.println("Wifi AP inicializado correctamente");
        }
        else{
            digitalWrite(LED_RED, HIGH);
            Serial.println("Wifi AP no inicializado");
            delay(2000);
            digitalWrite(LED_RED, LOW);
            ESP.restart();
        }
    }
    Serial.println("INICIALIZANDO SERVICIOS");
    initRequestServices();
    Serial.println("Servicios asincronos montados satisfactoriamente");
}
#endif
#endif

