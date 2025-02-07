const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; // Segment a-g
const int dpPin = 9; // Decimal Point
const int resetButton = 10; // Reset Button

const byte numbers[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

int counter = 9; // Start at 9
bool buttonPressed = false;
bool countdownFinished = false;

void setup() {
  Serial.begin(9600); // Start Serial Monitor

  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(dpPin, OUTPUT);
  pinMode(resetButton, INPUT_PULLUP); // Enable pull-up resistor

  Serial.println("Countdown starts from 9");
}

void loop() {
  if (!countdownFinished) {
    while (counter >= 0) {
      Serial.print("Countdown: ");
      Serial.println(counter);

      showDigit(counter);
      delay(1000); // Wait 1 second
      counter--;

      checkReset(); // Check if reset button is pressed
    }

    Serial.println("Countdown finished");
    countdownFinished = true; // Mark countdown as completed
  }

  // **Allow pressing the reset button at any time**
  checkReset();
}

void checkReset() {
  if (digitalRead(resetButton) == LOW) {
    if (!buttonPressed) {
      Serial.println("Resetting countdown...");
      counter = 9; // Reset to 9
      countdownFinished = false; // Allow countdown to restart
      buttonPressed = true; // Mark button as pressed
      delay(200); // Debounce delay
    }
  } else {
    buttonPressed = false; // Reset button state when released
  }
}

void showDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(numbers[num], i));
  }
  digitalWrite(dpPin, HIGH); // Turn on Decimal Point
  delay(500);
  digitalWrite(dpPin, LOW); // Turn off Decimal Point
}
