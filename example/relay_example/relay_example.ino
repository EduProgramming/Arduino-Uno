const int PIN_RELAY = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_RELAY, OUTPUT);
  digitalWrite(PIN_RELAY, HIGH);
  delay(3000);
  digitalWrite(PIN_RELAY, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
