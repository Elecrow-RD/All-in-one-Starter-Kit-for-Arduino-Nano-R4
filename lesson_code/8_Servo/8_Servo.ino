#include <Servo.h>            // Include the Servo library to control servo motors
 
Servo myservo;                // Create a Servo object to control a servo motor
int pos = 0;                  // Variable to store the current servo position (angle)
 
void setup() {
// Attach the servo to digital pin 9
// Set minimum pulse width to 600 µs 
// Set maximum pulse width to 2600 µs
  myservo.attach(9, 600, 2600); 

}
 
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { 
     // Increase servo angle from 0 to 180 degrees
    myservo.write(pos);        // Set the servo to the current angle
    delay(15);                 // Wait 15 ms for the servo to reach the position
  }

  for (pos = 180; pos >= 0; pos -= 1) { 
    // Decrease servo angle from 180 back to 0 degrees
    myservo.write(pos);        // Set the servo to the current angle
    delay(15);                 // Wait 15 ms for the servo to reach the position
  }
}
