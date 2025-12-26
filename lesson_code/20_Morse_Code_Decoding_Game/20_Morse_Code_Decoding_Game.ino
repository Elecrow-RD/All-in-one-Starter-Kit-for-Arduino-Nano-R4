#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
  =================== Hardware Definitions ===================
*/

// LED pin definitions
#define LED_RED     5
#define LED_YELLOW  10
#define LED_GREEN   11

// All three buttons share one analog input pin
#define BUTTON_ANALOG A3

/*
  =================== LCD Parameters ===================
*/
#define COLUMNS 16   // Number of LCD columns
#define ROWS    2    // Number of LCD rows

// Create an LCD object using PCF8574 I2C expander
LiquidCrystal_I2C lcd(
  PCF8574_ADDR_A21_A11_A01,  // I2C address of PCF8574
  4, 5, 6, 16,              // RS, RW, EN, Backlight
  11, 12, 13, 14,           // D4, D5, D6, D7
  POSITIVE                  // Backlight polarity
);

/*
  =================== Morse Code Table ===================
  Index corresponds to letters A–Z
*/
const char* morseCodes[] = {
  ".-",    // A
  "-...",  // B
  "-.-.",  // C
  "-..",   // D
  ".",     // E
  "..-.",  // F
  "--.",   // G
  "....",  // H
  "..",    // I
  ".---",  // J
  "-.-",   // K
  ".-..",  // L
  "--",    // M
  "-.",    // N
  "---",   // O
  ".--.",  // P
  "--.-",  // Q
  ".-.",   // R
  "...",   // S
  "-",     // T
  "..-",   // U
  "...-",  // V
  ".--",   // W
  "-..-",  // X
  "-.--",  // Y
  "--.."   // Z
};

// Corresponding alphabet characters
const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*
  =================== Timing & Threshold Parameters ===================
*/
const int SHORT_PRESS_THRESHOLD = 500;     // Short press < 500ms → dot
const int CHAR_INTERVAL = 1500;            // Idle time to auto-decode a character
const int CLEAR_SCREEN_THRESHOLD = 1000;   // Long press > 1s → clear screen
const int BLINK_INTERVAL = 200;             // LED blink interval (ms)

/*
  =================== Analog Button Ranges ===================
  (Must match your resistor ladder hardware)
*/
const int MORSE_BTN_RANGE[2]  = {500, 520};  // Morse input button
const int SPACE_BTN_RANGE[2]  = {680, 690};  // Space button
const int DELETE_BTN_RANGE[2] = {845, 860};  // Delete / clear button

/*
  =================== Global Variables ===================
*/
String currentMorse = "";   // Current Morse sequence being entered
String displayText  = "";   // Full text displayed on LCD (history preserved)

unsigned long buttonPressTime = 0;         // Timestamp when a button is pressed
unsigned long lastButtonReleaseTime = 0;  // Timestamp of last button release

bool morseBtnPressed  = false;   // Morse button state
bool spaceBtnPressed  = false;   // Space button state
bool deleteBtnPressed = false;   // Delete button state

/*
  =================== Function Declarations ===================
*/
char decodeMorse(String morse);
void resetMorseInput();
void updateLCDDisplay();
void blinkRedLED(int times);

/*
  =================== Setup Function ===================
*/
void setup() {
  Serial.begin(115200);   // Initialize serial communication for debugging

  // Initialize LED pins
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  // Initialize LCD
  lcd.begin(COLUMNS, ROWS, LCD_5x8DOTS);
  lcd.clear();
  lcd.backlight();

  // Startup message
  lcd.setCursor(0, 0);
  lcd.print(F("Morse Decoder"));
  lcd.setCursor(0, 1);
  lcd.print(F("Ready"));

  delay(1500);
  lcd.clear();
}

/*
  =================== Main Loop ===================
*/
void loop() {
  // Read the shared analog button value
  int val = analogRead(BUTTON_ANALOG);

  // Handle each button based on analog value
  handleMorseButton(val);
  handleSpaceButton(val);
  handleDeleteButton(val);

  delay(10);  // Simple debounce delay
}

