int btnList[3] = {A1, A2, A3};
int ledList[3] = {9, 10, 11};
int isPress[3] = {false, false, false};
int isLedOn[3] = {false, false, false};
int arraySize = 3;

void setup() {
  for (int btn=0; btn < arraySize; btn++) {
    pinMode(btnList[btn], INPUT);
  }
  for (int led=0; led < arraySize; led++) {
    pinMode(ledList[led], OUTPUT);
  }
}

// Tact Switch
// 안눌려 있을 때: 0
// 눌려있을 때: 1
void loop() {
  int btnValueList[3] = {digitalRead(btnList[0]), digitalRead(btnList[1]), digitalRead(btnList[2])};
  for (int index=0; index < arraySize; index++) {
    if (btnValueList[index] == 1 && isPress[index] == false) {
      isPress[index] = true;
      if (isLedOn[index] == false) {
        isLedOn[index] = true;
        digitalWrite(ledList[index], HIGH);
      } else {
        isLedOn[index] = false;
        digitalWrite(ledList[index], LOW);
      }
    } else if (btnValueList[index] == 0 && isPress[index] == true) {
      isPress[index] = false;
    }
  }
}
