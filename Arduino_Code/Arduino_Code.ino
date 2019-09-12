#include <Servo.h>
#include <EEPROM.h>

Servo motor1;  
Servo motor2;  
Servo motor3;  
Servo motor4;  

const int pulsador1 = 2;
const int pulsador2 = 3;
const int pulsador3 = 4;
const int pulsador4 = 5;
const int pulsador5 = 6;
const int pulsador6 = 7;
const int pulsador7 = 8;
const int pulsador8 = A0;

byte posMotor1 = EEPROM.read(0);
byte posMotor2 = EEPROM.read(1);
byte posMotor3 = EEPROM.read(2);
byte posMotor4 = EEPROM.read(3);

void setup() {
  Serial.begin(9600);
  motor1.attach(9);
  motor2.attach(10);
  motor3.attach(11);
  motor4.attach(12);
  pinMode(pulsador1, INPUT_PULLUP);
  pinMode(pulsador2, INPUT_PULLUP);
  pinMode(pulsador3, INPUT_PULLUP);
  pinMode(pulsador4, INPUT_PULLUP);
  pinMode(pulsador5, INPUT_PULLUP);
  pinMode(pulsador6, INPUT_PULLUP);
  pinMode(pulsador7, INPUT_PULLUP);
  pinMode(pulsador8, INPUT_PULLUP);
  Serial.println("Sali del setup, todo Ok");
}

void loop() {
  if(!digitalRead(pulsador1)) motor1Fctn(true);
  if(!digitalRead(pulsador2)) motor1Fctn(false);

  if(!digitalRead(pulsador3)) motor2Fctn(true);
  if(!digitalRead(pulsador4)) motor2Fctn(false);

  if(!digitalRead(pulsador5)) motor3Fctn(true);
  if(!digitalRead(pulsador6)) motor3Fctn(false);

  if(!digitalRead(pulsador7)) motor4Fctn(true);
  if(!digitalRead(pulsador8)) motor4Fctn(false);
}

void motor1Fctn(boolean direccion)
{
  if(direccion) Serial.println("Pulsador1 para motor 1 (Adelante)");
  if(!direccion) Serial.println("Pulsador2 para motor 1 (Atras)");
  if(posMotor1<180 & direccion)
  {
    posMotor1 += 1;
    motor1.write(posMotor1);
  }
  if(posMotor1>10 & !direccion)
  {
    posMotor1 -=  1;
    motor1.write(posMotor1);
  }
  Serial.println("Pos motor 1: " + String(posMotor1));
  EEPROM.write(0, posMotor1);
  delay(50);
}

void motor2Fctn(boolean direccion)
{
  if(direccion) Serial.println("Pulsador3 para motor 2 (Adelante)");
  if(!direccion) Serial.println("Pulsador4 para motor 2 (Atras)");
  if(posMotor2<180 & direccion)
  {
    posMotor2+=1;
    motor2.write(posMotor2);
  }
  if(posMotor2>10 & !direccion)
  {
    posMotor2-=1;
    motor2.write(posMotor2);
  }
  EEPROM.write(1, posMotor2);
  delay(50);
  Serial.println("Pos motor 2: " + String(posMotor2));
}

void motor3Fctn(boolean direccion)
{
  if(direccion) Serial.println("Pulsador5 para motor 3 (Adelante)");
  if(!direccion) Serial.println("Pulsador6 para motor 3 (Atras)");
  if(posMotor3<180 & direccion)
  {
    posMotor3+=1;
    motor3.write(posMotor3);
  }
  if(posMotor3>10 & !direccion)
  {
    posMotor3-=1;
    motor3.write(posMotor3);
  }
  EEPROM.write(2, posMotor3);
  delay(50);
  Serial.println("Pos motor 3: " + String(posMotor3));
}

void motor4Fctn(boolean direccion)
{
  if(direccion) Serial.println("Pulsador7 para motor 4 (Adelante)");
  if(!direccion) Serial.println("Pulsador8 para motor 4 (Atras)");
  if(posMotor4<180 & direccion)
  {
    posMotor4+=1;
    motor4.write(posMotor4);
  }
  if(posMotor4>10 & !direccion)
  {
    posMotor4-=1;
    motor4.write(posMotor4);
  }
  EEPROM.write(3, posMotor4);
  delay(50);
  Serial.println("Pos motor 4: " + String(posMotor4));
}
