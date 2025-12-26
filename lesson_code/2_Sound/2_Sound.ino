const int Sound_Pin = A1;     // Pin for sound sensor
const int LED_Pin = 5;        // Pin for LED

void setup() {
  Serial.begin(115200);       // Initialize serial communication
  pinMode(LED_Pin, OUTPUT);   // Set LED pin as output
}

void loop() {
  int val = analogRead(Sound_Pin);  // Read sound sensor value (0~1023)
  Serial.println(val);              // Print value to serial monitor

  // Check if the value exceeds the sound threshold
  if (val > 500) {
    digitalWrite(LED_Pin, HIGH);    // Turn on LED
    delay(3000);                    // Keep LED on for 3 seconds
    digitalWrite(LED_Pin, LOW);     // Turn off LED
  }

  delay(100);                       // Sampling delay
}