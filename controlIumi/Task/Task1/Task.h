#ifndef task1_task
#define task1_task

#include "trigger.h"
#ifdef enable_task1
#include "WifiParameter/wifiParameter.h"
#include "WifiParameter/request.h"
#include "WifiParameter/response.h"

void task1_function(void * parameters){
    (void)parameters;

    if(initSTAMode()) Serial.println("wifi inicializada correctamente");
    else Serial.println("Wifi no inicializada");
    initRequestServices();
    Serial.println("Servicios montados satisfactoriamente");
    Serial.println("imprimiendo IP LOCAL");
    Serial.println(getLocalIP());

    for(;;){
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
#endif
#endif

