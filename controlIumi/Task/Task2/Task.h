#ifndef task2_task
#define task2_task

#include "trigger.h"
#ifdef enable_task2

HTTPClient http;

void task2_function(void * parameters){
    
    (void)parameters;

    vTaskDelay(25 / portTICK_PERIOD_MS);
    Serial.println("Inicializa Tarea #1 :: WIFI REQUEST/RESPONSE SERVICES");

    for(;;){
        if(WiFi.status()== WL_CONNECTED){
            if(identification.available){
                identification.available = false;
                String serverPath = String(URL_SERVER) + PAGE_INSERTAR_PHP + "?id=" + identification.id + "&mac=" + MAC_ADDRESS + "&estado=" + "1";
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
                    else{
                        sistem.timeLightOn = payload.toInt();
                        sistem.newStatus = true;
                        setModeLed(ACCESS_OK);
                    } 
                    Serial.println(sistem.timeLightOn);
                }
                else {
                    //RUTINA ERROR DE CONSULTA
                    Serial.print("Error code: ");
                    Serial.println(httpResponseCode);
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

