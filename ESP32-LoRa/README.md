# ESP32-with-LoRa
Designing a microwave sensor node using ESP32 and LoRa for water quality monitoring
## Overview
This project implements a wireless sensor node that uses microwave signal attenuation to monitor water quality. It is built using ESP32 microcontrollers and LoRa SX1278 modules operating at 433 MHz, integrated with a custom-fabricated directional coupler and a coaxial microwave sensor. The system estimates attenuation based on RSSI values and correlates them with water sample properties, including salinity.

# Key Features

- Uses ESP32 (transmitter and receiver) programmed in Arduino IDE for data acquisition, LoRa communication, and real-time processing.
- LoRa SX1278 modules enable low-power, long-range communication at 433 MHz.
- Transmitter(ESP32 +LoRa) sends data packets per second; receiver(ESP32+LoRa) calculates median RSSI per batch and estimated attenuation.
- Calibration graph charted out on MATLAB using polyfit() for plotting Attenuation vs Median RSSI to analyse attenuation in realtime based on median RSSI 
- Custom-designed and fabricated directional coupler (433 MHz)  and Coaxial microwave sensor detects changes in dielectric properties of water.
- Sensor tested various samples of water like molarities of saline water.
- Calibration and molarity analysis performed in MATLAB.
- Final build soldered onto perfboard for improved stability and portability.

# Skills That Actually Went Into This

- Embedded C++ with Arduino for ESP32
- LoRa-based communication and packet handling
- RSSI signal processing and real-time computation
- MATLAB for curve fitting, error plotting, and molarity graphs
- Custom PCB-ish build using perfboard (yeah, soldered)
