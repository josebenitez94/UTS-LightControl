#ifndef task2_task
#define task2_task

#include "trigger.h"
#ifdef enable_task2

HTTPClient http;

void task2_function(void * parameters){
    
    (void)parameters;

    vTaskDelay(25 / portTICK_PERIOD_MS);
    Serial.println("Inicializa Tarea #2 :: WIFI REQUEST/RESPONSE SERVICES");

    for(;;){
        if(WiFi.status()== WL_CONNECTED){
            if(identification.available || sistem.automatic || sistem2.automatic){
                String serverPath = String(URL_SERVER) + PAGE_INSERTAR_PHP + "?id=" + identification.id + "&mac=" + MAC_ADDRESS + "&tipo=";
                
                if(identification.available)
                    serverPath += "normal";
                if(sistem.automatic)
                    serverPath += "auto";
                if(sistem2.automatic)
                    serverPath += "error";

                identification.available = false;
                sistem.automatic = false;
                sistem2.automatic = false;
                
                http.begin(serverPath.c_str());
                int httpResponseCode = http.GET();
                if (httpResponseCode == 200) {
                    String payload = http.getString();
                    payload.replace(" ","");
                    payload.replace("\r","");
                    payload.replace("\n","");
                    if(payload == "DATOS_ERROR")
                        setModeLed(CONNECTION_ERROR);
                    else if(payload == "TARJETA_ERROR" || payload == "LECTOR_ERROR")
                        setModeLed(ACCESS_ERROR);
                    else if(payload == "DATOS_ERROR")
                        setModeLed(CONNECTION_ERROR);
                    else if(payload == "NADA")
                        setModeLed(ACCESS_ERROR);
                    else{
                        sistem.timeLightOn = payload.toInt();
                        sistem.newStatus = true;
                        setModeLed(ACCESS_OK);
                    } 
                    Serial.println("payload:"+payload);
                }
                else {
                    //RUTINA ERROR DE CONSULTA
                    Serial.print("Error code: ");
                    Serial.println(httpResponseCode);
                    setModeLed(ACCESS_ERROR);
                }
                http.end();
            }
        }
        else{
            //rutina error de conexión WIFI
        }

        vTaskDelay(200 / portTICK_PERIOD_MS);

    }
}
#endif
#endif

