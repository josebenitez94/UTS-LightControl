# UTS-LightControl

_Este repositorio se crea con el fin de llevar el almacenamiento y desarrollo del proyecto de Grado LightControl para optar por el titulo de Ingeniero Electronico de un cliente. El dispositivo consta de un hardware diseñado y desarrollado + firmware que permite la lectura de tarjetas RFID y que llevan el control del encendido-apagado de las luces de las UNIDADES TECNOLOGICAS DE SANTANDER con tecnologías web PHP, Javascript y MySQL._

## Comenzando - TAREAS 🚀

_El algoritmo FreeRTOS conlleva una arquitectura que se presenta a continuación_

* [Task 1] - WIFI :: Conexión por modo ACCESSPOINT/STATION + consultas pila TCP/IP
* [Task 2] - WIFI :: Conexión con servidor por servicio en PHP bidireccional
* [Task 3]() - Lectura RFID con modulo RC522
* [Task 4](http://www.dropwizard.io/1.0.2/docs/) - Control de luces led + sonido por buzzer
* [Task 5]() - Sensor de corriente ACS712 + Control de Actuador

### Pre-requisitos 📋

* Instalar Arduino IDE y depencias ESP32 [Arduino IDE Windows](https://downloads.arduino.cc/arduino-1.8.15-windows.exe)
* Instalar dependencias y librerias para ESP32 en Arduino
* Hardware **LightControlHardware** y cargarle el firmware de este repositorio
* Utilizar a la par el proyecto [UTS-LightControlWeb](https://github.com/josebenitez94/UTS-LightControlWeb)
* Abrir el archivo config/config.h con los parametros deseados

## INDICADORES DE ESTADO ⚙️

* MODO ACCESS POINT: MORADO INDEFINIDO
* CONNECTION_WAITING: Esperando Conexión INTERMITENTE(Cambio cada segundo)
* MODO STATION OK: VERDE SOLIDO (POR 2 SEGUNDOS)
* MODO STATION ERROR: ROJO INDEFINIDO (REALIZA UN REINICIO AUTOMATICO PASADOS 2 SEGUNDOS)
* SERVER ERROR: AMARILLO INTERMITENTE (CADA SEGUNDO POR 3 OCASIONES)
* ACCESS OK: AZUL SOLIDO (POR 3 SEGUNDOS)
* ACCESS ERROR: ROJO INTERMITENTE (CADA SEGUNDO POR 3 OCASIONES)
__

## Construido con 🛠️

* [Arduino IDE](https://www.arduino.cc/en/software) - IDE de desarrollo de entorno Arduino
* [Visual Studio](https://visualstudio.microsoft.com/es/) - Herramienta Editor por Excelencia para Desarrolladores

## Versionado 📌

Para todas las versiones disponibles, mira los [tags en este repositorio](https://github.com/josebenitez94/UTS-LightControl/tags).

## Autores ✒️

* **Jose Benítez** - *Ingeriero Electronico y Tecnologo en Desarrollo de Sistemas Informaticos* - [josebenitez94](https://github.com/josebenitez94)

## Licencia 📄

Este proyecto está bajo la Licencia GPT 2.0

---
⌨️ con ❤️ por [josebenitez94](https://github.com/josebenitez94) 😊
