#include <dht.h>
#define dht_pino A3
dht sensor;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16, 2);

}

void loop() {

  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.print("CULTIVE BOT");
  lcd.setCursor(0, 1);
  lcd.print("FEBRACE 2018");
  delay(4000);

  sensor.read11(dht_pino);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Umidade: ");
  lcd.setCursor(0, 1);
  lcd.print(sensor.humidity);
  lcd.print(" % ");
  delay(4000); 
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.setCursor(0, 1);
  lcd.print(sensor.temperature);
  lcd.println(" C ");
  delay(4000);
  
  lcd.clear();

}
