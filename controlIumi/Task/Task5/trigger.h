#ifndef task5_trigger
#define task5_trigger

#include "config.h"

TaskHandle_t task5_handle = NULL;
void task5_function(void * parameters);

void task5_init(){
    #ifdef enable_task5
    xTaskCreatePinnedToCore(
        task5_function,
        task5_name,
        task5_RAM,
        NULL,
        task5_priority,
        &task5_handle,
        task5_nucleo);
    #endif
}

#endif