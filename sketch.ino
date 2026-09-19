// ENGR 4399 ST - Simulation Assignment 2
// ESP32 Joystick-Controlled Servo
// Student: Jacob kebbel

const int SW_PIN = 18;       // Joystick push button
const int SERVO_PIN = 19;    // Servo signal
const int X_PIN = 34;        // Joystick X-axis
const int Y_PIN = 35;        // Joystick Y-axis

void setup() {
  Serial.begin(115200);

  pinMode(SW_PIN, INPUT_PULLUP);
  pinMode(SERVO_PIN, OUTPUT);

  Serial.println("ESP32 Joystick Servo Controller");
}

// Send one control pulse to servo
void moveServo(int angle) {
  // Convert 0-180 degrees to servo pulse width
  int pulseWidth = map(angle, 0, 180, 500, 2400);

  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(pulseWidth);

  digitalWrite(SERVO_PIN, LOW);
  delayMicroseconds(20000 - pulseWidth);
}

void loop() {
  // Read joystick
  int xValue = analogRead(X_PIN);
  int yValue = analogRead(Y_PIN);

  // Read joystick button
  int switchState = digitalRead(SW_PIN);

  // Convert joystick X-axis to 0-180 degrees
  int servoAngle = map(xValue, 0, 4095, 0, 180);
  servoAngle = constrain(servoAngle, 0, 180);

  // Button centers the servo
  if (switchState == LOW) {
    servoAngle = 90;
  }

  // Move servo
  moveServo(servoAngle);

  // Serial Monitor output
  Serial.print("X: ");
  Serial.print(xValue);

  Serial.print(" | Y: ");
  Serial.print(yValue);

  Serial.print(" | SW: ");
  Serial.print(switchState);

  Serial.print(" | Servo Angle: ");
  Serial.print(servoAngle);

  Serial.println(" degrees");
}
