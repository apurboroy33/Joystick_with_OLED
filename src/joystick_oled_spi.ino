/*
Source code for SPI SSD1306 OLED Display with Arduino
Uses the SPI.h library
*/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// SPI pins for the OLED
#define OLED_MOSI   11
#define OLED_CLK    13
#define OLED_DC     8
#define OLED_CS     10
#define OLED_RESET  9

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         &SPI, OLED_DC, OLED_RESET, OLED_CS);

// Joystick pins
const int VRx = A0;
const int VRy = A1;
const int SW = 2;

// LED pin
const int ledPin = 7;

void setup() {
  pinMode(SW, INPUT_PULLUP);  // Joystick button
  pinMode(ledPin, OUTPUT);    // LED output
  Serial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println("OLED not found");
    while (true);  // Halt
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);
  display.println("Joystick");
  display.display();
  delay(1000);
}

void loop() {
  int x = analogRead(VRx);
  int y = analogRead(VRy);
  int sw = digitalRead(SW);  // LOW when pressed

  String direction = getDirection(x, y);

  // OLED Display
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("Dir: ");
  display.println(direction);

  if (sw == LOW) {
    digitalWrite(ledPin, HIGH);  // Turn on LED
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.print("Button: Pressed");
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
  }

  display.display();
  delay(200);
}

String getDirection(int x, int y) {
  if (x < 400) return "LEFT";
  else if (x > 600) return "RIGHT";
  else if (y < 400) return "UP";
  else if (y > 600) return "DOWN";
  else return "CENTER";
}
