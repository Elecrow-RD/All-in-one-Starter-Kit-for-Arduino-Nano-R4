#define Relay 4          // Define the relay control pin as digital pin 4

void setup() {
  pinMode(Relay, OUTPUT); // Set the relay pin as an output
}

void loop() {
  digitalWrite(Relay, HIGH); // Turn the relay ON
  delay(3000);               // Keep the relay ON for 3 seconds
  digitalWrite(Relay, LOW);  // Turn the relay OFF
  delay(3000);               // Keep the relay OFF for 3 seconds
}