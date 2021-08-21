#ifndef task2_trigger
#define task2_trigger

#include "config.h"

TaskHandle_t task2_handle = NULL;
void task2_function(void * parameters);

void task2_init(){
    #ifdef enable_task2
    xTaskCreatePinnedToCore(
        task2_function,
        task2_name,
        task2_RAM,
        NULL,
        task2_priority,
        &task2_handle,
        task2_nucleo);
    #endif
}

#endif