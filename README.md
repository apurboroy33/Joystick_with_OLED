# Joystick_with_OLED_Screen

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
### 🎮 Joystick Module

| Joystick Pin | Arduino Pin |
|--------------|-------------|
| GND          | GND         |
| +5V (VCC)    | 5V          |
| VRx          | A0          |
| VRy          | A1          |
| SW           | D2          |

### 🖥️ OLED Display (I2C)

| OLED Pin | Arduino Pin |
|----------|-------------|
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

### 💡 LED

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

- After all the connections are made up, open the source code (present in src folder) in **Arduino IDE**.
- Click **Compile** first (check for any errors), then hit **Upload**.
- After a few seconds, your Arduino Uno will run the code and your project will work like a charm.

## 🚀 Future Enhancements
