#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 10;
const int echoPin = 9;
const int buzzerPin = 8;
const int ledPin = 7;
int sayac = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  lcd.init();          // LCD başlatma
  lcd.backlight();     // Arka ışığı aç
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;1sxwde
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mesafe: ");
  lcd.print(distance);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  lcd.print("Sayac: ");
  lcd.print(sayac);
  
  if (distance < 70){
  	tone(buzzerPin, 1000);
    digitalWrite(ledPin, 1);
    delay(100);
    noTone(buzzerPin);
    sayac = sayac + 1;
    delay(3000);
  }
}