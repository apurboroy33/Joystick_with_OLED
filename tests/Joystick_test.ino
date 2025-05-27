// Define joystick pins
const int VRx = A0; // X-axis
const int VRy = A1; // Y-axis
const int SW = 2;   // Switch button

void setup() {
  Serial.begin(9600);        // Start serial communication
  pinMode(SW, INPUT_PULLUP); // Set switch pin as input with pull-up resistor
}

void loop() {
  int xValue = analogRead(VRx); // Read X-axis value
  int yValue = analogRead(VRy); // Read Y-axis value
  int swState = digitalRead(SW); // Read button state (LOW when pressed)

  // Print the values to Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | Switch: ");
  Serial.println(swState == LOW ? "Pressed" : "Released");

  delay(1000); // Delay for stability
}
