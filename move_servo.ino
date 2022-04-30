#include <Servo.h>
Servo myservo;         // Objeto Servo
String inString = "";  // Variable para guardar la información serial

void setup() {
  myservo.attach(9);   // Servo en pin 9
  Serial.begin(9600);  // Comenzar comunicacion serial en 9600 bps
}

void loop() {
  
  // Si hay datos, se ejecuta, si no, espera
  while (Serial.available() > 0) {
    
    // El serial se lee caracter por caracter
    int val = Serial.read();  // Lee y almacena en val
    
    // Si es dígito guardar en string
    if (isDigit(val)) {
      inString += (char)val;
    }
    
    // Checar el fin de línea
    if (val == '\n'){
      
      // Convertir de string a int para mover servo
      if (inString.toInt() > 179) {
        myservo.write(179);
      } else{
        myservo.write(inString.toInt()); // Convierte string val a int
      }
      delay(15);
      inString = ""; // Reset
      
    }
  }
 
}
