/**
 * #include를 통해서 라이브러리를 포함할 수 있습니다.
 * 포함하게 되면 해당 라이브러리를 사용할 수 있습니다.
 * 
 * h는 헤더파일 입니다.
 * 예를 들어서, 헤더파일이란 음식점의 메뉴판이라고 보시면 됩니다.
 * 헤더 파일에 내가 만든 함수들을 정리해 놓고 관리와 사용이 쉽기 때문입니다.
 */

#include <Servo.h>

#define PIN_SERVO       9

Servo servo;

void setup() {
  servo.attach(PIN_SERVO);
  servo.write(0);
  delay(500);
  servo.write(180);
}

void loop() {
}
