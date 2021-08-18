int led = 10;
int power = 0;
int sw = 1;

/**
 * [가정문] if문
 * if (조건식A) {
 *   // 수행문장A
 * } else if (조건식B) {
 *   // 수행문장B
 * } else if (조건식C) {
 *   // 수행문장C
 * } else {
 *   // 수행문장D
 * }
 */

void setup() {
}

void loop() {
  analogWrite(led, power);
  delay(20);
  power += sw;

  if (power == 255) sw = -1;
  else if (power == 0) sw = 1;
}
