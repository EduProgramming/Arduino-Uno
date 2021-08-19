/**
 * 서보 모터를 이용한 복불복 게임 만들기
 */

#include <Servo.h>

Servo servo;
int PIN_SERVO = 9;

void setup() {
  servo.attach(PIN_SERVO);
  randomSeed(analogRead(A0)); // 랜덤시드는 랜덤값을 섞어주는 역할을 합니다.
  // 랜덤시드가 없다면 랜덤으로 오는 값이 실행할때 늘 똑같습니다.
  // analogRead(A0)을 통해서 0~1023의 값을 가져올때 아무것도 꽂혀있지 않으면
  // 값이 랜덤으로 바뀔 것이기 때문에 해당 부분을 사용합니다.
  // 반대로 말하면, 다른 센서가 꽂혀있어서 값이 일정하면 랜덤시드의 효과가 없습니다.
}

void loop() {
  // 시작점을 알려주기 위해서는 tone을 이용하거나
  // 다른 센서를 이용해서 알려준 후에 사용하면 됩니다. (해당 부분 생략)
  int value = random(2); // 0~1의 값에서 랜덤 -> 해당값을 3으로 하면 0~2의 값에서 랜덤
  if (value == 0) {
    servo.write(30);
    delay(500);
  } else {
    servo.write(150);
    delay(500);
  }
}
