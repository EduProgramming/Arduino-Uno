int PIN_RELAY = 12;

/**
 * NO: Normally Open
 * NC: Normally Close
 * 
 * NO는 평상시에 열려 있고, NC는 평상시에 닫혀있습니다.
 * 그러나, 제조사마다 릴레이를 만들때 해당 부분을 거꾸로 만드는 곳도 있습니다.
 * 이점 참조하시길 바랍니다.
 */

void setup() {
  pinMode(PIN_RELAY, OUTPUT);

  digitalWrite(PIN_RELAY, HIGH);
  delay(3000);
  digitalWrite(PIN_RELAY, LOW);
}

void loop() {
  
}
