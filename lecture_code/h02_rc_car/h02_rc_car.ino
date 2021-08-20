#include <SoftwareSerial.h>
SoftwareSerial BT(A4, A5);

int LEFT_MOTOR_FRONT = 2;
int LEFT_MOTOR_BACK = 4;
int RIGHT_MOTOR_FRONT = 7;
int RIGHT_MOTOR_BACK = 8;
int LEFT_MOTOR_SPEED = 5;
int RIGHT_MOTOR_SPEED = 6;
int ULTRASONIC_TRIG = 12;
int ULTRASONIC_ECHO = 13;

unsigned long currentTime;
char cmd;

/**
 * 모터 제어 함수
 * @params leftValue, rightValue
 * leftValue: 왼쪽 모터의 값
 * rightValue: 오른쪽 모터의 값
 * 
 * 해당 값이 0일때는 정지 신호
 * 1일때는 정회전
 * 2일때는 역회전
 */
void motorCtrl(int leftValue, int rightValue) {
  if (leftValue == 0 && rightValue == 0) { // 모터 정지
    digitalWrite(LEFT_MOTOR_FRONT, LOW);
    digitalWrite(LEFT_MOTOR_BACK, LOW);
    digitalWrite(RIGHT_MOTOR_FRONT, LOW);
    digitalWrite(RIGHT_MOTOR_BACK, LOW);
  } else {
    boolean leftState = leftValue == 1 ? true : false;
    boolean rightState = rightValue == 1 ? true : false;
    digitalWrite(LEFT_MOTOR_FRONT, leftState);
    digitalWrite(LEFT_MOTOR_BACK, !leftState);
    digitalWrite(RIGHT_MOTOR_FRONT, rightState);
    digitalWrite(RIGHT_MOTOR_BACK, !rightState);
  }
}

/**
 * 초음파 센서 거리값 반환 함수
 * @return cm단위로 소수점 가진 거리값 반환
 */
float getDistance() {
  digitalWrite(ULTRASONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG, LOW);
  float duration = pulseIn(ULTRASONIC_ECHO, HIGH);
  return duration / 29 / 2;
}

/**
 * 회피주행
 * @params command
 * command: 블루투스 명령 가져오기
 * 
 * 블루투스 명령이 이전과 다르면 끊고 다른 명령 시행을 위해서.
 * 투석기 앱에 맞추다보니 장전 버튼 이벤트
 * touchDown: 5
 * touchUp: 6
 * 으로 데이터가 와서 6을 강제적 or 처리
 */
void avoidDistance(char command) {
  while (cmd == command || cmd == '6') {
    float distance = getDistance();
    if (distance < 15) {
      currentTime = millis();
      while (millis() - currentTime < 1000 && (cmd == command || cmd == '6')) {
        communicationBluetooth();
      }
      motorCtrl(1, 2);
    } else {
      motorCtrl(1, 1);
    }
    communicationBluetooth();
  }
}

void communicationBluetooth() {
  if (BT.available()) {
    cmd = BT.read();
    if (cmd == '1') { // 앞으로
      motorCtrl(1, 1);
    } else if (cmd == '2') { // 왼쪽으로
      motorCtrl(2, 1);
    } else if (cmd == '3') { // 오른쪽으로
      motorCtrl(1, 2);
    } else if (cmd == '4') { // 뒤로
      motorCtrl(2, 2);
    } else if (cmd == '0') { // 정지
      motorCtrl(0, 0);
    } else if (cmd == '5') { // 자율주행
      avoidDistance(cmd);
    }
  }
}

void setup() {
  BT.begin(9600);
  pinMode(LEFT_MOTOR_FRONT, OUTPUT);
  pinMode(LEFT_MOTOR_BACK, OUTPUT);
  pinMode(RIGHT_MOTOR_FRONT, OUTPUT);
  pinMode(RIGHT_MOTOR_BACK, OUTPUT);
  pinMode(ULTRASONIC_TRIG, OUTPUT);
  pinMode(ULTRASONIC_ECHO, INPUT);
  
  analogWrite(LEFT_MOTOR_SPEED, 255);
  analogWrite(RIGHT_MOTOR_SPEED, 255);
}

void loop() {
  communicationBluetooth();
}
