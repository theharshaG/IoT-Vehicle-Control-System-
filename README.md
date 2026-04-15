# IoT-Vehicle-Control-System

RFID Based Smart Speed Control System (IoT Project)

## Overview

This project is an IoT-based Smart Speed Control System using ESP32 and RFID technology. It controls the speed of a vehicle (motor) based on RFID tags placed in different zones such as school or hospital areas. When the RFID reader detects a tag, the system adjusts the motor speed accordingly.

## Features

RFID-based zone detection
Automatic speed control
Multiple zone support (School, Hospital, Normal)
Real-time tag reading
Motor control using driver module
Customizable speed levels

## Technologies Used

ESP32 (Arduino IDE)
RFID Module (MFRC522)
SPI communication
Motor driver (L298N or similar)
Embedded C++

## Project Structure

rfid-speed-control-system/
│
├── main.ino
└── README.md

## How to Run

install Arduino IDE
Install ESP32 board support
Install MFRC522 library
Connect RFID module and motor driver to ESP32
Update RFID tag UID values in code
Upload code to ESP32

## How It Works

ESP32 initializes RFID module using SPI communication

The vehicle (motor) moves forward at normal speed by default

When an RFID tag is detected:
The UID of the tag is read

Based on UID:
Specific zones are identified

Example:
School Zone → Speed reduced
Hospital Zone → Medium speed
Unknown Zone → Normal speed

Motor speed is controlled using PWM signals

After a delay, the system returns to normal speed

## Future Improvements

Add more zones with different speed limits
Integrate GPS for location-based control
Add display to show current zone
Add buzzer for alerts
Store logs for tracking
Develop mobile app for monitoring

## Author
Harsha G
Learning Python | Embedded Systems | IoT
