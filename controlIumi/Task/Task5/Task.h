#ifndef task5_task
#define task5_task

#include "trigger.h"
#ifdef enable_task5


void task5_function(void * parameters){
    (void)parameters;

    vTaskDelay(100 / portTICK_PERIOD_MS);
    uint32_t TiAct = millis();
    boolean varDelete = false;

    pinMode(RELE_PIN, OUTPUT);
    Serial.println("Inicializa Tarea #5 :: Actuadores y detector de corriente");

    for(;;){    

        if(sistem.newStatus){
            sistem.newStatus= false;
            if(sistem.timeLightOn > 0){
                digitalWrite(RELE_PIN, HIGH);
                TiAct = millis();
                Serial.println("ENCIENDE BOMBILLA");
                varDelete=true;
            }
        }
        if((millis() > (sistem.timeLightOn*100 + TiAct))){
            digitalWrite(RELE_PIN, LOW);
            if(varDelete){
                varDelete = false;
                Serial.println("APAGUE BOMBILLA");
            }
        }

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
#endif

#endif

