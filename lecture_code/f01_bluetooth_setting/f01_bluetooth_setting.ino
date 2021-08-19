#include <SoftwareSerial.h>

SoftwareSerial BT(A4, A5);
/**
 * HC06의 경우에 AT Command를 통하여 설정 변경
 * AT Command는 제조사마다 다른 점이 있음
 * 
 * 시리얼 모니터에서 보드레이트 동일하게 맞춰주고
 * line ending 없음으로 설정
 * 
 * AT -> OK
 * AT+NAME이름 -> OK+SETNAME
 * AT+RESET -> OK
 */
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {
  if (Serial.available()) {
    BT.write(Serial.read());
  }
  if (BT.available()) {
    Serial.write(BT.read());
  }
}
