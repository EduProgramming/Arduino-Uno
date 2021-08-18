/**
 * 중괄호를 쓰는 경우 -> 영역 표시
 * 1. 함수
 * 2. 반복문
 * 3. 가정문
 * 
 * ... 현재까지의 경우만 기재
 */

int PIN_RED = 9;
int PIN_GREEN = 10;
int PIN_BLUE = 11;

void ledCtrl(int redValue, int greenValue, int blueValue) {
  analogWrite(PIN_RED, redValue);
  analogWrite(PIN_GREEN, greenValue);
  analogWrite(PIN_BLUE, blueValue);
}

void setup() {
}

void loop() {
  ledCtrl(150, 0, 0); // RED 150세기
  delay(1000); // 1초 지연
  ledCtrl(0, 100, 0); // GREEN 100세기
  delay(1000);
  ledCtrl(0, 0, 50); // BLUE 50세기
  delay(1000);
  ledCtrl(100, 100, 0); // RED + GREEN 100세기 = 노랑 (빛의 삼원색)
  delay(1000);
}
