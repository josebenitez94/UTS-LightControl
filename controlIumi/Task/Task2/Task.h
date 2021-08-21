#ifndef task2_task
#define task2_task

#include "trigger.h"
#ifdef enable_task2


void task2_function(void * parameters){
    
    (void)parameters;

    pinMode(led_blink,OUTPUT);

    for(;;){
        digitalWrite(led_blink, HIGH);
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        digitalWrite(led_blink, LOW);
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}
#endif
#endif
