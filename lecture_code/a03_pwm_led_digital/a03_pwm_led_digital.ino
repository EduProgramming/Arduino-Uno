int led = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  delayMicroseconds(10);
  digitalWrite(led, LOW);
  delayMicroseconds(990);
}
