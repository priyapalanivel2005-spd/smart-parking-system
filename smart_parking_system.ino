/*
  Smart Parking System
  --------------------
  Hardware:
  - Arduino Uno
  - IR Sensor: Gate      -> D4
  - IR Sensor: Slot 1    -> D2
  - IR Sensor: Slot 2    -> D3
  - Servo Motor           -> D5
  - 16x2 I2C LCD         -> SDA A4, SCL A5

  Assumption:
  IR sensor output LOW = vehicle detected / slot occupied.
  Gate servo opens when a vehicle is detected at the entrance.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define SLOT1_SENSOR_PIN 2
#define SLOT2_SENSOR_PIN 3
#define GATE_SENSOR_PIN  4
#define SERVO_PIN        5

#define GATE_CLOSED_ANGLE 0
#define GATE_OPEN_ANGLE   90

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gateServo;

void setup() {
  pinMode(SLOT1_SENSOR_PIN, INPUT);
  pinMode(SLOT2_SENSOR_PIN, INPUT);
  pinMode(GATE_SENSOR_PIN, INPUT);

  gateServo.attach(SERVO_PIN);
  gateServo.write(GATE_CLOSED_ANGLE);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  bool slot1Occupied = (digitalRead(SLOT1_SENSOR_PIN) == LOW);
  bool slot2Occupied = (digitalRead(SLOT2_SENSOR_PIN) == LOW);
  bool vehicleAtGate = (digitalRead(GATE_SENSOR_PIN) == LOW);

  // Display parking slot availability.
  lcd.setCursor(0, 0);
  lcd.print("S1:");
  lcd.print(slot1Occupied ? "FULL " : "EMPTY");

  lcd.setCursor(8, 0);
  lcd.print("S2:");
  lcd.print(slot2Occupied ? "FULL " : "EMPTY");

  // Open the gate when a vehicle is detected.
  if (vehicleAtGate) {
    lcd.setCursor(0, 1);
    lcd.print("Vehicle Detected");

    gateServo.write(GATE_OPEN_ANGLE);
    delay(2000);

    // Wait until the vehicle leaves the gate sensor.
    while (digitalRead(GATE_SENSOR_PIN) == LOW) {
      delay(50);
    }

    gateServo.write(GATE_CLOSED_ANGLE);
    delay(500);
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Gate: CLOSED    ");
    gateServo.write(GATE_CLOSED_ANGLE);
  }

  delay(200);
}
