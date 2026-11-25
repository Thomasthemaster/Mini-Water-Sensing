# Mini Water Sensing Device
A project that uses the Analog Water Level Sensor Module from ELEGOO to detect how much of the module's copper conductive traces are submerged in a percentage.

---

## 🚀 How It Works

The sensor detects how much of its copper conductive traces are submerged. Then, it prints the percentage of copper conductive traces on the sensor submerged to the Serial Monitor. If the percentage is > 0%, meaning the sensor is wet, then the blue LED will light up, signaling that the sensor is wet. The sensor calculates the percentage of copper conductive traces submerged based on calibration data.

### Hardware
- **Development Board:** Arduino Nano
- **Main Components:** Analog Water Level Sensor Module
- **Software:** Arduino IDE

### Cool Features
- Blue LED Indicator

---

## 📊 Circuit Layouts

### Wiring Diagram

No wiring diagram was created for this project. 
Reason: **Wokwi does not have an Analog Water Level Sensor Module of any sort at the time of creation, and since the module is the main component of the build, it seemed unnecessary to create a wiring diagram without the main component.**
Instead, a Wire Pinout Table has been created to compensate:
🔌 Wiring Pinout

| Component | Arduino Nano Pin | Notes |
| :--- | :--- | :--- |
| Water Sensor `S` (Signal) | `A0` | Analog input |
| Water Sensor `+` (VCC) | `5V` | Power |
| Water Sensor `-` (GND) | `GND` | Ground |
| Blue LED Anode (`+`) | `D2` | Connect through 220Ω resistor |
| Blue LED Cathode (`-`) | `GND` | Ground |


### Schematic

Below is the schematic generated in Tinkercad:

[![Schematic](Schematic.png)](Schematic.png)

*Schematic coming soon*

---
## 🖼️ Project Photo

See the project (may have some issues viewing it on desktop):

[Click here](Mini_Water_Sensing_Device.png)

## 🎥 Video Demonstration

Watch the project in action + an explanation of the build:

[▶ Watch the Video](YOUTUBE_LINK_NOT_READY_YET)

---

## 🔧 Sensor Calibration

The water level sensor requires calibration because its analog output depends on water conductivity, sensor positioning, and immersion depth.

### Equipment
- ELEGOO Analog Water Level Sensor Module
- Microcontroller
- Water container
- Ruler
- Water

### Calibration Procedure

1. Connect the sensor's `S` pin to an Arduino analog input, `+` to 5V, and `-` to GND.
2. Upload an analog-reading sketch that uses `analogRead()`.
3. Open the Serial Monitor at 9600 baud.
4. Measure the length of the exposed copper sensing area.
5. Position the sensor vertically in the water.
6. Immerse 25%, 50%, 75%, and 100% of the exposed copper sensing area.
7. At each depth, record three analog readings and calculate their average.
8. Enter the resulting average ADC values into the calibration constants in the Arduino sketch.

### Original Calibration Results

| Immersion | Average ADC |
|---|---:|
| 25% | 361.3 |
| 50% | 383.0 |
| 75% | 392.0 |
| 100% | 398.7 |

### Important

These values are specific to the original experimental setup. Different water conductivity, temperature, sensor positioning, and sensor condition can produce different readings.

For reliable results, perform calibration using the same water and positioning conditions expected during operation.

{Sidenote: **This project measures immersion depth of the copper conductive traces on the water sensor, not actual tank volume or water height.**}

---
## 📁 Repository Contents

- `Mini_Water_Sensing_Device.ino` — Arduino source code
- `README.md` — Project documentation
- `LICENSE` — Apache License 2.0
- `Mini_Water_Sensing_Device.png` — Project photo
- `Schematic.png` — Coming Soon!

---

## 🛠️ Components Used

- Arduino Nano Board
- Analog Water Level Sensor Module [from ELEGOO]
- Blue LED
- 220 Ohm Resistor
- Jumper wires

---

## 💡 What I Learned

I learned how to use and calibrate the Analog Water Level Sensor Module from ELEGOO, and was able to create a mini-project that can detect the percentage of how much the water sensor's copper conductive traces are submerged based on calibration data.

---

**{Extra safety sidenote: Do not leave the Analog Water Level Sensor Module wet and powered for a long time. Otherwise, this risks electrochemical corrosion. Only leave the sensor powered during operation, and dry the sensor after each use.}**

---
## 📜 License

This project is licensed under the Apache License 2.0.

