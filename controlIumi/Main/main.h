#ifndef Main_main.h
#define Main_main.h

#include "Arduino.h"
#include "../config/pines.h"
#include "../config/config.h"
#include "../Task/Task0/Task.h"
#include "../Task/Task1/Task.h"
#include "../Task/TaskControl.h"

void MainSetup(){
    Serial.begin(115200);
    init_task_all();
}

void MainLoop(){

}

#endif