 /*--------------------------------------------------------------------------------------------------
 * Conexion entre arduino y java
 * -------------------------------------------------------------------------------------------------
 * Programa que ejemplifica una conexion entre java y arduino en la cual habra una interface en java
 * que tendra el menude opciones enumeradas: 1 hora ,2 temperatura ,3 intensidad de luz ,4 mensaje.
 * Funcionara de la siguiente manera en el protoboard habla 2 botones uno es uno incrementara un 
 * numero que inicialmente estara en 1 que servira como indice para saber que opcion escojer con 
 * respecto al menu y el otro boton funcionara como un selector el cual al precionarlo realizara 
 * la opcion marcada y se mostrara en la lcd.
 *      1 hora---muetra la hora del sistema desde java
 *      2 temperatura---muestra la temperatura desde arduino
 *      3 intensidad de luz---muestra la intersidad de luz desde arduino
 *      4 mesnaje---en la interface de java escribes un menaje y se muestra en la lcd.
 *
 *Sistemas Programables
 *Manuel Alejandro Torres Fonseca
 *11 de Abril del 2018
 *--------------------------------------------------------------------------------------------------
 */
  //inicia la importacion de librerias
//incluir la libreria LiguidCrystal que nos permitira usar la pantalla lcd
#include <LiquidCrystal.h>
  //termina la importacion de librerias
  
  //inicia la declaracion de variables y constantes 
//se declaran las variables que tienen los  pines que se usaran para la pantalla lcd
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//las variables se agregar como parametro para el metodo que llamara la pantalla lcd
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//se indica que pin usara el boton de arriba del protoboard
int btnarriba=9;
//se indica que pin usara el boton de abajo del protoboard
int btnabajo=8;
//se indica que pin usara la fotoresistor
int pinLuz=1;
//se inicializa la variable que contendra la intensidad de la luz
int valorLuz=0;
//inicializa el contador que permitira saber que opcion del menu  se usara 
int cont=1;
//declara la variable que tendra la entrada analogica para el sensor de temperatura
int dato;
//inicializa la varible que se encargara de los calculos de la temperatura
float c=0;
  //fin de la declaracion de variables y constantes

//inicia el metodo  setup 
void setup() {
  //indica el tamaño de la lcd en este caso es 16x2
  lcd.begin(16, 2);
  //inicializar la comunicacion serial
  Serial.begin(9600);
  //indica que  el botonarriba enviara pulsos que recivira el arduino
  pinMode(btnarriba,INPUT);
  //inidica que el botonabajo enviara pulsos que recivira el arduino
  pinMode(btnabajo,INPUT);
//termina el metodo setup 
}

