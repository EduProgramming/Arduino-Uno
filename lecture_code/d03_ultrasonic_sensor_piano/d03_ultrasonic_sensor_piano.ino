int PIN_BUZZER = 3;
int PIN_RED_LED = 9;
int PIN_GREEN_LED = 10;
int PIN_BLUE_LED = 11;
int PIN_TRIG = 12;
int PIN_ECHO = 13;

int notes[8] = {262, 294, 330, 349, 392, 440, 494, 523};
boolean ledList[8][3] = {
  {true, false, false}, {false, true, false}, {false, false, true}, {true, true, false}, {true, false, true},
  {false, true, true}, {true, true, true}, {true, false, false}
};

int playTime = 300;
int pauseTime = 500;

void ledCtrl(boolean redState, boolean greenState, boolean blueState) {
  digitalWrite(PIN_RED_LED, redState);
  digitalWrite(PIN_GREEN_LED, greenState);
  digitalWrite(PIN_BLUE_LED, blueState);
}

int getDistance() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  float duration = pulseIn(PIN_ECHO, HIGH);
  return duration / 29.0 / 2;
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_RED_LED, OUTPUT);
  pinMode(PIN_GREEN_LED, OUTPUT);
  pinMode(PIN_BLUE_LED, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {
  int distance = getDistance();
  int index = distance / 7;
  if (index < 8) {
    ledCtrl(ledList[index][0], ledList[index][1], ledList[index][2]);
    tone(PIN_BUZZER, notes[index], playTime);
    delay(pauseTime);
  } else {
    ledCtrl(false, false, false);
  }
}
