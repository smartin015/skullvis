#include <Servo.h>
#include <Arduino.h>

#define EYEMIN 70
#define EYEMAX 110
#define EYEMID ((EYEMAX-EYEMIN)/2 + EYEMIN)

Servo eyeL;
Servo eyeR;

#define LEDR D8
#define LEDG D7
#define LEDB D6
/*
Servo eyeR(3);
Servo jaw(2);
Servo neckL(1);
Servo neckR(0);
*/

void setup() {
  eyeL.attach(D4);
  eyeR.attach(D3);
  Serial.begin(9600);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}


int rgb = -1;
void loop() { 
  Serial.println("Loop"); 
  rgb = (rgb + 1) % 3;
  switch(rgb) {
    case 0:
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, HIGH);
      digitalWrite(LEDB, HIGH);
      break;
    case 1:
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, LOW);
      digitalWrite(LEDB, HIGH);
      break;
    case 2:
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, HIGH);
      digitalWrite(LEDB, LOW);
      break;
  }
  int pos;
  delay(1000);
  eyeL.write(EYEMIN);
  eyeR.write(EYEMIN);
  delay(1000);
  eyeL.write(EYEMAX);
  eyeR.write(EYEMAX);
  delay(1000); 
  eyeL.write(EYEMID);
  eyeR.write(EYEMID);
  delay(1000);
}
