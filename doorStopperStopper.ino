#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define servo 0
#define SERVOMIN 150
#define SERVOMAX 1200
#define soundMic 3

void setup() {
  pinMode(soundMic, INPUT);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);
}

void loop() {
  if (digitalRead(soundMic)) {
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
      pwm.writeMicroseconds(servo, 1000);
    }
    pwm.writeMicroseconds(servo, 0);
    delay(1000);
    for (uint16_t pulselen = SERVOMAX * 1.2; pulselen > SERVOMIN; pulselen--) {
      pwm.writeMicroseconds(servo, 1000);
    }
    pwm.writeMicroseconds(servo, 0);
    delay(2000);
  }
}
