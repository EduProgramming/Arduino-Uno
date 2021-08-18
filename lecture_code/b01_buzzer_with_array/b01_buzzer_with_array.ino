/**
 * tone함수
 * : tone(핀번호, 주파수, 소리시간);
 * 
 * sizeof 사용시 주의사항
 * sizeof는 해당 배열의 byte길이로 나타내기에
 * 원하는 길이를 나타내기 위해서는 해당 인덱스의 값을 하나 가지고 와서 나눠주면 됨.
 */

int PIN_BUZZER = 3;
int notes[8] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  for (int index=0; index < sizeof(notes)/sizeof(notes[0]); index++) {
    tone(PIN_BUZZER, notes[index], 300);
    delay(500);
  }
}

void loop() {

}
