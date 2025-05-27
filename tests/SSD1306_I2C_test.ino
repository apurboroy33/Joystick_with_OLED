/*
Source code for SSD1306 OLED Display testing using I2C communication
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C address for most 0.96" OLEDs is 0x3C
#define OLED_ADDR 0x3C

// Create display object using I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

void setup() {
  // Initialize serial monitor (optional)
  Serial.begin(9600);

  // Initialize OLED display with I2C address
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Stay here if OLED doesn't initialize
  }

  display.clearDisplay(); // Clear the display buffer

  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(0, 10);            // Set starting position

  display.println("Hello there!");
  display.println("Your OLED works!");

  display.display(); // Push to screen
}

void loop() {
  // Empty loop for now
}
