# Developing an Automatic Engine Car Lock System Using Alcohol Sensor

## Problem Statement
Despite stringent government regulations, heavily publicized road safety campaigns, and continuous public sensitization, drunk driving continued to cause preventable accidents, economic losses, and fatalities across Uganda. The primary flaw in existing interventions was their heavy reliance on human enforcement, which was inherently reactive, intermittent, and easily bypassed. 
Once an intoxicated driver sat behind the wheel, there was no onboard mechanical or electronic safeguard to prevent them from operating the vehicle. Therefore, a critical need existed for a real-time, proactive, and automated in-vehicle system capable of independently assessing alcohol levels and immediately locking out the ignition system before an impaired driver could endanger road users. 

## Proposed Solution
This project presents an automated vehicle ignition interlock system that shifts road safety from reactive enforcement to proactive prevention. It uses an Arduino Uno integrated with an MQ-3 semiconductor gas sensor to measure Breath Alcohol Concentration (BrAC). If alcohol is detected above a set threshold, the system triggers a 12V automotive relay to safely interrupt the vehicle's ignition circuit, preventing the engine from starting. Real-time status is displayed on an I2C LCD screen, supported by a buzzer alert and dual-color LED indicators.

## Hardware Components
| Component | Purpose |
|---|---|
| Arduino Uno | Main microcontroller |
| MQ-3 Alcohol Sensor | Detects Breath Alcohol Concentration (BrAC) |
| 12V Relay | Interrupts vehicle ignition circuit |
| I2C LCD Display (16x2, address 0x27) | Displays system status |
| Red LED | Indicates alcohol detected / unsafe state |
| Green LED | Indicates safe state |
| Buzzer | Audible alcohol alert |

## Pin Configuration
| Pin | Component |
|---|---|
| A0 | MQ-3 Sensor (Analog Output) |
| D2 | Buzzer |
| D3 | Red LED |
| D4 | Relay |
| D5 | Green LED |
| A4 / A5 | I2C LCD (SDA / SCL) |

## Required Libraries
Install these via **Arduino IDE → Sketch → Include Library → Manage Libraries**:
- `Wire.h` (built-in with Arduino IDE)
- `LiquidCrystal_I2C.h` (search "LiquidCrystal I2C" by Frank de Brabander)

## Calibration Instructions
1. Power the MQ-3 sensor and allow a preheat.
2. Before each test session, allow 2–3 minutes warm-up with power applied.
3. Observe baseline `sensorValue` readings via Serial Monitor (9600 baud) in clean air — this should be a low, stable number.
4. Adjust the `THRESHOLD` constant in the code (default: `400`) based on your baseline and desired sensitivity.
5. Use the onboard potentiometer on the MQ-3 module for coarse sensitivity adjustment.

## How to Run
1. Wire the components according to the pin configuration table above.
2. Open `AlcoholDetector.ino` in Arduino IDE.
3. Select **Tools → Board → Arduino Uno** and the correct **Port**.
4. Click **Upload**.
5. Open **Serial Monitor** (9600 baud) to view live sensor readings.
6. The LCD will display **"STATUS: SAFE"** under normal conditions and **"ALERT"** when alcohol is detected, with the relay cutting the ignition circuit accordingly.

## Author
Final year project of engineering group 32.
July,2026.
