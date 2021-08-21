#ifndef WIRI_PARAMETER_REGISTRO_RED
#define WIRI_PARAMETER_REGISTRO_RED

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html lang="es">
<head><meta charset="utf-8"><title> Formulario de Conexión </title><meta name="viewport" content="width=device-width, initial-scale=1.0"></head>
<body style="background: #0f4c75; line-height: 50px; vertical-align: middle;"> 
<center><div style="font-size: 250%; color: white; text-align: center; margin-bottom: 20px">Credenciales</div>
<form action="/ROUTER" style="width: 60%;padding: 50px 30px; background-color: #3282b8; border-radius: 3px 3px 3px 3px;box-sizing: border-box;">
<div><input id="ssid" type="text" placeholder="SSID" name="ssid" required style="font-family: 'Overpass', sans-serif;color: #1b262c;padding: 5px 5px 5px 10px;border-radius: 10px 10px 10px 10px; align-items: center"></div>
<div><input id="pass" type="text" placeholder="Contraseña" name="password" required style="font-family: 'Overpass', sans-serif;color: #1b262c;padding: 5px 5px 5px 10px;border-radius: 10px 10px 10px 10px; align-items: center"></div>
<div><button type="submit" title="Ingresar" style="font-family: 'Overpass', sans-serif;font-size: 110%;color:#1b262c;width: 70%;height: 40px;border: none;background-color: #bbe1fa;margin-top: 10px;">Login</button></div>
</form></center></body></html>)rawliteral";

#endif