int triggerPin = 6;
int echoPin = 7;

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

void setup() {
  Serial.begin(115200);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  measureDistanceCm();
}
