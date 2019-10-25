#include <dht.h>

#define dht_pino A3

dht sensor;

void setup() {
  Serial.begin(9600);
  Serial.println("-- Teste do Sensor de Umidade e Temperatura --");
}

void loop() {
  delay(2000);
  
  sensor.read11(dht_pino);

    Serial.print("Umidade: ");
    Serial.print(sensor.humidity);
    Serial.print(" % ");
    Serial.print("Temperatura: ");
    Serial.print(sensor.temperature);
    Serial.println(" °C");
}
