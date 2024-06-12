#include <Arduino.h>
#include <ESP32Servo.h>


int minUs = 500; // 500us
int maxUs = 2400; // 2400us
int servoFrequency = 50; // 50Hz
int servoPin = 25;//25; // GPIO 25
Servo servo1;

void setup() {
  // put your setup code here, to run once:
  // シリアル通信を9600bpsで開始
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  // pinMode(25, OUTPUT);
  servo1.setPeriodHertz(servoFrequency); // Standard 50hz servo
  servo1.attach(servoPin, minUs, maxUs);
  servo1.write(180);


}
int deg = 180;
void loop() {
  // シリアルで入力した値を読み取り、その値を出力する
  deg = Serial.parseInt();
  if (deg != 0) {
    servo1.write(deg);
    Serial.printf("deg:%d\n",deg);
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}