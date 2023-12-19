#include <SoftwareSerial.h>
SoftwareSerial BTserial(0, 1); // RX | TX

void setup() {
  Serial.begin(9600);  // Initialize serial communication
   BTserial.begin(9600);
}

void loop() {
  static int index = 0;  // Index for storing characters in the array

  if (BTserial.available() > 0) {
    // Read the incoming data and print it to the Serial monitor
    char receivedChar = BTserial.read();
    Serial.print(receivedChar);

        // Store the received character in the array
    msg[index] = receivedChar;
    index++;

    // Check if the message is complete or buffer is full
    if (receivedChar == '\n' || index == bufferSize - 1) {
      // Null-terminate the char array to treat it as a string
      msg[index] = '\0';

      // Process the received message
      processMessage(msg);

      // Reset the index for the next message
      index = 0;
    }
  }
}
