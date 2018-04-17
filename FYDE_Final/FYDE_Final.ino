//www.elegoo.com
//2016.06.13

#define STEP_NUMBER 1

#include <Wire.h>
#include "rgb_lcd.h"

int Led = 13;//define LED port
int speaker = 7;
int light = 8;
int sensorPin = 3; //define switch port
int val;//define digital variable val
int check;
int arm = 0;
int blynk = 19;

rgb_lcd lcd;

 int colorR = 0;
 int colorG = 255;
 int colorB = 0;

void setup(){
  pinMode(Led,OUTPUT);//define LED as a output port
  pinMode(sensorPin,INPUT);//define switch as a output port
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
    lcd.print("You Gucci");

  pinMode(13, OUTPUT);
  pinMode(blynk, INPUT);
  check = 0;
}

void loop(){ 
  val=digitalRead(sensorPin);//read the value of the digital interface 3 assigned to val 
  int disarm = digitalRead(blynk);

  while(disarm == LOW){
    colorR = 0;
    colorG = 255;
    colorB = 0;
    lcd.setCursor(0, 0);
    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("Disarmed       ");
    digitalWrite(speaker,LOW);
    digitalWrite(light, HIGH);
  }
  
  Serial.println(val);
  
  if(val==LOW && check == 0){
    digitalWrite(speaker,HIGH);
    digitalWrite(light,HIGH);
    colorR = 255;
    colorG = 0;
    colorB = 0;
    lcd.setCursor(0, 0);
    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("FUCK OFF, THIEF!");
    check = 1;
  }else if(val == LOW && check == 1){
  }else if(val == HIGH && check == 1){
    digitalWrite(speaker,LOW);
    digitalWrite(light, LOW);

    colorR = 0;
    colorG = 0;
    colorB = 255;
    lcd.setCursor(0, 0);
    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("Armed           ");
    check = 0;
  }else if(val == HIGH && check == 0){
  }
  Serial.println(check);
}