//inicia el metodo  que se repetira 
void loop() {
  //valorLuz guarda el valor que obtiene el fotoresistor
  valorLuz= analogRead(pinLuz);
  //inicia la condicion  que indica que realizara el programa cuando reciva algun dato por comunicacion seriar desde la de java 
  if (Serial.available()){
        //ya que pudo recivir un dato de la comunicacion serial se espera 100 milisegundos
        delay(100);
         //deja la pantalla lcd en vacia
         lcd.clear();
            //inicia  la condicion cuando el valor del contador es 1(opcion 1 del menu de java)        
            if(cont==1){
               //manda el mensaje en la parte superior de la pantalla lcd
               lcd.print("hora");
               //manda el cursor en el inicio del siguiente renglon de la pantalla lcd               
               lcd.setCursor(0,1);
            //termina la condicion cuando el valor del contador es 1 (opcion 1 del menu de java)
            }
            //inicia la condicion cuando el valor del contador es 2  (opcion 2 del menu de java)        
            if(cont==2){
                //pone el cursor al principio del segundo renglon  de la pantalla lcd               
                lcd.setCursor(0,1);
                //imprime en la pantalla lcd el valor de la temperatura                
                lcd.print(c);
                //pone el cursor al principio del primer renglon de la pantalla lcd                
                lcd.setCursor(0,0);
            //termina  la condicion cuando el valor del contador es 2 (opcion 2 del menu de java)
            }
              //inicia la condicion cuando el valor del contador es 3 (opcion 3 del menu de java)            
              if(cont==3){
                 //pone el curdor al principio del segundo renglon de la pantalla lcd              
                 lcd.setCursor(0,1);
                 //imprime en la pantalla lcd el valor de la intensidad de la luz                 
                 lcd.print(valorLuz);
                 //pone el cursor al principio del primer renglon de la pantalla lcd                 
                 lcd.setCursor(0,0);
              //termina la condicion cuando el valor del contador es 3 (opcion 3 del menu de java)              
              }
               //inicia la condicion cuando el valor del contador es 4 (opcion 4 del menu de java)              
               if(cont==4){
                  //pone el cursor al principio del primer renglon de la pantalla lcd                  
                  lcd.setCursor(0,0);
                  //imprime  mensaje en la pantalla lcd                  
                  lcd.print("mensaje");
                  //pone el cursor al principio del segundo renglon de la pantalla lcd                  
                  lcd.setCursor(0,1);
               //termina la condicion cuando el valor del controlador  es 4 (opcion 4 del menu de java)                
               }
                
              //inicia el ciclo que repite el mensaje que recive de java  hasta que se imprima toda la palabra 
              while (Serial.available() > 0){
                     //imprime en la pantalla lcd un letra del mensaje que mando de java
                     lcd.write(Serial.read());
              //termina el ciclo que repite el mensaje que recive de java 
              }
//termina la condicion  que indica que realizara el programa cuando reciva algun dato por comunicacion seriar desde la de java              
}
  //inicia la condicion que indica que hara cuando se apriete el botonarriba
  if ( digitalRead(btnarriba) == HIGH ){ 
       //inicia la condicion cuando el contador tiene el valor de alguna de las opciones del menu de java
        if(cont<=4){
            //incrementa el contador para indicar que sera la siguiente opcion del menu de java
            cont++;
        //temina la condicion cuando el contador tiene el valor de alguna de las opciones del menu de java 
        }else{
          //en caso de que no tenga una de las opciones del menu de java te mandara a la primera opcion 
          cont=1;
        //temina la condicion cuando el contador no es una de las opciones del menu de java  
        }
        //espera 1 segundo para procesar lo que preciono
       delay(1000);
 //termina la condicion que indica que hara cuando se apriete el botonarriba     
 }
//inicia la condicion que indica lo que hara cuando se apriete  el botonabajo
 if ( digitalRead(btnabajo) == HIGH ){
        //inicia la condicion cuando la opcion del menu de java es la 1
        if(cont==1){
           //mediante la comunicacion serial manda a  java el valor del contador
           Serial.println(cont);
           //espera medio segundo
           delay(500);
       //termina la condicion cuando la opcion del menu java es la 1   
       }
       //inica la condicion cuando la opcion del menu de java es la 2
       else if(cont==2){
               //indica que el valor del dato es lo que reciva del dispositivo de temperatura 
               dato = analogRead(A0);
               //realiza el calculo para calcular la temperatura en grados centigrados 
               c = (500.0 * dato)/1023;
               //mediante la comunicacion serial manda a java el valor del contador
               Serial.println(cont); 
               //espera medio segundo
               delay(500);
       //termina la condicion cuando la opcion del menu de java es la 2   
       }
       //inicia la condicion cuando la opcion del menu de java es 3
       else if(cont==3){
              //pone el cursor al principio del segundo renglon de la pantalla lcd
               lcd.setCursor(0,1);
               //imprime en la pantalla lcd el valor de la intensidad de la luz
               lcd.print(valorLuz);
               //pone el cursor al principio del primer renglon de la pantalla lcd
               lcd.setCursor(0,0);
               //mediante la comunicacion serial manda a java el valor del contador
               Serial.println(cont); 
               //espera medio segundo
               delay(500);
       //termina la condicion cuando la opcion del menu de java es 3   
       }
       //inicia la condicion cuando la opcion del menu de java es 4
       else if(cont==4){
               //mediante la comunicacion serial  manda a java el valor del contador
               Serial.println(cont);
               //espera medio segundo
               delay(500);
        //termina la condicion cuando la opcion del menu de java es 4
        }else{
               //en caso de que la opcion del menu de java sea mayor a 4 va poner la opcion 1
               cont=1;
               //pone el cursor al principio del primer renglon de la pantalla lcd
               lcd.setCursor(0,0);
               //imprime en la pantalla lcd el mensaje de hora
               lcd.print("hora");
               //mediante la comunicacion serial manda a java el valor del contador
               Serial.println(cont);
               //pone el cursor al princio del segundo renglon de la pantalla lcd
               lcd.setCursor(0,1);
               //espera medio segundo
               delay(500);
       //termina la condicion cuando la opcion del menu de java es mayor a 4
       }
  //termina la condicion que indica lo que hara cuando se apriete  el botonabajo    
 }
//termina el metodo  que se repetira 
}


