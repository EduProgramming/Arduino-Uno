int led = 10;

/**
 * [반복문] for문
 * for (초기값, 조건식, 증감식) {
 *   수행문장
 * }
 */

void setup() {
  for (int power=0; power < 256; power++) {
    analogWrite(led, power);
    delay(20);
  }
}

void loop() {
}
