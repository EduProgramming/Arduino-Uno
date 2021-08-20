#define PIN_LED_FIRST       9
#define PIN_LED_SECOND     10

#include <Ticker.h>

void blinkOne();
void blinkTwo();

Ticker timer500ms(blinkOne, 500);
Ticker timer1000ms(blinkTwo, 1000);

void blinkOne() {
  digitalWrite(PIN_LED_FIRST, !digitalRead(PIN_LED_FIRST));
}

void blinkTwo() {
  digitalWrite(PIN_LED_SECOND, !digitalRead(PIN_LED_SECOND));
}

void setup() {
  pinMode(PIN_LED_FIRST, OUTPUT);
  pinMode(PIN_LED_SECOND, OUTPUT);
  
  timer500ms.start();
  timer1000ms.start();
}

void loop() {
  timer500ms.update();
  timer1000ms.update();
}
