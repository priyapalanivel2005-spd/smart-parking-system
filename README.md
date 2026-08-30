# 🚗 Smart Parking System using Arduino

An Arduino-based **Smart Parking System** designed to automatically detect vehicles, monitor parking slot availability, and control the entrance gate using IR sensors, a servo motor, and an LCD display.

## 📌 Overview

Finding available parking spaces can be difficult in crowded areas, and manual parking management can lead to unnecessary waiting and congestion.

This project provides a simple and low-cost solution by using **IR sensors to detect vehicles**, an **Arduino Uno to process the sensor data**, a **servo motor to control the parking gate**, and a **16×2 I2C LCD to display parking slot availability in real time**.

The prototype monitors **two parking slots** and automatically controls the entrance gate when a vehicle is detected.

---

## 🎯 Objectives

* Automatically detect vehicles entering the parking area.
* Monitor the availability of two parking slots.
* Control the parking entrance gate automatically.
* Display parking slot status in real time.
* Develop a low-cost and easy-to-expand parking automation system.

---

## ✨ Features

* 🚗 Automatic vehicle detection using IR sensors
* 🅿️ Real-time monitoring of two parking slots
* 🚪 Automatic gate control using a servo motor
* 📺 16×2 I2C LCD status display
* 🔄 Continuous parking status monitoring
* ⚡ Low-cost embedded system
* 🔧 Simple hardware integration
* 📈 Expandable to support additional parking slots

---

## 🛠️ Components Required

| Component                |    Quantity |
| ------------------------ | ----------: |
| Arduino Uno              |           1 |
| IR Sensors               |           3 |
| Servo Motor              |           1 |
| 16×2 LCD with I2C Module |           1 |
| Breadboard / PCB         |           1 |
| Jumper Wires             | As required |
| Power Supply             |           1 |

---

## 🔌 Pin Configuration

| Component        | Signal | Arduino Uno Pin |
| ---------------- | ------ | --------------: |
| Slot 1 IR Sensor | OUT    |              D2 |
| Slot 2 IR Sensor | OUT    |              D3 |
| Gate IR Sensor   | OUT    |              D4 |
| Servo Motor      | Signal |              D5 |
| LCD              | SDA    |              A4 |
| LCD              | SCL    |              A5 |

### Power Connections

**IR Sensors**

* VCC → 5V
* GND → GND
* OUT → D2 / D3 / D4

**Servo Motor**

* Signal → D5
* VCC → 5V
* GND → GND

**16×2 I2C LCD**

* VCC → 5V
* GND → GND
* SDA → A4
* SCL → A5

> For a larger servo motor, use an appropriate external 5V supply and connect the external supply GND to Arduino GND.

---

## ⚙️ How It Works

The Arduino Uno acts as the main controller of the system.

### 1. Vehicle Detection

The IR sensor installed at the entrance detects an approaching vehicle.

The gate sensor is connected to **D4**.

When the sensor detects a vehicle, the Arduino processes the signal.

### 2. Automatic Gate Control

The servo motor is connected to **D5**.

When a vehicle is detected:

```text
Vehicle Detected
       ↓
Gate IR Sensor
       ↓
Arduino Uno
       ↓
Servo Motor
       ↓
Gate Opens
```

After the vehicle passes the entrance sensor, the servo returns to its closed position.

### 3. Parking Slot Detection

Two IR sensors monitor the parking slots:

```text
Slot 1 → D2
Slot 2 → D3
```

The system continuously checks whether a vehicle is present in each slot.

The project assumes:

```text
LOW  → Vehicle detected → Slot FULL
HIGH → No vehicle       → Slot EMPTY
```

### 4. LCD Display

The 16×2 I2C LCD displays the current parking status.

Example:

```text
S1:FULL  S2:EMPTY
Gate: CLOSED
```

This allows the user to quickly identify available parking spaces.

---

## 🔄 System Flow

