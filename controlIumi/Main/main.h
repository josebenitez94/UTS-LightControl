#ifndef Main_main.h
#define Main_main.h

#include "Arduino.h"
#include "../config/pines.h"
#include "../config/config.h"
#include "../Util/structs.h"
#include "../Util/enum.h"
#include "../Util/SPIFFS/spiffsMetods.h"

Ident identification;
String MAC_ADDRESS;
System sistem;
System sistem2;
void setModeLed(AlarmLevel level);

#include "../Task/Task1/Task.h"
#include "../Task/Task2/Task.h"
#include "../Task/Task3/Task.h"
#include "../Task/Task4/Task.h"
#include "../Task/Task5/Task.h"
#include "../Task/TaskControl.h"

void MainSetup(){
    Serial.begin(115200);
    MAC_ADDRESS = WiFi.macAddress();
    initSPIFFS();
    init_task_all();
}

void MainLoop(){
    
}

#endif