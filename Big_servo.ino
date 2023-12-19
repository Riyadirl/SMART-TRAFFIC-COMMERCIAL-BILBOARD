#include <Servo.h>

Servo myServo; // Create a servo object

int pirPin = 3;

// Create a Servo object
Servo Myservo;

void setup() {
  myServo.attach(13); // Attach the servo to pin 9
  

  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read
    char command = Serial.read(); // Read the incoming command

    // Perform actions based on the received command
    if (command == '1') {
      moveServo(0); // Move the servo to direction 1
    } else if (command == '2') {
      moveServo(90); // Move the servo to direction 2
    } else if (command == '3') {
      moveServo(180); // Move the servo to direction 3
    } else if (command == '4') {
      moveServo(270); // Move the servo to direction 4
    }
  }
}

void moveServo(int angle) {
  myServo.write(angle); // Move the servo to the specified angle
  delay(500); // Wait for the servo to reach the position
}
