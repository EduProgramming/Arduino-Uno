#include <SoftwareSerial.h>

SoftwareSerial BT(A4, A5);
int PIN_LED = 11;

void setup() {
  BT.begin(9600);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  if (BT.available()) {
    char cmd = BT.read(); // char -> character 문자 타입
    /**
     * a 문자가 올 때: 파란색 불 ON 
     * b 문자가 올 때: 파란색 불 OFF
     */
    if (cmd == 'a') {
      digitalWrite(PIN_LED, HIGH);
    } else if (cmd == 'b') {
      digitalWrite(PIN_LED, LOW);
    }
  }
}