/*
  =================== Morse Input Button ===================
  Short press → dot
  Long press  → dash
*/
void handleMorseButton(int val) {
  bool active = (val >= MORSE_BTN_RANGE[0] && val <= MORSE_BTN_RANGE[1]);

  // Button pressed
  if (active && !morseBtnPressed) {
    morseBtnPressed = true;
    buttonPressTime = millis();
    digitalWrite(LED_YELLOW, HIGH);  // Yellow LED indicates button hold
  }
  // Button released
  else if (!active && morseBtnPressed) {
    morseBtnPressed = false;
    digitalWrite(LED_YELLOW, LOW);

    unsigned long duration = millis() - buttonPressTime;
    lastButtonReleaseTime = millis();

    // Determine dot or dash
    if (duration < SHORT_PRESS_THRESHOLD) {
      currentMorse += ".";
      digitalWrite(LED_GREEN, HIGH);
    } else {
      currentMorse += "-";
      digitalWrite(LED_RED, HIGH);
    }

    delay(100);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, LOW);
  }

  // Auto-decode if idle timeout reached
  if (!active && currentMorse.length() > 0) {
    if (millis() - lastButtonReleaseTime > CHAR_INTERVAL) {
      char c = decodeMorse(currentMorse);
      displayText += c;
      updateLCDDisplay();
      resetMorseInput();
    }
  }
}

/*
  =================== Space Button ===================
  Adds a space character
*/
void handleSpaceButton(int val) {
  bool active = (val >= SPACE_BTN_RANGE[0] && val <= SPACE_BTN_RANGE[1]);

  if (active && !spaceBtnPressed) {
    spaceBtnPressed = true;
    digitalWrite(LED_GREEN, HIGH);  // Green LED indicates space key
  }
  else if (!active && spaceBtnPressed) {
    spaceBtnPressed = false;
    digitalWrite(LED_GREEN, LOW);

    displayText += " ";
    updateLCDDisplay();
    delay(100);
  }
}

/*
  =================== Delete Button ===================
  Short press → delete last character
  Long press  → clear screen
*/
void handleDeleteButton(int val) {
  bool active = (val >= DELETE_BTN_RANGE[0] && val <= DELETE_BTN_RANGE[1]);

  if (active && !deleteBtnPressed) {
    deleteBtnPressed = true;
    buttonPressTime = millis();
    digitalWrite(LED_RED, HIGH);
  }
  else if (deleteBtnPressed) {
    unsigned long pressTime = millis() - buttonPressTime;

    // Long press: clear entire display
    if (pressTime >= CLEAR_SCREEN_THRESHOLD) {
      displayText = "";
      lcd.clear();
      blinkRedLED(3);
      deleteBtnPressed = false;
      digitalWrite(LED_RED, LOW);
    }
    // Short press: delete last character
    else if (!active) {
      if (displayText.length() > 0) {
        displayText.remove(displayText.length() - 1);
        updateLCDDisplay();
      }
      deleteBtnPressed = false;
      digitalWrite(LED_RED, LOW);
      delay(100);
    }
  }
}

/*
  =================== Utility Functions ===================
*/

// Convert Morse code string to corresponding letter
char decodeMorse(String morse) {
  for (int i = 0; i < 26; i++) {
    if (morse == morseCodes[i]) return letters[i];
  }
  return '?';  // Unknown Morse sequence
}

// Reset current Morse input state
void resetMorseInput() {
  currentMorse = "";
  lastButtonReleaseTime = millis();
}

// Update LCD display while preserving text history
void updateLCDDisplay() {
  lcd.clear();
  if (displayText.length() <= COLUMNS) {
    lcd.setCursor(0, 0);
    lcd.print(displayText);
  } else {
    lcd.setCursor(0, 0);
    lcd.print(displayText.substring(0, COLUMNS));
    lcd.setCursor(0, 1);
    lcd.print(displayText.substring(COLUMNS));
  }
}

// Blink the red LED a given number of times
void blinkRedLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_RED, HIGH);
    delay(BLINK_INTERVAL);
    digitalWrite(LED_RED, LOW);
    delay(BLINK_INTERVAL);
  }
}
