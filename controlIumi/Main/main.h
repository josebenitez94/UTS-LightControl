#ifndef Main_main.h
#define Main_main.h

#include "Arduino.h"
#include "../config/pines.h"
#include "../config/config.h"
#include "../Util/enum.h"
#include "../Util/SPIFFS/spiffsMetods.h"

Ident identification;

#include "../Task/Task1/Task.h"
#include "../Task/Task2/Task.h"
#include "../Task/Task3/Task.h"
#include "../Task/TaskControl.h"

void MainSetup(){
    Serial.begin(115200);
    initSPIFFS();
    init_task_all();
}

void MainLoop(){
    
}

#endif