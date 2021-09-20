#ifndef task5_task
#define task5_task

#include "trigger.h"
#ifdef enable_task5

void task5_function(void * parameters){
    (void)parameters;

    vTaskDelay(100 / portTICK_PERIOD_MS);
    uint32_t TiAct = millis();
    boolean varDelete = false;
    int conteoPromedio=0;
    uint32_t promAnalogico=0;
    int numeroVecesPromedio=0;
    bool bombillaStatus;

    pinMode(RELE_PIN, OUTPUT);
    digitalWrite(RELE_PIN, HIGH);
    Serial.println("Inicializa Tarea #5 :: Actuadores y detector de corriente");

    for(;;){    

        if(sistem.newStatus){
            sistem.newStatus= false;
            if(sistem.timeLightOn > 0){
                digitalWrite(RELE_PIN, LOW);
                TiAct = millis();
                Serial.println("ENCIENDE BOMBILLA");
                varDelete=true;
                bombillaStatus = true;
            }
            else{
                digitalWrite(RELE_PIN, HIGH);
                TiAct = millis();
                Serial.println("APAGA BOMBILLA");
                varDelete=false;
                bombillaStatus = false;
            }
        }

        if((millis() > (sistem.timeLightOn*1000 + TiAct))){
            if(varDelete){
                varDelete = false;
                sistem.automatic = true;
                Serial.println("TIEMPO EXCEDIDO");
            }
        }

        promAnalogico = analogRead(CORRIENTE_SENSOR);
        conteoPromedio++;

        if(promAnalogico > VALUE_DETECT){
            numeroVecesPromedio++;
        }

        if(conteoPromedio==1000){
            if(bombillaStatus && numeroVecesPromedio<50){
                sistem2.automatic = true;
                bombillaStatus = false;
                Serial.println("Enviando error bombilla al servidor");
            }
            //Serial.println(String(numeroVecesPromedio));
            numeroVecesPromedio=0;
            conteoPromedio=0;
        }

        if(bombillaStatus)

        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}
#endif

#endif

