# Smart Parking System - Pin Configuration

## Arduino Uno Pin Mapping

| Component | Signal | Arduino Uno Pin | Purpose |
|---|---|---:|---|
| IR Sensor - Slot 1 | OUT | D2 | Detects whether Slot 1 is occupied |
| IR Sensor - Slot 2 | OUT | D3 | Detects whether Slot 2 is occupied |
| IR Sensor - Gate | OUT | D4 | Detects an incoming vehicle |
| Servo Motor | Signal | D5 | Opens/closes the parking gate |
| 16x2 I2C LCD | SDA | A4 | I2C data communication |
| 16x2 I2C LCD | SCL | A5 | I2C clock communication |

## Power Connections

### IR Sensors
- VCC → Arduino 5V
- GND → Arduino GND
- OUT → D2 / D3 / D4

### Servo Motor
- Signal → D5
- VCC → 5V
- GND → GND

> For a larger servo, use a suitable external 5V supply and connect its GND to Arduino GND.

### 16x2 I2C LCD
- VCC → Arduino 5V
- GND → Arduino GND
- SDA → A4
- SCL → A5

## Sensor Logic

The project assumes the IR sensors use:

- `LOW` → Vehicle detected / Slot occupied
- `HIGH` → No vehicle detected / Slot empty

## System Flow

IR Sensors → Arduino Uno → Servo Motor + I2C LCD

## Summary

D2 → Slot 1 IR Sensor
D3 → Slot 2 IR Sensor
D4 → Gate IR Sensor
D5 → Servo Motor
A4 → LCD SDA
A5 → LCD SCL
