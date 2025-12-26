#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// ===== LCD parameters =====
#define COLUMNS 16
#define ROWS    2

LiquidCrystal_I2C lcd(
  PCF8574_ADDR_A21_A11_A01,
  4, 5, 6, 16, 11, 12, 13, 14,
  POSITIVE
);
// ===== Pin definitions =====
const int Sound_Pin = A1;
const int RED_LED    = 5;
const int YELLOW_LED = 10;
const int GREEN_LED  = 11;

void setup() {
  // Initialize LED pins as output
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Initialize LCD
  lcd.begin(COLUMNS, ROWS, LCD_5x8DOTS);
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Sound Monitor");
}

void loop() {
  int soundValue = analogRead(Sound_Pin);
  // ===== LCD display =====
  lcd.setCursor(0, 1);
  lcd.print("Value: ");
  lcd.print(soundValue);
  lcd.print("   ");   // Clear remaining characters
  // ===== LED status control =====
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  if (soundValue < 100) {
    digitalWrite(GREEN_LED, HIGH);
  }
  else if (soundValue <= 300) {
    digitalWrite(YELLOW_LED, HIGH);
  }
  else {
    digitalWrite(RED_LED, HIGH);
  }

  delay(200);  // Refresh rate
}
