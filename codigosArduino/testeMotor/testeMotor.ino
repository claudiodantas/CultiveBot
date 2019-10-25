#include <SoftwareSerial.h> // Monitor serial

int rele = 12;

void setup()
{
  //início da comunicação serial
  Serial.begin(9600); 
  
  //relé
  pinMode(rele, OUTPUT);
  digitalWrite(rele, 1);
}

void loop()
{
  char caracter = Serial.read();
  if (caracter == 'a'){
    Serial.println("Ligado");
    digitalWrite(rele, 0);
    delay(1000);
  }
  if (caracter == 'b'){
    Serial.println("Desligado");
    digitalWrite(rele, 1);
  }
  
}
