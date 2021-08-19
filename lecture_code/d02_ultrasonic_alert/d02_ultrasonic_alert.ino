/**
 * 경보 알림 시스템
 * 15cm 이내에 접근하면 소리와 빨강 LED ON
 * 밖으로 벗어나면 OFF
 */

int PIN_BUZZER = 3;
int PIN_LED = 9;
int PIN_TRIG = 12;
int PIN_ECHO = 13;

float getDistance() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  float duration = pulseIn(PIN_ECHO, HIGH); // 걸린 시간
  // 걸린 시간 * 상온의 초음파 속도 / 2 = 편도 거리(단위 cm)
  // 상온의 초음파 속도를 29로 나눠주면 작은 오차범위를 제외하고 거의 유사(cm단위로 진행)
  return duration / 29.0 / 2;
}

void setup() {
  Serial.begin(9600); // 시리얼 모니터 사용 -> 1초에 9600bit 통신 속도
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {
  float distance = getDistance();
  if (distance < 15) {
    digitalWrite(PIN_LED, HIGH);
    tone(PIN_BUZZER, 2048);
  } else {
    digitalWrite(PIN_LED, LOW);
    noTone(PIN_BUZZER);
  }
}
