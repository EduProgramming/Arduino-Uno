class ledFlasher {
  int ledPin;
  long ledOnTime;
  long ledOffTime;
  boolean state;
  unsigned long previousTime;

  public:
    ledFlasher(int pin, long onTime, long offTime) {
      ledPin = pin;
      ledOnTime = onTime;
      ledOffTime = offTime;
      
      pinMode(ledPin, OUTPUT);

      state = false;
      previousTime = 0;
    }

  void update() {
    unsigned long currentTime = millis();
    if (state == false && currentTime - previousTime >= ledOnTime) {
      state = true;
      previousTime = currentTime;
      digitalWrite(ledPin, state);
    } else if (state && currentTime - previousTime >= ledOffTime) {
      state= false;
      previousTime = currentTime;
      digitalWrite(ledPin, state);
    }
  }
};

class BuzzerFlasher {
  int buzzerPin;
  int buzzerNote;
  long buzzerSoundTime;
  long buzzerDelayTime;
  boolean state;
  unsigned long previousTime;

  public:
    BuzzerFlasher(int pin, int note, long soundTime, long delayTime) {
      buzzerPin = pin;
      buzzerNote = note;
      buzzerSoundTime = soundTime;
      buzzerDelayTime = delayTime;

      pinMode(buzzerPin, OUTPUT);

      state = false;
      previousTime = 0;
    }

  void sound() {
    unsigned long currentTime = millis();
    if ((state == false) && ((currentTime - previousTime) <= (buzzerSoundTime + buzzerDelayTime))) {
      state = true;
      tone(buzzerPin, buzzerNote, buzzerSoundTime);
    } else if (state == true && currentTime - previousTime > (buzzerSoundTime + buzzerDelayTime)) {
      state = false;
      previousTime = millis();
    }
  }
  
};

int PIN_BUZ = 3;
int PIN_LED = 11;

ledFlasher ledFlasher(PIN_LED, 600, 400);
BuzzerFlasher buzzerFlasher(PIN_BUZ, 912, 100, 150);

void setup() {
  
}

void loop() {
  ledFlasher.update();
}
