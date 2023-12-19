#include <Servo.h>

// Define PIR sensor pin
int pirPin = 3;

// Create a Servo object
Servo myservo;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Attach servo to pin 9
  myservo.attach(13);

  // Initialize PIR sensor pin as input
  pinMode(pirPin, INPUT);
}

void loop() {
  // Read PIR sensor value
  int pirValue = digitalRead(pirPin);

  if (pirValue == HIGH) {
    // PIR sensor detected motion
    Serial.println("Motion detected!");

    // Move servo to a specific angle (e.g., 90 degrees)
    myservo.write(90);

    // Wait for the servo to reach the desired position
    delay(5000);

    // Return servo to the initial position (e.g., 0 degrees)
    myservo.write(180);
  }

  // Optional delay to avoid rapid detection
  delay(500);
}