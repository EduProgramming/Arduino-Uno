int PIN_RED = 9;
int PIN_GREEN = 10;
int PIN_BLUE = 11;

boolean ledState[3] = {false, false, false};

void setup() {
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'a') {
      ledState[0] = !ledState[0];
      digitalWrite(PIN_RED, ledState[0]);
    } else if (cmd == 'b') {
      ledState[1] = !ledState[1];
      digitalWrite(PIN_GREEN, ledState[1]);
    } else if (cmd == 'c') {
      ledState[2] = !ledState[2];
      digitalWrite(PIN_BLUE, ledState[2]);
    }
  }
}
