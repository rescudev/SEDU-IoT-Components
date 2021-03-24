/*
  switchSec

  En este programa vamos a añadir la funcionalidad de un switch al secuenciador de leds. Haremos una comprobación mediante un 
  bloque if y la secuencia del leds del bucle se ejecutará únicamente si el switch está pulsado. Si la secuencia de iluminación
  aún no ha terminado cuando dejamos de pulsar el switch ésta sigue ejecutándose hasta terminar la iteración actual del bucle.
  
}
*/

int SWITCH = 4; //Definimos el pin del switch

int leds[4]= {5,6,7,8}; 

void setup() {
  for(int i=0; i<sizeof(leds)/sizeof(int); i++){ 
    pinMode(leds[i], OUTPUT);                  
  }         
  pinMode(SWITCH, INPUT);  //Definimos el modo del pin como input, lo usaremos como entrada.                                  
}

void loop() {
  secuencial(); 
}

void secuencial(){
  if(digitalRead(SWITCH) == 1){ //Haciendo uso del método digitalRead() podemos leer el pin del switch. Al estar pulsado el switch se cumple la condición y entra en el bucle.
    for(int i=0; i<sizeof(leds)/sizeof(int); i++){ 
      digitalWrite(leds[i], HIGH);                 
      delay(200);
      digitalWrite(leds[i], LOW);
    }
  }   
}
