int PIN_LED = 5;
int PIN_HUMIDIFIED = 6;
int PIN_TRIG = 12;
int PIN_ECHO = 13;

boolean state = false;

float getDistance() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  float duration = pulseIn(PIN_ECHO, HIGH);
  return duration / 29 / 2;
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_HUMIDIFIED, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {
  float distance = getDistance();
  if (distance < 20) {
    state = true;
  } else {
    state = false;
  }
  digitalWrite(PIN_LED, state);
  digitalWrite(PIN_HUMIDIFIED, state); 
}
