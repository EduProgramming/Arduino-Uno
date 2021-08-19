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
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {
  float distance = getDistance();
  Serial.println(distance);
}
