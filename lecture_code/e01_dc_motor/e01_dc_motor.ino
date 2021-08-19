int PIN_MOTOR_FRONT = 2;
int PIN_MOTOR_BACKWARD = 4;

void setup() {
  pinMode(PIN_MOTOR_FRONT, OUTPUT);
  pinMode(PIN_MOTOR_BACKWARD, OUTPUT);

  digitalWrite(PIN_MOTOR_FRONT, HIGH); //정회전
  digitalWrite(PIN_MOTOR_BACKWARD, LOW);
  delay(3000);
  digitalWrite(PIN_MOTOR_FRONT, LOW); // 역회전
  digitalWrite(PIN_MOTOR_BACKWARD, HIGH);
  delay(3000);
  digitalWrite(PIN_MOTOR_FRONT, LOW);
  digitalWrite(PIN_MOTOR_BACKWARD, LOW);
}

void loop() {

}
