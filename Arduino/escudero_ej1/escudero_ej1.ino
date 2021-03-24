/*
  secuencial

  En este programa se define una función conteniendo dos bucles que encienden y apagan los 4 leds del circuto
  de manera secuencial durante 200ms.

  Como puede observarse, al tamaño del array en los bucles debemos dividirlo por el tamaño de una variable int o de otro tipo dado el caso.
  Esto es debido a que la función sizeof() devuelve el tamaño del array en bytes y un int en arduino ocupa 2 bytes.
}
*/

int leds[4]= {5,6,7,8}; //Definimos el array de int que contiene los identificadores de los leds.

void setup() {
  for(int i=0; i<sizeof(leds)/sizeof(int); i++){ //Definimos el modo de los pines como outputs, para ello recorremos el array una vez usando la función pinMode().
    pinMode(leds[i], OUTPUT);                  
  }                                              
}

void loop() {
  secuencial(); //Llamada a nuestro método.
}

void secuencial(){
  for(int i=0; i<sizeof(leds)/sizeof(int); i++){ //En este método recorremos un bucle for en el cual encendemos el led, esperamos 200ms y apagamos ese led.
    digitalWrite(leds[i], HIGH);                 //El bucle recorre las 4 posiciones del array con lo que los leds se encenderán y apagarán de forma secuencial.
    delay(200);
    digitalWrite(leds[i], LOW);
  }
}
