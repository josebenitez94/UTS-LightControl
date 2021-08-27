#ifndef task4_trigger
#define task4_trigger

#include "config.h"

TaskHandle_t task4_handle = NULL;
void task4_function(void * parameters);

void task4_init(){
    #ifdef enable_task4
    xTaskCreatePinnedToCore(
        task4_function,
        task4_name,
        task4_RAM,
        NULL,
        task4_priority,
        &task4_handle,
        task4_nucleo);
    #endif
}

#endif