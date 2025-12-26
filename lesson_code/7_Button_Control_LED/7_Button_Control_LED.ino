// Combine with LED lights to do button lighting experiment
// Define LED pins
#define LED_RED 5
#define LED_YELLOW 10
#define LED_GREEN 11

// Define button analog input pin
#define Button_Pin A3

void setup() {
  // Initialize LED pins as output
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(Button_Pin, INPUT);

  // Initialize serial communication
  Serial.begin(115200);
}

void loop() {
  // Read analog value
  int val = analogRead(Button_Pin);
  Serial.print("Button Value: ");
  Serial.println(val);

  // Check the analog value range and light up the corresponding LED
  if (val >= 500 && val <= 520) {
    digitalWrite(LED_RED, HIGH);
  } 
  else if (val >= 680 && val <= 690) {
    digitalWrite(LED_YELLOW, HIGH);
  } 
  else if (val >= 845 && val <= 860) {
    digitalWrite(LED_GREEN, HIGH);
  }
  else{
  // Turn off all LEDs by default
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
  }

  delay(100); // Read every 100ms
}