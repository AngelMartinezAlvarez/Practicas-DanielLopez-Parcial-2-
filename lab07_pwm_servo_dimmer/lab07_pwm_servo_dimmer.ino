#include <Servo.h>

const int PIN_LED = 9;
const int PIN_SERVO = 10;
const int PIN_POT = A0;

Servo miServo;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  miServo.attach(PIN_SERVO);
}

void loop() {
  int lectura = analogRead(PIN_POT);  // 0 - 1023

  int brillo = map(lectura, 0, 1023, 0, 255);
  int grados = map(lectura, 0, 1023, 0, 180);

  analogWrite(PIN_LED, brillo);
  miServo.write(grados);

  Serial.print("ADC: ");
  Serial.print(lectura);
  Serial.print(" | LED: ");
  Serial.print(brillo);
  Serial.print(" | Servo: ");
  Serial.println(grados);

  delay(100);
}
