#ifndef config_config
#define config_config

#define DEBUG_MODE
//***********************MODO AP*************************
#define SSID_AP         "LightControl-01"
#define PASS_AP         ""
#define PORT_AP_STA     80
#define CREDENTIALS_SPIFFS "/credentials.txt"
#define INTENT_CONNECT_TIME 15 //15 segundos para tratar de conectar
#define INTENT_UNTIL_RESET 3   //intentos de conexion maximos
#define URL_SERVER  "http://192.168.1.2:82/"  
#define PAGE_INSERTAR_PHP "UTS-LightControlWeb/php/insertar.php"
//***********************TAREAS**************************
#define enable_task1
#define enable_task2
#define enable_task3
#define enable_task4
#define enable_task5
//***********************OTROS***************************
#define TIME_READ_LOCK 2000

#endif