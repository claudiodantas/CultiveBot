//Teste da raspberry

#include <SoftwareSerial.h> // Monitor serial
#include <LiquidCrystal_I2C.h> //Biblioteca LCD 
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(3,0);
  lcd.setBacklight(HIGH);
  lcd.print("CultiveBot");

}

void loop() {
  delay(1000);
  Serial.println("Alô Alô vcs sabem quem sou eu");
  
  char caracter = Serial.read();

  if (caracter=='a'){
    lcd.setCursor(3,0);
    lcd.setBacklight(HIGH);
    lcd.print("CultiveBot");
    lcd.setCursor(3,1);
    lcd.print("A");
    Serial.println("Inês brasil, graças a Deus");
  }

  if (caracter=='s'){
    lcd.setCursor(3,0);
    lcd.setBacklight(LOW);
    lcd.print("CultiveBot");
    lcd.setCursor(3,1);
    lcd.print("S");
    Serial.println("Aqui é só um S mesmo");
  }

}
