void setup() {

pinMode(A0, INPUT);
pinMode(6, OUTPUT);
Serial.begin(9600);

}

void loop() {
  if (analogRead(A0) < 100){
    digitalWrite(6, HIGH);
  }
  else {
    digitalWrite(6, LOW);
  }
  Serial.println(analogRead(A0));
  delay(300);

  delay(10);

}
