#define BUZ 3
// Seven basic note frequencies (4/4 time, C4–B4, in Hz)
int m[] = {262, 294, 330, 349, 392, 440, 494};  // C D E F G A B
int d[] = {4, 4, 4, 4, 4, 4, 4};                // Each note is a quarter note

void setup() {
  pinMode(BUZ, OUTPUT);
}

void loop() {
  for (int i = 0; i < 7; i++) {
    int t = 1000 * 4 / d[i] * 60 / 100;  // 100 BPM
    tone(BUZ, m[i], t * 0.9);
    delay(t);
    noTone(BUZ);
  }
  delay(2000);  // Two-second interval before repeating playback
}