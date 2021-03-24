/*
  LDRMeasure

  En este programa hacemos uso de una resistencia variable LDR. Este tipo de resistencia es sensible a la luz y nos ofrecerá un valor de lectura analógica diferente
  según la incidencia de la luz sobre su superficie. Una vez sabemos este valor lo usaremos para determinar la intensidad de brillo de 3 LEDS conectados a puertos digitales
  con funcionalidad PWM. Gracias a esta funcionalidad asignaremos un valor entre 0 y 255 a cada LED según en rango de valor marcado por la resistencia LDR.

  El resultado será una variación dinámica de la luminosidad de todos los LEDs al mismo tiempo. A más oscura quede la habitación donde se encuentra el sensor mayor serán
  la intensidad mostrada por nuestros LEDs.
}
*/

int LDR = A0; //Definimos el pin de lectura de la resistencia.
int leds[3]= {9,10,11}; 
int valLDR = 0; //Inicializamos la variable en la que guardaremos el valor de lectura.

void setup() {
  Serial.begin(9600); //Inicializamos el puesrto serie con un valor de refresco.
}

void loop() {
  valLDR = analogRead(LDR);  //La función analogRead() nos permite leer valores analógicos.
  Serial.println(valLDR);   //Vamos a mostrar el valor analógico de la resistencia en el puerto serie.
  for(int i=0; i<sizeof(leds)/sizeof(int); i++){
    if(valLDR>=768 && valLDR<=1023){                  //Aquí definimos 4 bloques condicionales en los que, tras leer el valor de la resistencia LDR haremos uso de la función analogWrite() sobre los pins de nuestros LEDS.                                                 
        analogWrite(leds[i], 64);                     //Con el fin de reutilizar código vamos a hacer uso del bucle for de escritura sobre pines.
    }
    if(valLDR>=512 && valLDR<=767){
        analogWrite(leds[i], 127);                   
    }
    if(valLDR>=256 && valLDR<511){
        analogWrite(leds[i], 191);                  
    }
    if(valLDR>=0 && valLDR<=255){
        analogWrite(leds[i], 255);                  
    }
  }    
}
