#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trig = 2;
int echo = 3;
int led = 13;  

long duration;
float distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);


  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Distance Sensor");
  delay(1500);
  lcd.clear();
}

void loop() {

  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  
  duration = pulseIn(echo, HIGH);
//distance caculation
  distance = (duration * 0.0343) / 2;
//LCD display 
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");

  lcd.setCursor(10, 0);
  lcd.print(distance, 1); 
  
  lcd.setCursor(15, 0);
  lcd.print(" ");
  


  //led control 
 lcd.setCursor(9,0);
  lcd.print(distance);
  if (distance <= 100){
    lcd.setCursor(0,1);
    lcd.print("Hello");
  }else{
    lcd.setCursor(0,1);
    lcd.print("              ");
  }
  
}