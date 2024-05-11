const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  if (distance < 20) {
      tone(buzzerPin, 1000);
  }
  else if (distance < 50) {
      tone(buzzerPin, 1000);
      delay(50);
      noTone(buzzerPin);
      delay(50);
  }
  else if (distance < 100) {
      tone(buzzerPin, 750);
      delay(100);
      noTone(buzzerPin);
      delay(100);
  }else if (distance < 200) {
      tone(buzzerPin, 500);
      delay(300);
      noTone(buzzerPin);
      delay(300);
  }
  else {
    noTone(buzzerPin);
  }
  
  delay(100);
}
