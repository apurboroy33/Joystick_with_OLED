# Joystick_with_OLED

## 🎮 Arduino Joystick with OLED Display and LED Indicator

This project demonstrates how to interface a **joystick module** with an **Arduino**, display the joystick **movement direction** on an **I2C OLED display**, and light up an **LED** when the joystick switch is pressed.

## 🧰 Components Used

- Arduino Uno (or any compatible board)
- Joystick module (with X, Y, and button outputs)
- 0.96" I2C OLED Display (SSD1306, 128x64)
- LED + 220Ω resistor (optional)
- Jumper wires
- Breadboard (optional)

## 🔌 Circuit Connections
### Joystick Module

| Joystick Pin | Arduino Pin |
|--------------|-------------|
| GND          | GND         |
| +5V (VCC)    | 5V          |
| VRx          | A0          |
| VRy          | A1          |
| SW           | D2          |

### OLED Display (I2C)

| OLED Pin | Arduino Pin |
|----------|-------------|
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

### LED

| LED Pin       | Arduino Pin |
|---------------|-------------|
| Anode (+)     | D8 (via 220Ω resistor) |
| Cathode (–)   | GND         |

## 🔌 Circuit

<img src="media/Joystick_with_OLED_Screen.png" style="width:550px;"/>

## 📦 Library Dependencies

Install the following libraries via **Arduino Library Manager**:

- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)

## 🖱️ Uploading the code

- After all the connections are made up, open the source code (present in [src](src/joystick_oled.ino) folder) in **Arduino IDE**.
- Click **Compile** first (check for any errors), then hit **Upload**.
- After a few seconds, your Arduino Uno will run the code and your project will work like a charm.

## ⚠️ Precautions

Take the following precautions to ensure safe and reliable operation of your OLED + Joystick + LED setup with Arduino.

### Wiring & Power
- Double-check all connections before powering the Arduino.
- Ensure all components share a common **GND**.
- Use the correct voltage levels (typically 5V for OLED, joystick, and Arduino Uno).
- Connect OLED **SDA to A4** and **SCL to A5** (on Uno/Nano).
- Avoid reversed connections of **VCC** and **GND**.
- Use a **220Ω–330Ω resistor** in series with the LED.
- Do not exceed the current draw from Arduino’s **5V** pin.
- Power the Arduino using a **regulated 7–12V supply** (center-positive) if not using USB.

### OLED Display
- Use the correct **I2C address** (usually `0x3C`).
- Avoid displaying static images for long durations (prevents burn-in).
- Use `display.clearDisplay()` and `display.display()` properly to update screen content.
- Power off the display when not in use for extended periods.

### Joystick Module
- Do not press or move the joystick excessively hard — it uses delicate potentiometers.
- Handle the switch gently and don’t force press it.
- Use `INPUT_PULLUP` for the switch pin to prevent erratic behavior.
- Handle analog values with range comparisons (not exact values due to noise).

### LED Output
- Always use a current-limiting resistor to prevent pin overload.
- Check the LED polarity before wiring (long leg = +, short leg = –).
- Avoid drawing more than 20mA from a single pin.

### Debugging Tips
- Test OLED and joystick **individually first**, then combine.
- Use **Serial Monitor** to check raw analog readings during development.
- Add delays (`delay(100–200ms)`) in the loop to avoid flickering and serial flooding.

### Safety
- Never touch the circuit with wet hands or metal tools while powered.
- Disconnect power when rewiring or adjusting the circuit.
- Place the project on a **non-conductive surface**.

### Build Best Practices
- Use **color-coded or labeled wires** to keep wiring clear.
- Secure components on a breadboard or perfboard for stability.
- Add `.gitkeep` files in folders to maintain project structure in GitHub.

## 📝 License

This project is open-source and free to use for educational and non-commercial purposes.

## 🚀 Future Enhancements
- Use to control servos, robots, or game sprites
- Add graphics (e.g., arrows) on OLED
- Add a buzzer for click feedback
- Display raw X/Y analog values

