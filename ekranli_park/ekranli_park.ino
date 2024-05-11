#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 9;
const int echoPin = 10;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD adresi (genellikle 0x27 veya 0x3F olabilir), sütun sayısı ve satır sayısı

const int buzzerPin = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.init();          // LCD başlatma
  lcd.backlight();     // Arka ışığı aç
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mesafe: ");
  lcd.print(distance);
  lcd.print("cm");

  if (distance < 20) {
    tone(buzzerPin, 1000);
  } else if (distance < 50) {
    tone(buzzerPin, 1000);
    delay(50);
    noTone(buzzerPin);
    delay(50);
  } else if (distance < 100) {
    tone(buzzerPin, 750);
    delay(100);
    noTone(buzzerPin);
    delay(100);
  } else if (distance < 200) {
    tone(buzzerPin, 500);
    delay(300);
    noTone(buzzerPin);
    delay(300);
  } else {
    noTone(buzzerPin);
  }
  
  delay(100);
}