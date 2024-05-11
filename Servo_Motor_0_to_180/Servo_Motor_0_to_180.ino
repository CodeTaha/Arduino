#include <Servo.h>

Servo motor;

void setup() {
  
  motor.attach(3);

}

void loop() {
  for(int i=0; i <= 180; i++){
    motor.write(i);
    delay(20);
  }
  for(int i=180; i >= 0; i--){
    motor.write(i);
    delay(20);
  }
}
