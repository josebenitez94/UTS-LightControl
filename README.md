# UTS-LightControl

_Este repositorio se crea con el fin de llevar el almacenamiento y desarrollo del proyecto de Grado LightControl para optar por el titulo de Ingeniero Electronico de un cliente. El dispositivo consta de un hardware dise帽ado y desarrollado + firmware que permite la lectura de tarjetas RFID y que llevan el control del encendido-apagado de las luces de las UNIDADES TECNOLOGICAS DE SANTANDER con tecnolog铆as web PHP, Javascript y MySQL._

## Comenzando - TAREAS 馃殌

_El algoritmo FreeRTOS conlleva una arquitectura que se presenta a continuaci贸n_

* [Task 1] - WIFI :: Conexi贸n por modo ACCESSPOINT/STATION + consultas pila TCP/IP
* [Task 2] - WIFI :: Conexi贸n con servidor por servicio en PHP bidireccional
* [Task 3]() - Lectura RFID con modulo RC522
* [Task 4](http://www.dropwizard.io/1.0.2/docs/) - Control de luces led + sonido por buzzer
* [Task 5]() - Sensor de corriente ACS712 + Control de Actuador

### Pre-requisitos 馃搵

* Instalar Arduino IDE y dependencias ESP32 [Arduino IDE Windows](https://downloads.arduino.cc/arduino-1.8.15-windows.exe)
* Instalar dependencias y librerias para ESP32 en Arduino [ESP32 para Arduino] (https://iberotecno.com/blog-supratecno/47-tutoriales-paso-a-paso/108-como-instalar-esp32-en-el-ide-de-arduino-tutorial)
* Hardware **LightControlHardware** y cargarle el firmware de este repositorio
* Utilizar a la par el proyecto [UTS-LightControlWeb](https://github.com/josebenitez94/UTS-LightControlWeb)
* Abrir el archivo config/config.h con los parametros deseados

Parametros mas importantes de config.h
* URL_SERVER: Se debe colocar la url del servidor con su respectivo puerto, sino no va a funcionar nada
* VALUE_DETECT: Si no se reconoce el da帽o del bombillo, se debe bajar el valor de esta definici贸n, por defecto es 1600

## INDICADORES DE ESTADO 馃殌

* MODO ACCESS POINT: MORADO INDEFINIDO
* CONNECTION_WAITING: Esperando Conexi贸n INTERMITENTE(Cambio cada segundo)
* MODO STATION OK: VERDE SOLIDO (POR 2 SEGUNDOS)
* MODO STATION ERROR: ROJO INDEFINIDO (REALIZA UN REINICIO AUTOMATICO PASADOS 2 SEGUNDOS)
* SERVER ERROR: AMARILLO INTERMITENTE (CADA SEGUNDO POR 3 OCASIONES)
* ACCESS OK: AZUL SOLIDO (POR 3 SEGUNDOS)
* ACCESS ERROR: ROJO INTERMITENTE (CADA SEGUNDO POR 3 OCASIONES)
__

## PASOS PARA CONFIGURAR TODO EL SISTEMA 鈿欙笍
* Armar Todo el hardware requerido [Circuito Electronico](https://github.com/josebenitez94/UTS-LightControl/tree/Master/Hardware)
* Conectar conversor USB-UART
* Compilar Firmware y subir a la tarjeta [Firmware LightControl](https://github.com/josebenitez94/UTS-LightControl/tree/Master/controlIumi)
* Si es la primera vez que se usa, el hardware pasar谩 a modo AP (Luz morada)... por lo que debe conectarse a la red WIFI que se genera (LightControl-01)
* luego de darse de alta en la red, debe dirigirse a [http://192.168.4.1/REGISTER](http://192.168.4.1/REGISTER) y colocar los datos del router WIFI al cual se debe conectar y a continuaci贸n click en Login. Debe colocar el mensaje "OK, Cambiando Parametros" y tumbar la red ACCESS POINT para conectarse al router
* una vez conectado al router, el led verde se activar谩 por 3 segundos indicando que ya se encuentra satisfactoriamente conectada y lista para consultas


## Construido con 馃洜锔?

* [Arduino IDE](https://www.arduino.cc/en/software) - IDE de desarrollo de entorno Arduino
* [Visual Studio](https://visualstudio.microsoft.com/es/) - Herramienta Editor por Excelencia para Desarrolladores

## Versionado 馃搶

Para todas las versiones disponibles, mira los [tags en este repositorio](https://github.com/josebenitez94/UTS-LightControl/tags).

## Autores 鉁掞笍

* **Jose Ben铆tez** - *Ingeniero Electr贸nico y Tecn贸logo en Desarrollo de Sistemas Inform谩ticos* - [josebenitez94](https://github.com/josebenitez94)

## Licencia 馃搫

Este proyecto est谩 bajo la Licencia GPT 2.0

---
鈱笍 con 鉂わ笍 por [josebenitez94](https://github.com/josebenitez94) 馃槉
