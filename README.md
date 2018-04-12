# Practica3 Conexion Java-Arduino
***
## Indice
+ [Despripcion](#Descripcion)
+ [Material](#Material)
+ [Archivos](#Archivos)
+ [Nota](#Nota)
+ [Contacto](#Contacto)
***
## Descripcion
Este programa  ejemplifica una conexion entre java y arduino en la cual habra una interface en java
que tendra el menu de opciones enumeradas: 1 hora ,2 temperatura ,3 intensidad de luz ,4 mensaje.
Funcionara de la siguiente manera en el protoboard habla 2 botones uno es uno incrementara un contador 
 que inicialmente estara en 1 que servira como indice para saber que opcion escojer con 
respecto al menu y el otro boton funcionara como un selector el cual al precionarlo realizara 
la opcion marcada y se mostrara en la pantalla lcd.

|id|menu|descripcion|
|--|----|-----------|
|1 |hora |muetra la hora del sistema desde java|
|2 |temperatura|muestra la temperatura desde arduino|
|3 |intensidad de luz|muestra la intersidad de luz desde arduino|
|4 |mesnaje|en la interface de java escribes un menaje y se muestra en la lcd|
***
## Material
1. placa protoboard
2. arduino uno/cualquier otro arduino
3. cable usb de arduino
4. resistencias 10k ohms(3)
5. potenciometro 
6. push boton(2)
7. fotoresistor 
8. sensor de temperatura LM35
9. pantalla lcd 16x2
10. cables para puentear (para protoboard)
***
## Archivos 
* readme: contiene la informacion de lo que realiza  el programa junto con informacion necesaria como el material.
* imagenes: en esta carpeta se encuentra la evidencia del cirduito en fisico y funcionando.
* TempLuz.fz:contiene el diagrama del circuito realizado en el programa fritzing (**requiere tener fritzing para poderlo abrir**).
* Mensajes3.ino: Contiene el codigo de arduino.
* Int1.java: Contiene la interface grafica de llava la cual  requerira  la libreria **PanamaHitek_Arduino-3.0.0.jar**.
* PanamaHitek_Arduino-3.0.0.jar: Esta libreria se agrega al paquete de java dando click derecho en la carpeta de librerias agregar libreria jar.
***
## Nota
Los documentos de java estan hechos en netbeans por lo que  requerira  la descarga e instalacion de netbeans junto con los otros software como son **arduino** y **fritzin**.
***
## Contacto
 correo electronico:321ctorres@gmail.com
 
 nombre: Manuel Alejandro Torres Fonseca
