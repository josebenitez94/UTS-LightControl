#ifndef task3_task
#define task3_task

#include "trigger.h"
#ifdef enable_task3

#include <SPI.h>
#include <MFRC522.h>
 
MFRC522 rfid(RC522_SS_PIN, RC522_RST_PIN);
MFRC522::MIFARE_Key key; 

void task3_function(void * parameters){
    (void)parameters;
    Serial.println("Inicializa Tarea #3 :: Lectura RFID");
    SPI.begin();
    rfid.PCD_Init();

    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }

    for(;;){       
        if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()){
            identification.id = "";
            for (byte i = 0; i < rfid.uid.size; i++) {
                if(rfid.uid.uidByte[i] < 0x10)
                    identification.id += "0";
                identification.id +=  String(rfid.uid.uidByte[i], HEX);
            }
            identification.available = true;
            Serial.println("ID: " + identification.id);
            vTaskDelay(TIME_READ_LOCK / portTICK_PERIOD_MS);
        }
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}
#endif
#endif

