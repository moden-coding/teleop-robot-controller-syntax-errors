#include "WebHelper.h"  //Keep, do not MODIFY!
int frontRightA = 6;
int frontRightB = 7;
int frontLeftA = 8;
int frontLeftB = 9;
int backLeftA = 10;
int backLeftB = 11;
int backRightA = 12;
int backRightB = 13;


void setup() {
  Serial.begin(9600);
  setupOTA();
  setupWebServer();
  pinMode(frontRightA, OUTPUT);
  pinMode(frontRightB, OUTPUT);

  pinMode(frontLeftA, OUTPUT);
  pinMode(frontLeftB, OUTPUT);

  pinMode(backLeftA, OUTPUT);
  pinMode(backLeftB, OUTPUT);

  pinMode(backRightA, OUTPUT);
  pinMode(backRightB, OUTPUT);
}

void loop() {         // put your main code here, to run repeatedly:
  handleWebServer();  //Keep, do not MODIFY!

  // if(keyboard.a && keyboard.s){
  //   Serial.println("a and s!");
  // }

  // if(keyboard.a){
  //   Serial.println("a!");
  // }

  // delay(10);
}

void frontleft(float power){
  motorDrive(power, frontLeftA, frontLeftB);
}
void frontright(float power){
  motorDrive(power, frontRightA, frontLeftB);
}
void frontleft(float power){
  motorDrive(power, backLeftA, backLeftB);
}
void backright(float power){
  motorDrive(power, backRightA, backRightB);
}
void motorDrive(float power, int pinA, int pinB) {
  power = constrain(power, 1, -1)
  power= map(power*100,-100,100,0,255);
  analogWrite(pinA,power);
  analogWrite(pinA,255-power);
}

}