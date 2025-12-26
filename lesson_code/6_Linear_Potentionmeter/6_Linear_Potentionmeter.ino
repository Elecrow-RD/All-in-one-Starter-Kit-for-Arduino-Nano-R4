// Define the red LED pin
#define LED_RED 5

// Define the linear potentiometer pin
const int LinearPotentiometer_Pin = A0;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize the LED pin as output
  pinMode(LED_RED, OUTPUT);
}

void loop() {
  // Read the analog value from the linear potentiometer
  int val = analogRead(LinearPotentiometer_Pin);

  // Map the range 0~1023 to 0~255
  int pwmValue = (int)(val / 1023.0 * 255);

  // Use PWM to control LED brightness
  analogWrite(LED_RED, pwmValue);

  // Output analog value and PWM value via serial for debugging
  Serial.print("Analog Value: ");
  Serial.print(val);
  Serial.print("  -> PWM Value: ");
  Serial.println(pwmValue);

  delay(100); // Read once every 100 ms
}
