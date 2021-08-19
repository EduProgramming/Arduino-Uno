/**
 * 경보 알림 시스템
 * analogWrite을 사용했을 때
 * tone 함수가 3번핀과 11번 핀 PWM에 영향을 줌으로 digitalWrite을 사용해야함
 * 참고: https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
 */

int PIN_BUZZER = 3;
int PIN_RED = 9;
int PIN_BLUE = 11;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop() {
  digitalWrite(PIN_BLUE, LOW);
  digitalWrite(PIN_RED, HIGH);
  tone(PIN_BUZZER, 2048, 300);
  delay(500);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_BLUE, HIGH);
  tone(PIN_BUZZER, 3024, 300);
  delay(500);
}
