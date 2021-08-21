#ifndef task1_trigger
#define task1_trigger

#include "config.h"

TaskHandle_t task1_handle = NULL;
void task1_function();

void task1_init(){
    #ifdef enable_task1
    task1_function();
    /*
    xTaskCreatePinnedToCore(
        task1_function,
        task1_name,
        task1_RAM,
        NULL,
        task1_priority,
        &task1_handle,
        task1_nucleo);
    */
    #endif
}

#endif