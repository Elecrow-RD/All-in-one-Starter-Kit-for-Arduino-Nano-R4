int triggerPin = 6;
int echoPin = 7;
#define BUZ 3        // Buzzer pin
#define LED_RED 5    // Red LED pin

// Custom function: measure ultrasonic distance (in centimeters)
float measureDistanceCm() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;
  Serial.print((int)distance);
  Serial.println("\t cm");
  delay(100); // Small delay
  return distance;
}

// Function: Blink LED + buzzer sound
void flashLedBuzzer(int interval) {
  digitalWrite(LED_RED, HIGH);
  tone(BUZ, 1000);       // High-frequency buzzer sound
  delay(interval);        // Parameter controls blinking interval
  digitalWrite(LED_RED, LOW);
  noTone(BUZ);
  delay(interval);
}

void setup() {
  Serial.begin(115200);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(BUZ, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}

void loop() {
  float distance = measureDistanceCm();
  if (distance >= 0 && distance <= 10) {
    // 0-10 cm: buzzer beeps rapidly, LED blinks fast
    flashLedBuzzer(50);   // 50ms interval, rapid
  }
  else if (distance >= 11 && distance <= 20) {
    // 11-20 cm: buzzer beeps slowly, LED blinks slowly
    flashLedBuzzer(150);  // 150ms interval, slow
  }
  else {
    // More than 20 cm: buzzer off, LED off
    digitalWrite(LED_RED, LOW);
    noTone(BUZ);
  }
  delay(200);  // Small delay after each measurement
}
