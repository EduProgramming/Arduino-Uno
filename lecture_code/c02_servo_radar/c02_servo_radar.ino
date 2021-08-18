#include <Servo.h>

#define PIN_SERVO       9
int angle = 0;
int sw = 1;

Servo servo;

void setup() {
  servo.attach(PIN_SERVO);
}

void loop() {
  servo.write(angle);
  delay(10);
  angle += sw;
  if (angle == 180) {
    sw = -1;
  } else if (angle == 0) {
    sw = 1;
  }
}
