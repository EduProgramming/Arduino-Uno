int led = 11;
int allTime = 1000;
int onTime = 0;
int sw = 1;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delayMicroseconds(onTime);
  digitalWrite(led, LOW);
  delayMicroseconds(allTime - onTime);
  onTime += sw;
  
  if (onTime >= allTime) {
    sw = -1 * abs(sw);
  } else if (onTime <= 0) {
    sw = abs(sw);
  }

  if (allTime - onTime < 0) {
    onTime = allTime;
  } else if (onTime < 0) {
    onTime = 0;
  }

}
