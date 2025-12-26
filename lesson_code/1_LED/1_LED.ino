// Blink the red, yellow, and green LEDs

#define LED_RED 5       // Define the red LED pin as digital pin 5
#define LED_YELLOW 10   // Define the yellow LED pin as digital pin 10
#define LED_GREEN 11    // Define the green LED pin as digital pin 11

int interval = 1000;   // Set the blinking interval to 1000 milliseconds (1 second)

void setup() {
  pinMode(LED_RED, OUTPUT);     // Set the red LED pin as an output
  pinMode(LED_YELLOW, OUTPUT);  // Set the yellow LED pin as an output
  pinMode(LED_GREEN, OUTPUT);   // Set the green LED pin as an output
}

void loop() {
  digitalWrite(LED_RED, HIGH);     // Turn on the red LED
  digitalWrite(LED_YELLOW, HIGH);  // Turn on the yellow LED
  digitalWrite(LED_GREEN, HIGH);   // Turn on the green LED
  delay(interval);                  // Wait for the defined interval (1 second)
  
  digitalWrite(LED_RED, LOW);      // Turn off the red LED
  digitalWrite(LED_YELLOW, LOW);   // Turn off the yellow LED
  digitalWrite(LED_GREEN, LOW);    // Turn off the green LED
  delay(interval);                 // Wait for the defined interval (1 second)
}
