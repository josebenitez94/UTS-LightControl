#ifndef task3_trigger
#define task3_trigger

#include "config.h"

TaskHandle_t task3_handle = NULL;
void task3_function(void * parameters);

void task3_init(){
    #ifdef enable_task3
    xTaskCreatePinnedToCore(
        task3_function,
        task3_name,
        task3_RAM,
        NULL,
        task3_priority,
        &task3_handle,
        task3_nucleo);
    #endif
}

#endif