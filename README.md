# IoT Fish Tank Monitor

An IoT-based solution to monitor and manage your fish tank in real-time using an ESP32. The system monitors water parameters like temperature, pH, and water level, and displays the data on a dashboard accessible from anywhere.

## Features

- Real-time monitoring of water parameters
- Alerts for abnormal conditions
- Easy-to-use dashboard for visualization

## Hardware

- ESP32 development board
- Temperature sensor (DS18B20)
- pH sensor
- Water level sensor
- Power supply

## Software

- Arduino IDE for ESP32 firmware
- Blynk / custom web dashboard for real-time monitoring
- Arduino code on ESP32

## Folder Structure

iot-fish-tank-monitor/
├─ firmware/ # ESP32 code
├─ docs/ # Documentation (block diagrams, flowcharts)
├─ images/ # Screenshots / demo
├─ README.md
├─ LICENSE
└─ .gitignore


## Installation

1. Install [Arduino IDE](https://www.arduino.cc/en/software) and ESP32 board support.
2. Connect ESP32 to your PC.
3. Open `firmware/main.ino` in Arduino IDE and install the required libraries.
4. Configure Wi-Fi credentials and sensor pins.
5. Upload the code to ESP32.

## Usage

1. Power up the ESP32.
2. Connect to the dashboard.
3. Monitor water parameters in real-time.
4. Set alerts for thresholds (optional).

## Documentation

See `docs/` folder for:

- Block Diagram (`block_diagram.png`)
- Flow Chart (`flow_chart.png`)

