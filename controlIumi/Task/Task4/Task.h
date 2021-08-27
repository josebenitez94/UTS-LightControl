#ifndef task4_task
#define task4_task

#include "trigger.h"
#ifdef enable_task4

void ledControl(bool red, bool green, bool blue);
AlarmLevel alarmLevel;
uint32_t tiLed;
int conteoLed;

void task4_function(void * parameters){
    (void)parameters;
    
    vTaskDelay(75 / portTICK_PERIOD_MS);
    tiLed = millis();

    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    Serial.println("Inicializa Tarea #4 :: Indicadores y Sonido");

    for(;;){    
        if((millis()-tiLed) > 500){
            conteoLed++;
            tiLed = millis();
            if(conteoLed >100) conteoLed = 0;
        }

        if(alarmLevel == MODE_AP){
            ledControl(true, false, true);
        }
        if(alarmLevel == CONNECTION_OK){
            if(conteoLed < 6){
                ledControl(false, true, false);
            }
            else{
                ledControl(false, false, false);
                alarmLevel = NONE_ALARM;
            }
        }
        if(alarmLevel == CONNECTION_ERROR){
            ledControl(true, false, false);
        }
        if(alarmLevel == SERVER_ERROR){
            if((conteoLed%2) == 0){
                ledControl(true, true, false);
            }
            else{
                ledControl(false, false, false);
            }
            if(conteoLed >= 6){
                ledControl(false, false, false);
                alarmLevel = NONE_ALARM;
            }
        }
        if(alarmLevel == ACCESS_OK){
            if(conteoLed < 6){
                ledControl(false, true, false);
            }
            else{
                ledControl(false, false, false);
                alarmLevel = NONE_ALARM;
            }
        }
        if(alarmLevel == ACCESS_ERROR){
            if((conteoLed%2) == 0){
                ledControl(true, false, false);
            }
            else{
                ledControl(false, false, false);
            }
            if(conteoLed >= 6){
                ledControl(false, false, false);
                alarmLevel = NONE_ALARM;
            }
        }        
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}
#endif

void setModeLed(AlarmLevel level){
    alarmLevel = level;
    tiLed = millis();
    conteoLed = 0;
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);
}

void ledControl(bool red, bool green, bool blue){
    digitalWrite(LED_RED, red);
    digitalWrite(LED_GREEN, green);
    digitalWrite(LED_BLUE, blue);
}

#endif

