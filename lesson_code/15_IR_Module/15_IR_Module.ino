#include <DIYables_IRcontroller.h>              // Include the DIYables IR controller library

#define IR_RECEIVER_PIN 2                       // Define the Arduino pin connected to the IR receiver

DIYables_IRcontroller_21 irController(          // Create an IR controller object for a 21-key remote
  IR_RECEIVER_PIN,                              // Specify the pin used by the IR receiver
  200                                           // Set debounce time to 200 milliseconds
);

void setup() {                                  // Arduino setup function, runs once
  Serial.begin(115200);                         // Initialize serial communication at 115200 baud rate
  irController.begin();                         // Initialize the IR controller
}

void loop() {                                   // Arduino loop function, runs repeatedly
  Key21 command = irController.getKey();         // Read the pressed key from the IR remote

  if (command != Key21::NONE) {                 // Check if a valid key was received
    switch (command) {                          // Determine which key was pressed

      case Key21::KEY_CH_MINUS:                 // If the CH- key is pressed
        Serial.println("CH-");                  // Print "CH-" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_CH:                       // If the CH key is pressed
        Serial.println("CH");                   // Print "CH" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_CH_PLUS:                  // If the CH+ key is pressed
        Serial.println("CH+");                  // Print "CH+" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_PREV:                     // If the previous (<<) key is pressed
        Serial.println("<<");                   // Print "<<" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_NEXT:                     // If the next (>>) key is pressed
        Serial.println(">>");                   // Print ">>" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_PLAY_PAUSE:               // If the play/pause key is pressed
        Serial.println(">||");                  // Print ">||" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_VOL_MINUS:                // If the volume down key is pressed
        Serial.println("-");                    // Print "-" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_VOL_PLUS:                 // If the volume up key is pressed
        Serial.println("+");                    // Print "+" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_EQ:                       // If the EQ key is pressed
        Serial.println("EQ");                   // Print "EQ" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_100_PLUS:                 // If the 100+ key is pressed
        Serial.println("100+");                 // Print "100+" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_200_PLUS:                 // If the 200+ key is pressed
        Serial.println("200+");                 // Print "200+" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_0:                        // If the number 0 key is pressed
        Serial.println("0");                    // Print "0" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_1:                        // If the number 1 key is pressed
        Serial.println("1");                    // Print "1" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_2:                        // If the number 2 key is pressed
        Serial.println("2");                    // Print "2" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_3:                        // If the number 3 key is pressed
        Serial.println("3");                    // Print "3" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_4:                        // If the number 4 key is pressed
        Serial.println("4");                    // Print "4" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_5:                        // If the number 5 key is pressed
        Serial.println("5");                    // Print "5" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_6:                        // If the number 6 key is pressed
        Serial.println("6");                    // Print "6" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_7:                        // If the number 7 key is pressed
        Serial.println("7");                    // Print "7" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_8:                        // If the number 8 key is pressed
        Serial.println("8");                    // Print "8" to the serial monitor
        break;                                  // Exit the switch case

      case Key21::KEY_9:                        // If the number 9 key is pressed
        Serial.println("9");                    // Print "9" to the serial monitor
        break;                                  // Exit the switch case

      default:                                  // If the key is not recognized
        Serial.println("WARNING: undefined command:"); // Print a warning message
        break;                                  // Exit the switch case
    }
  }
}
