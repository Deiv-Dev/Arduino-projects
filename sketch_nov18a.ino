const int numLeds = 8; // Number of LEDs
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Updated pins connected to the LEDs
const int potPin = A4; // Pin connected to the rotary potentiometer

void setup() {
  // Set up LED pins as OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Read the analog value from the potentiometer
  int potValue = analogRead(potPin);

  // Map the potentiometer value to the range of the number of LEDs (0 to numLeds - 1)
  int ledIndex = map(potValue, 0, 1023, 0, numLeds);

  // Turn on LEDs up to the mapped index
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], i <= ledIndex ? HIGH : LOW);
    delay(50); // Add a small delay for a smoother effect
  }
  
  delay(100); // Add a delay between cycles to reduce sensitivity
}
