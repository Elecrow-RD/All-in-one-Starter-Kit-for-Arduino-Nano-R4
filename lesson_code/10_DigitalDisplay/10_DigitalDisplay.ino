#include "HT16K33.h"          // Include the HT16K33 LED display driver library

HT16K33 seg(0x70);            // Create an HT16K33 display object with I2C address 0x70
uint8_t array_test[4] = {1, 2, 3, 4};  // Define a 4-element array to display digits on the 4-digit display

void setup()
{
  Wire.begin();               // Initialize I2C communication
  Wire.setClock(100000);      // Set I2C clock speed to 100 kHz (standard mode)
  seg.begin();                // Initialize the HT16K33 display controller

  seg.displayOn();            // Turn on the LED display
  seg.setBrightness(2);       // Set display brightness (range usually 0–15)
  seg.displayClear();         // Clear all digits on the display
  seg.setBlink(0);            // Disable blinking mode
  seg.display(array_test, 0); // Display the array starting at digit position 0
  delay(1000);                // Wait for 1 second
  seg.display(array_test, 1); // Display the array starting at digit position 1
  delay(1000);                // Wait for 1 second
  seg.display(array_test, 2); // Display the array starting at digit position 2
  delay(1000);                // Wait for 1 second
  seg.display(array_test, 3); // Display the array starting at digit position 3
  delay(1000);                // Wait for 1 second
}

void loop()
{
  // Loop to display decreasing repeating digits on the 4-digit display
  for (int number = 8888; number >= 1111; number = number - 1111) {
    seg.displayInt(number);   // Display the integer value on the 4-digit display
    delay(1000);              // Wait for 1 second before updating the display
  }
}
