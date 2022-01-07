/*
 * 아두이노 대포가습기 확장
 * Author: TaeJune Joung
 * Enterprise: NEO3DS
 * License:
 *  본 코드의 저작권은 위와 같으며,
 *  상업적인 무단 도용시 법적인 책임을 물을 수 있음을 공지합니다.
 *  
 *  확장 부품: 버저, 블루투스 모듈, 터치 센서
 */

#include <SoftwareSerial.h>

SoftwareSerial bt(A4, A5);

int PIN_BUZZER = 3;
int PIN_LED = 5;
int PIN_HUMIDIFIED = 6;
int PIN_TOUCH_SENSOR = 7;
int PIN_TRIG = 12;
int PIN_ECHO = 13;

boolean isPress = false;
boolean isUp = false;
boolean beforeTouchValue = 0;
boolean canonState = false;
boolean isBluetooth = false;

void turnCtrl(boolean isOn) {
  digitalWrite(PIN_LED, isOn);
  digitalWrite(PIN_HUMIDIFIED, isOn);
}

void setup() {
  bt.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_HUMIDIFIED, OUTPUT);
  pinMode(PIN_TOUCH_SENSOR, INPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  for (int i=0; i < 3; i++) {
    tone(PIN_BUZZER, 262, 200);
    delay(300);
  }
}

void loop() {
  if (bt.available()) {
    isBluetooth = true;
    char cmd = bt.read();
    if (cmd == '1') {
      canonState = true;
      turnCtrl(canonState);
    } else if (cmd == '0') {
      canonState = false;
      turnCtrl(canonState);
    }
  }
  
  int value = digitalRead(PIN_TOUCH_SENSOR);
  if (beforeTouchValue == 0 && value == 1 && isUp == false) {
    beforeTouchValue = 1;
    isPress = true;
    isBluetooth = false;
  } else if (beforeTouchValue == 1 && value == 0 && isPress == true) {
    beforeTouchValue = 0;
    isPress = false;
    isUp = true; 
  }

  if (isUp && isBluetooth == false) {
    isUp = false;
    canonState = !canonState;
    if (canonState) {
      turnCtrl(canonState); // true
    } else {
      turnCtrl(canonState); // false
    }
  }
}
