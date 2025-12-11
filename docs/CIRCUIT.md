# Circuit Diagram: Ultra Gesture Switch Hardware Connections

This document details the wiring for the MVP using Arduino Uno, HC-SR04 ultrasonic sensor, LEDs. No soldering required – use jumper wires on a breadboard for prototyping. The design prioritizes simplicity and safety (e.g., resistors for LEDs to prevent burnout).

## Components List
- Arduino Uno.
- HC-SR04 Ultrasonic Sensor (VCC, Trig, Echo, GND).
- 5 LEDs (any color) + 5 x 220Ω resistors.
- Jumper wires (male-to-male/female).
- Breadboard (optional, for organized connections).
- 9V battery + connector (for portability).

## Pin Assignments
- **HC-SR04**:
  - VCC → Arduino 5V (power supply).
  - GND → Arduino GND (common ground).
  - Trig → Arduino Digital Pin 9 (output for pulse trigger; chosen for PWM capability if needed later).
  - Echo → Arduino Digital Pin 10 (input for echo duration; digital pin for precise timing).

- **LED Bar (Progressive Feedback)**:
  - LED 1 (farthest, for low proximity) → Arduino Digital Pin 2 (anode via 220Ω resistor) → GND (cathode).
  - LED 2 → Pin 3 → GND.
  - LED 3 → Pin 4 → GND.
  - LED 4 → Pin 5 → GND.
  - LED 5 (closest, for high proximity) → Pin 6 → GND.
  - Justification: Pins 2-6 are standard digital outputs; resistors limit current to ~20mA per LED.

- **Buzzer (Auditory Feedback)**:
  - Positive → Arduino Digital Pin 8 (output for tone signal).
  - Negative → Arduino GND.
  - Justification: Pin 8 is free for PWM/tone(); use active buzzer for simple HIGH/LOW control.

- **Power**:
  - Arduino via USB (for development) or 9V battery jack (Vin/GND).
  - Note: HC-SR04 draws ~15mA; total circuit <100mA – safe for battery.

## Wiring Diagram (Textual Representation)
Use this as a quick reference. For visual, generate with Fritzing and add to [assets/circuit_diagram.png](assets/circuit_diagram.png).


Arduino Uno
+----------+
| 5V  --- VCC (HC-SR04)
| GND  --- GND (all components)
| Pin9 --- Trig (HC-SR04)
| Pin10 -- Echo (HC-SR04)
| Pin2  --- LED1 (220Ω) --- GND
| Pin3  --- LED2 (220Ω) --- GND
| Pin4  --- LED3 (220Ω) --- GND
| Pin5  --- LED4 (220Ω) --- GND
| Pin6  --- LED5 (220Ω) --- GND
+----------+

## Assembly Tips
- **Breadboard Layout**: Place Arduino on one side; HC-SR04 on the opposite. Use rails for 5V/GND common.
- **Physical Mount**: Use cardboard stand (10x15cm): Fix HC-SR04 at top (hot glue), LEDs in row below. Angle sensor 15° for hand detection.
- **Safety Notes**: Double-check polarities (LED anodes to pins). Test voltages with multimeter if available (5V on VCC).
- **Troubleshooting**:
  - No echo: Check Trig/Echo wires (loose connections cause 70% errors).
  - Dim LEDs: Verify resistors (without, current spikes can damage Arduino).
  - Power issues: USB for testing; battery for demos (monitor voltage drop).

## Schematic Tool Recommendations
- Fritzing (free): Drag-and-drop for PNG export.
- Draw.io (online): For quick diagrams.
- Tinkercad: Simulate circuit virtually before building.

This circuit supports the algorithm in [ALGORITHM.md](ALGORITHM.md). Total cost: <R$50 with kit components. For expansions (e.g., joystick), see future features.