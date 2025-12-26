#include <Wire.h>                 // Include I2C communication library
#include <LiquidCrystal_I2C.h>    // Include I2C LCD control library

#define COLUMNS 16                // Number of LCD columns (16x2 LCD)
#define ROWS    2                 // Number of LCD rows

// Create an LCD object using PCF8574 I2C address and pin mapping
LiquidCrystal_I2C lcd(
  PCF8574_ADDR_A21_A11_A01,        // I2C address of PCF8574 (based on A2/A1/A0 wiring)
  4, 5, 6, 16, 11, 12, 13, 14,     // PCF8574 pin mapping to LCD pins (RS, RW, EN, BL, D4-D7)
  POSITIVE                        // Backlight polarity: POSITIVE means HIGH turns backlight on
);

void setup()
{
  // Initialize the LCD with specified columns, rows, and character size
  lcd.begin(COLUMNS, ROWS, LCD_5x8DOTS);  
  lcd.clear();                    // Clear LCD display
  lcd.backlight();                // Turn on LCD backlight
  lcd.setCursor(0, 0);            // Set cursor to column 0, row 0 (first row)
  lcd.print(F("Hello world"));    // Print text stored in flash memory
}

void loop()
{
  // Scroll the display to the right for a fixed number of steps
  for(int i = 0; i <= 4; i++){
    lcd.scrollDisplayRight();     // Scroll entire display one position to the right
    delay(300);                  // Delay to control scrolling speed
  }
  // Scroll the display to the left for a fixed number of steps
  for(int i = 0; i <= 4; i++){
    lcd.scrollDisplayLeft();      // Scroll entire display one position to the left
    delay(300);                  // Delay to control scrolling speed
  }
}
