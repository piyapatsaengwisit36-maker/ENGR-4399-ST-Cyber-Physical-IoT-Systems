# ENGR 4399 ST: Cyber-Physical & IoT Systems
## Simulation Assignment 2 — ESP32 Joystick-Controlled Servo

**Student:** Jacob kebbel  
**Instructor:** Dr. Okan Caglayan  
**Semester:** Fall 2026

## Project Description

This project uses an ESP32 Dev Module, analog joystick, and servo motor in Wokwi. The ESP32 reads the joystick X-axis and maps the analog value to a servo position from 0 to 180 degrees. The Y-axis is also read and displayed in the Serial Monitor. Pressing the joystick push button centers the servo at 90 degrees.

The project demonstrates ESP32 GPIO management, ADC input, digital input using an internal pull-up resistor, servo pulse control, and UART Serial monitoring.

## Components

- ESP32 Dev Module
- Analog joystick
- Hobby servo motor
- Jumper wires

## Pin Mapping

| ESP32 Pin | Connection | Purpose |
|---|---|---|
| GPIO34 | Joystick HORZ | X-axis ADC input |
| GPIO35 | Joystick VERT | Y-axis ADC input |
| GPIO18 | Joystick SEL | Push-button input |
| GPIO19 | Servo PWM | Servo control signal |
| 3V3 | Joystick VCC | Joystick power |
| 5V | Servo V+ | Servo power in simulation |
| GND | Joystick/Servo GND | Common ground |

## How It Works

The ESP32 reads the joystick using its analog inputs. The X-axis value ranges from 0 to 4095 and is mapped to a servo angle from 0 to 180 degrees. The program generates the servo control pulse directly on GPIO19, so no external servo library is required.

The joystick button uses `INPUT_PULLUP`. The button reads HIGH when released and LOW when pressed. When pressed, the program commands the servo to return to 90 degrees.

The Serial Monitor runs at 115200 baud and displays the X-axis value, Y-axis value, button state, and commanded servo angle.

## Test Cases

| Test | Action | Expected Behavior |
|---|---|---|
| 1 | Move joystick left | Servo moves toward 0 degrees |
| 2 | Move joystick right | Servo moves toward 180 degrees |
| 3 | Press joystick button | Servo returns to 90 degrees |

## Wokwi Simulation

Add the permanent saved/share Wokwi project URL here before final submission.

> Note: `https://wokwi.com/projects/new/esp32` is the project creation page, not the permanent URL for the saved simulation.

## Files

- `sketch.ino` — ESP32 source code
- `diagram.json` — Wokwi circuit configuration
- `README.md` — project documentation
