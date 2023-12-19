Mahbub Hasaan Riyad
#include <Servo.h>

Servo myServo; // Create a servo object

// Define PIR sensor pin
int pirPin = 3;
// int pirPin = 2;
const int buzzerPin = 8; // Replace with the actual pin your buzzer is connected to

// Create a Servo object
Servo myservo;
Servo myservo2;

void setup() {
  myServo.attach(12); // Attach the servo to pin 12
  Serial.begin(9600); // Initialize serial communication
  myservo.attach(13); // Attach servo to pin 13
  myservo2.attach(11);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  static char command;
  if (Serial.available() > 0) { // Check if data is available to read
     command = Serial.read(); // Read the incoming command

    // Perform actions based on the received command
    if (command == '1') {
      moveServoWithMotionDetection(0);
    } else if (command == '2') {
      moveServoWithMotionDetection(90);
    } else if (command == '3') {
      moveServoWithMotionDetection(180);
    } else if (command == '4') {
      alarmSound(500);

      myservo.write(90);
      myservo2.write(90);
          // Wait for the servo to reach the desired position
    delay(5000);


    // Return servo to the initial position (e.g., 180 degrees)
    myservo.write(180);
    myservo2.write(180);
      
  }
    }
  
   if(myServo.read()==90){
    pinMode(3, INPUT); // Initialize PIR sensor pin as input
    checkMotion(3); // Check for motion using the PIR sensor
}

   if(myServo.read()==0 || myServo.read()==90){
    pinMode(4, INPUT); // Initialize PIR sensor pin as input
    checkMotion2(4); // Check for motion using the PIR sensor
}
}

void moveServoWithMotionDetection(int angle) {
  moveServo(angle); // Move the servo to the specified angle
  delay(500);
}

void moveServo(int angle) {
  myServo.write(angle); // Move the servo to the specified angle
  delay(500); // Wait for the servo to reach the position
}

void checkMotion(int x) {
  // Read PIR sensor value
  int pirValue = digitalRead(x);
  myservo.write(180);

  if (pirValue == HIGH) {
    // PIR sensor detected motion
    Serial.println("Motion detected!");
    delay(10000);

  int step = (180 < 90) ? 1 : -1; // Determine the direction of movement

  for (int angle = 180; angle != 90; angle += step) {
    myservo.write(angle); // Move the servo to the specified angle
    delay(10); // Adjust the delay as needed for your desired speed
  }

    // Wait for the servo to reach the desired position
    delay(5000);

    // Return servo to the initial position (e.g., 180 degrees)
    myservo.write(180);
  }

  // Optional delay to avoid rapid detection
  delay(500);
}

void checkMotion2(int x) {
  // Read PIR sensor value
  int pirValue = digitalRead(x);
  myservo2.write(180);

  if (pirValue == HIGH) {
    // PIR sensor detected motion
    Serial.println("Motion detected!");
    delay(10000);

  int step = (180 < 90) ? 1 : -1; // Determine the direction of movement

  for (int angle = 180; angle != 90; angle += step) {
    myservo2.write(angle); // Move the servo to the specified angle
    delay(10); // Adjust the delay as needed for your desired speed
  }

    // Wait for the servo to reach the desired position
    delay(5000);

    // Return servo to the initial position (e.g., 180 degrees)
    myservo2.write(180);
  }

  // Optional delay to avoid rapid detection
  delay(500);
}
void alarmSound(int duration) {
  // Play the alarm sound on the buzzer
  tone(buzzerPin,450); // Adjust the frequency as needed
  delay(duration);      // Wait for the specified duration
  noTone(buzzerPin);    // Turn off the buzzer
  delay(duration);

    // Play the alarm sound on the buzzer
  tone(buzzerPin, 450); // Adjust the frequency as needed
  delay(duration);      // Wait for the specified duration
  noTone(buzzerPin);    // Turn off the buzzer
  delay(duration);

    // Play the alarm sound on the buzzer
  tone(buzzerPin, 450); // Adjust the frequency as needed
  delay(duration);      // Wait for the specified duration
  noTone(buzzerPin);    // Turn off the buzzer
  delay(duration);

    // Play the alarm sound on the buzzer
  tone(buzzerPin, 450); // Adjust the frequency as needed
  delay(duration);      // Wait for the specified duration
  noTone(buzzerPin);    // Turn off the buzzer
  delay(duration);
}