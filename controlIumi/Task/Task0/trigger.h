#ifndef task0_trigger
#define task0_trigger

#include "config.h"

TaskHandle_t task0_handle = NULL;
void task0_function(void * parameters);

void task0_init(){
    #ifdef enable_task0
    xTaskCreatePinnedToCore(
        task0_function,
        task0_name,
        task0_RAM,
        NULL,
        task0_priority,
        &task0_handle,
        task0_nucleo);
    #endif
}

#endif