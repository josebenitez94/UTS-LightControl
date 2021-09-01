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
            else{
                digitalWrite(RELE_PIN, LOW);
                TiAct = millis();
                Serial.println("APAGA BOMBILLA");
                varDelete=false;
            }
        }

        if((millis() > (sistem.timeLightOn*1000 + TiAct))){
            if(varDelete){
                varDelete = false;
                sistem.automatic = true;
                Serial.println("TIEMPO EXCEDIDO");
            }
        }

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
#endif

#endif

