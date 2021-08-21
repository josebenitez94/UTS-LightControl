#ifndef UTIL_SPIFFS_METODS_H
#define UTIL_SPIFFS_METODS_H

#include "FS.h"
#include "SPIFFS.h"

bool initSPIFFS(){
    return(SPIFFS.begin(true));
}

bool isFileExist(const char* path){
    File file = SPIFFS.open(path);
    if(!file || file.isDirectory()){
        return(false);
    }
    return(true);
}

String readFile(const char* path){
    File file = SPIFFS.open(path);
    String response="";
    while(file.available()){
        response += (char)file.read();
    }
    return(response);
}

bool writeFile(const char * path, String message){
    File file = SPIFFS.open(path, FILE_WRITE);
    if(file.print(message)){
        return(true);
    }
    return(false);
}

bool appendFile(const char * path, String message){
    File file = SPIFFS.open(path, FILE_APPEND);
    if(file.print(message)){
        return(true);
    }
    return(false);
}

bool deleteFile(const char * path){
    if(SPIFFS.remove(path)){
        return(true);
    }
    return(false);
}

#endif