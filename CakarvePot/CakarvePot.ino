void setup() {

  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
  delay(200);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(5, LOW);
  delay(200);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  delay(200);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(200);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

  int oku = analogRead(A0);
  float gerilim = (5.00 / 1024.00) * oku;

  Serial.println(oku);
  delay(100);

  Serial.println(gerilim);
  delay(100);
                    // wait for a second
}
