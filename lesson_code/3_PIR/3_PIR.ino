#define PIR     A2      // PIR sensor
#define SOUND   A1      // Sound sensor
#define LED_PIN 5       // LED pin

void setup() {
  pinMode(PIR, INPUT);
  pinMode(SOUND, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Read PIR state
  int PIRState = digitalRead(PIR);

  // Read sound sensor value
  int soundValue = analogRead(SOUND);

// LED logic: if PIR detected OR sound > 500, LED on for 3 seconds; otherwise off
if (PIRState == HIGH || soundValue > 500) {
    digitalWrite(LED_PIN, HIGH);   // Turn on LED
    delay(3000);                   // Keep LED on for 3 seconds
    digitalWrite(LED_PIN, LOW);    // Turn off LED
} else {
    digitalWrite(LED_PIN, LOW);    // No trigger: LED off
}

  delay(100);  // Slight delay to reduce serial spam
}