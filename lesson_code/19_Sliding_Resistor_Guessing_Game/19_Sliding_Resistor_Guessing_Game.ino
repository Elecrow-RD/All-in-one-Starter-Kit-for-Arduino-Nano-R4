#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/* ========== LCD Parameters ========== */
#define COLUMNS 16   // Number of LCD columns
#define ROWS    2    // Number of LCD rows

LiquidCrystal_I2C lcd(
  PCF8574_ADDR_A21_A11_A01,  // I2C address of PCF8574
  4, 5, 6, 16,              // RS, RW, EN, Backlight
  11, 12, 13, 14,           // D4, D5, D6, D7
  POSITIVE                  // Backlight polarity
);

/* ========== Hardware Pins ========== */
#define POT_PIN A0

#define LED_RED     5
#define LED_GREEN   11

/* ========== Game Variables ========== */
int targetValue = 0;
int currentValue = 0;
int diffValue = 0;
int score = 0;

/* ========== Setup ========== */
void setup()
{
  Serial.begin(115200);

  lcd.begin(COLUMNS, ROWS, LCD_5x8DOTS);
  lcd.clear();
  lcd.backlight();

  randomSeed(analogRead(A1));

  // LED initialization
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Pot Guess Game");
  lcd.setCursor(0, 1);
  lcd.print("Get Ready...");
  delay(1500);
  lcd.clear();
}

/* ========== Loop ========== */
void loop()
{
  // Turn off LEDs at the start of each round
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);

  /* ===== Generate target value ===== */
  targetValue = random(0, 1024);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Target:");
  lcd.print(targetValue);

  lcd.setCursor(0, 1);
  lcd.print("Adjust in 3s");

  delay(3000);

  /* ===== Read potentiometer value ===== */
  currentValue = analogRead(POT_PIN);
  diffValue = abs(currentValue - targetValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Now:");
  lcd.print(currentValue);

  lcd.setCursor(0, 1);
  lcd.print("Diff:");
  lcd.print(diffValue);

  /* ===== Success / Failure ===== */
  if (diffValue <= 10) {
    score++;
    digitalWrite(LED_GREEN, HIGH);   // Success → turn on green LED
    lcd.setCursor(12, 1);
    lcd.print("OK");
  } else {
    digitalWrite(LED_RED, HIGH);     // Failure → turn on red LED
    lcd.setCursor(12, 1);
    lcd.print("NO");
  }

  delay(2000);

  /* ===== Display score ===== */
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Score:");
  lcd.print(score);
  lcd.setCursor(0, 1);
  lcd.print("Next round");

  delay(1500);
}