```text
           Vehicle Approaches
                   ↓
            Gate IR Sensor
                   ↓
              Arduino Uno
                   ↓
             Servo Motor
                   ↓
              Gate Opens
                   ↓
          Vehicle Enters Area
                   ↓
          Slot IR Sensors
                   ↓
              Arduino Uno
                   ↓
             LCD Display
                   ↓
        Slot Availability Status
```

---

## 🧠 System Architecture

```text
       ┌─────────────────────┐
       │      IR Sensors     │
       │                     │
       │ Slot 1 | Slot 2     │
       │       | Gate        │
       └──────────┬──────────┘
                  │
                  ▼
       ┌─────────────────────┐
       │     Arduino Uno     │
       │   Main Controller   │
       └─────────┬───┬───────┘
                 │   │
          ┌──────┘   └──────┐
          ▼                 ▼
   ┌─────────────┐   ┌─────────────┐
   │ Servo Motor │   │  16×2 LCD   │
   │ Gate Control│   │ Slot Status │
   └─────────────┘   └─────────────┘
```

---

## 💻 Software

* **Arduino IDE**
* **Embedded C/C++**
* Arduino Servo Library
* LiquidCrystal_I2C Library

---

## 📂 Project Structure

```text
smart-parking-system-arduino/
│
├── README.md
│
├── src/
│   └── smart_parking_system.ino
│
├── docs/
│   └── pin-configuration.md
│
└── images/
    ├── hardware-setup.jpg
    ├── circuit-diagram.jpg
    └── lcd-output.jpg
```

### File Description

| File / Folder              | Description                |
| -------------------------- | -------------------------- |
| `README.md`                | Project documentation      |
| `src/`                     | Arduino source code        |
| `smart_parking_system.ino` | Main Arduino program       |
| `docs/`                    | Additional documentation   |
| `pin-configuration.md`     | Hardware pin configuration |
| `images/`                  | Project and output images  |

---

## 🚀 Getting Started

### 1. Install Arduino IDE

Download and install the Arduino IDE from:

https://www.arduino.cc/en/software

### 2. Install Required Libraries

Install:

* Servo
* LiquidCrystal_I2C

### 3. Connect the Hardware

Connect the components according to the pin configuration provided above.

### 4. Open the Code

Open:

```text
src/smart_parking_system.ino
```

in Arduino IDE.

### 5. Select Arduino Uno

In Arduino IDE:

```text
Tools → Board → Arduino Uno
```

Select the appropriate COM port.

### 6. Upload

Click **Upload** and wait for the program to be transferred to the Arduino Uno.

---

## 📸 Project Output

Add your actual project photographs here.

### Hardware Setup

![Smart Parking Hardware](images/hardware-setup.jpg)

### Circuit

![Circuit Diagram](images/circuit-diagram.jpg)

### LCD Output

![LCD Output](images/lcd-output.jpg)

---

## 🔮 Future Scope

The prototype can be further improved by integrating IoT and automation technologies.

* 📱 Mobile application for real-time parking availability
* ☁️ Cloud-based parking data storage
* 🌐 IoT-based remote monitoring
* 🎫 Online parking slot reservation
* 💳 Automated digital payment
* 🔢 RFID-based vehicle identification
* 📷 License plate recognition using computer vision
* 📊 Parking usage and occupancy analytics
* 🅿️ Support for multiple parking slots
* 🔔 Notifications when parking slots become available
* 🤖 AI-based vehicle detection and smart parking optimization

---

## 🎓 Learning Outcomes

Through this project, we gained practical experience in:

* Embedded system design
* Arduino programming
* Embedded C/C++
* IR sensor interfacing
* Servo motor control
* LCD interfacing
* I2C communication
* Microcontroller programming
* Hardware integration
* Real-time monitoring
* Basic automation

---

## 👨‍💻 Project Information

**Project:** Smart Parking System
**Platform:** Arduino Uno
**Domain:** Embedded Systems & Automation
**Type:** Academic / Prototype Project

---

## 📄 License

This project is intended for educational and academic purposes.
