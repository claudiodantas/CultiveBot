// SISTEMA DE PLANTAÇÃO INTELIGENTE

// -- BIBLIOTECAS AUXILIARES --
#include <SoftwareSerial.h> // Monitor serial
#include <dht.h> // biblioteca do sensor de umidade e temperatura
#include <LiquidCrystal_I2C.h> //Biblioteca LCD

// -- DEFINIÇÕES --
// sensor dht
#define dht_pino A3
dht sensor;

//sensor do solo
#define sensor_solo A0
float umidade_solo;

//módulo relé
int rele = 12;

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

//Pinos de ligacao ponte H L298N
//Motor Y
int IN1 = 6;
int IN2 = 7;
//Motor X
int IN3 = 8;
int IN4 = 9;
//Motor Z
int IN5 = 4;
int IN6 = 3;

void setup() {
  Serial.begin(9600);
  Serial.println("CultiveBot");
  lcd.begin(16, 2);
  lcdHome();
  
  //Definicao pinos ponte H
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);

  //sensor umidade do solo
  pinMode(sensor_solo, INPUT);

  //relé
  pinMode(rele, OUTPUT);
  digitalWrite(rele, 1);
}

// -- CÓDIGO DO LOOP --
void loop() {
char caracter = Serial.read();
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);

  // Testes de movimentação por teclado
  if (caracter == 'a') {
    Serial.println("Eixo Y para frente");
    forwardEixoY();
    lcdHome();
  }

  if (caracter == 's') {
    Serial.println("Eixo Y para trás");
    backEixoY();
    lcdHome();
  }

  if (caracter == 'x') {
    Serial.println("Eixo X para direita");
    rightEixoX();
    lcdHome();
  }

  if (caracter == 'z') {
    Serial.println("Eixo X para esquerda");
    leftEixoX();
    lcdHome();
  }
  
  if (caracter == 'c') {
    Serial.println("Eixo Z para baixo");
    upEixoZ();
    lcdHome();
  }

  if (caracter == 'd') {
    Serial.println("Eixo Z para cima");
    downEixoZ();
    lcdHome();
  }

  if (caracter == 'p'){
    Serial.println("Parar");
    parar();
    lcdHome();
  }

  if (caracter == 't'){
    Serial.println("informações dos Sendores");
    lcd.setCursor(0,0);
    lerTemperatura();
    lcd.setCursor(0,1);
    lerUmidade();
    delay(4000);
    lcd.clear();
    lcd.setCursor(0,0);
    umidadeSolo();
    delay(4000);
    lcdHome();
  }

  if (caracter == 'i'){
    Serial.println("irrigando");
    irrigar();
    lcdHome();
  }

  if (caracter == 'o'){
    Serial.println("irrigando");
    irrigarStop();
    lcdHome();
  }

  if (caracter == 'w'){
    Serial.println("planta 1");
    irPlanta1();
    lcdHome();
  }  
  
}

// -- MOVIMENTAÇÃO DOS MOTORES --

// -- EIXO Y --
void forwardEixoY (){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Eixo Y");
  lcd.setCursor(0,1);
  lcd.print("FRENTE");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(1000);
}

void backEixoY (){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Eixo Y");
  lcd.setCursor(0,1);
  lcd.print("TRAS");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(1000);
}

// -- EIXO X --
void leftEixoX (){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Eixo x");
  lcd.setCursor(0,1);
  lcd.print("ESQUERDA");
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1000);
}

void rightEixoX (){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Eixo x");
  lcd.setCursor(0,1);
  lcd.print("DIREITA");
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1000);
}

// -- EIXO Z --
void upEixoZ (){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Eixo Z");
  lcd.setCursor(0,1);
  lcd.print("CIMA");
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  delay(1000);
}

void downEixoZ (){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Eixo Z");
  lcd.setCursor(0,1);
  lcd.print("BAIXO");
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  delay(1000);
}

// -- PARAR --
void parar(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Eixos parados");
  lcd.setCursor(0,1);
  lcd.print(":)");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  delay(1000);
}


// -- MOVIMENTAÇÃO DOS MOTORES ATÉ AS PLANTAS

void irPlanta1 (){
  for(int i = 0; i < 6; i ++){
    forwardEixoY();
  }
  for(int i = 0; i < 5; i ++){
    rightEixoX();
  }
  for(int i = 0; i < 4; i ++){
    downEixoZ();
  }

  for(int i = 0; i < 6; i ++){
    backEixoY();
  }
  for(int i = 0; i < 5; i ++){
    leftEixoX();
  }
  for(int i = 0; i < 4; i ++){
    upEixoZ();
  }
}

void irPlanta2 (){
  
}

void irPlanta3 (){
  
}

// -- ANÁLISE DOS SENSORES --

void lerUmidade() {
  sensor.read11(dht_pino);
  Serial.print("Umidade: ");
  Serial.print(sensor.humidity);
  Serial.print(" % ");
  lcd.print("Umidade: ");
  lcd.print(sensor.humidity);
  lcd.print(" % ");
}

void lerTemperatura() {
  sensor.read11(dht_pino);
  Serial.print("Temperatura: ");
  Serial.print(sensor.temperature);
  Serial.println(" °C");  
  lcd.print("Temp: ");
  lcd.print(sensor.temperature);
  lcd.print(" C");  
}

void umidadeSolo(){
  umidade_solo = analogRead(sensor_solo);
  int porcentagemUmidade = ((umidade_solo)/1024)*100;
  Serial.print("Umidade do solo: ");
  Serial.print(porcentagemUmidade);
  Serial.print(" %");  
  lcd.print("Solo: ");
  lcd.print(porcentagemUmidade);  
  lcd.print(" % ");
}

void irrigar(){
  Serial.println("Irrigando");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.println("Irrigando");
  digitalWrite(rele, 0);
}

void irrigarStop(){
  digitalWrite(rele, 1); 
}

void lcdHome(){
   lcd.clear();
   lcd.setCursor(3,0);
   lcd.print("CULTIVEBOT");
   lcd.setCursor(2, 1);
   lcd.print("FEBRACE 2018");
}

