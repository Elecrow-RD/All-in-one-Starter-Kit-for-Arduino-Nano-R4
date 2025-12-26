// ================== Pin Definitions ==================
#define LED_RED     5
#define LED_YELLOW  10
#define LED_GREEN   11

#define Button_Pin  A3   // Analog button input

// ================== Game Settings ==================
#define MAX_LEVEL     10

int levelLength = 5;      // Sequence length (difficulty)
int flashDelay  = 400;    // LED flash speed (ms)

// ================== Variables ==================
int ledSequence[MAX_LEVEL];
int userIndex = 0;

// ================== Setup ==================
void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(Button_Pin, INPUT);

  Serial.begin(115200);
  randomSeed(analogRead(A0));

  startGame();
}

// ================== Main Loop ==================
void loop() {
  int button = readButton();

  if (button != 0) {
    flashSingleLED(button);

    if (button == ledSequence[userIndex]) {
      userIndex++;

      // All correct
      if (userIndex >= levelLength) {
        successLED();
        delay(500);
        startGame();
      }
    } else {
      failLED();
      delay(500);
      startGame();
    }

    delay(300); // Prevent a single key press from being read multiple times
  }
}

// ================== Game Functions ==================

void startGame() {
  userIndex = 0;
  generateSequence();
  showSequence();
}

// Generate random LED order
void generateSequence() {
  for (int i = 0; i < levelLength; i++) {
    ledSequence[i] = random(1, 4); // 1=Red, 2=Yellow, 3=Green
  }
}

// Show LED flashing sequence
void showSequence() {
  delay(800);
  for (int i = 0; i < levelLength; i++) {
    flashSingleLED(ledSequence[i]);
    delay(200);
  }
}

// ================== Button Reading ==================
// Return: 1=Red, 2=Yellow, 3=Green, 0=None
int readButton() {
  int val = analogRead(Button_Pin);
  Serial.println(val);

  if (val >= 500 && val <= 520) return 1;   // Red
  if (val >= 680 && val <= 690) return 2;   // Yellow
  if (val >= 845 && val <= 860) return 3;   // Green

  return 0;
}

// ================== LED Control ==================
void flashSingleLED(int num) {
  allLEDOff();

  if (num == 1) digitalWrite(LED_RED, HIGH);
  if (num == 2) digitalWrite(LED_YELLOW, HIGH);
  if (num == 3) digitalWrite(LED_GREEN, HIGH);

  delay(flashDelay);
  allLEDOff();
}

// ================== Success Effect ==================
void successLED() {
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  delay(1000);
  allLEDOff();
}

// ================== Fail Effect ==================
void failLED() {
  for (int i = 0; i < 10; i++) {
    allLEDOn();
    delay(100);
    allLEDOff();
    delay(100);
  }
}

// ================== Utility ==================
void allLEDOn() {
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_GREEN, HIGH);
}

void allLEDOff() {
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
}
