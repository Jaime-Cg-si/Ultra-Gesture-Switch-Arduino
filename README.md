# Ultra Gesture Switch: Arduino Gesture Detection Project

[![Arduino](https://img.shields.io/badge/Platform-Arduino-blue)](https://www.arduino.cc/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub stars](https://img.shields.io/github/stars/Jaime-Cg-si/Ultra-Gesture-Switch-Arduino?style=social)](https://github.com/Jaime-Cg-si/Ultra-Gesture-Switch-Arduino)

## Overview
The Ultra Gesture Switch is a simple yet innovative DIY project that uses an HC-SR04 ultrasonic sensor to detect hand proximity and control outputs like LEDs and a buzzer. Approaching your hand within 20cm activates the system (turning on lights), while moving away deactivates it. This serves as an entry-level gesture recognition prototype, blending electronics with basic embedded programming.

Inspired by IoT and human-computer interaction (HCI) concepts, it's designed for beginners in computing and electronics. Future expansions could include multi-gesture support or integration with servo motors for robotic arms.

**Key Features:**
- Ultrasonic distance measurement for "on/off" gestures.
- Visual (LED bar) feedback.
- Hysteresis to prevent false triggers.
- Portable with 9V battery support.

## Hardware Requirements
- Arduino Uno (or compatible board).
- HC-SR04 Ultrasonic Sensor (1x).
- LEDs (3-5x, with 220Ω resistors).
- Jumper wires.
- 9V battery and connector (optional for portability).
- Breadboard or protoboard for prototyping.
- Cardboard, hot glue gun, and craft knife for enclosure (DIY mounting).

No soldering required for the MVP – use jumper wires for quick iteration.

## Software Requirements
- Arduino IDE (version 1.8+).
- Standard Arduino libraries (e.g., no external dependencies for v1.0).

## Installation
1. Clone this repository:  
git clone https://github.com/Jaime-Cg-si/Ultra-Gesture-Switch-Arduino.git2. Open `src/ultra_gesture_switch.ino` in the Arduino IDE.
3. Connect the hardware as described in [docs/CIRCUIT.md](docs/CIRCUIT.md).
4. Select your board (Arduino Uno) and port in the IDE.
5. Upload the sketch: Tools > Upload.

## Usage
1. Power the Arduino via USB or 9V battery.
2. Position the HC-SR04 sensor facing the interaction area (e.g., on a cardboard stand).
3. Perform the gesture:
- **Activate**: Approach your hand within 20cm – LEDs light up progressively.
- **Deactivate**: Move your hand away beyond 25cm (hysteresis prevents flickering).
4. Monitor debug output in the Serial Monitor (9600 baud) for distance readings.

Example: In a desk setup, use it as a "proximity alarm" for notifications.

## Circuit Diagram
![Circuit Diagram](assets/circuit_diagram.png)  
*(Placeholder: Add a Fritzing or Draw.io schematic here showing pin connections: Trig to Pin 9, Echo to Pin 10, LEDs to Pins 2-6, Buzzer to Pin 8.)*

For detailed wiring, see [docs/CIRCUIT.md](docs/CIRCUIT.md).

## Algorithm Overview
The core logic follows a simple event-driven loop:
- Send ultrasonic pulse and measure echo time.
- Calculate distance using the speed of sound formula: `distance = (duration * 0.034) / 2` (in cm).
- Apply threshold logic with hysteresis: If distance &lt; 20cm and previous state off → Turn on outputs. If >25cm and on → Turn off.
- Filter noise with averaged readings to improve reliability.

Detailed pseudocode in [docs/ALGORITHM.md](docs/ALGORITHM.md).

## Testing and Validation
- **Unit Tests**: Verify distance readings at 10cm, 20cm, 50cm using a ruler.
- **Integration Tests**: Perform 20 gestures; aim for >80% accuracy.
- **Edge Cases**: Test in low light (ultrasonic is immune), with obstacles, and battery power.

Results logged in [docs/TESTS.md](docs/TESTS.md). Example accuracy: 85% in controlled environments.

## Limitations and Improvements
- **Current Limits**: Narrow field of view (~15°); sensitive to temperature (±2cm error). No multi-gesture support yet.
- **Known Issues**: False positives from fixed objects – mitigated by hysteresis.
- **Future Enhancements**:
- Add joystick for gesture calibration.
- Integrate servo motor for physical responses (e.g., robotic arm extension).
- Machine learning lite for advanced gesture classification (using Arduino Nano 33 BLE Sense).
- Bluetooth module for app control.

Contributions welcome! See [CONTRIBUTING.md](CONTRIBUTING.md).

## Project Structure
- `/src/`: Arduino sketch files (.ino).
- `/docs/`: Detailed guides (circuit, algorithm, assembly, tests).
- `/assets/`: Images, diagrams, and demo videos.
- `/tests/`: Validation data and scripts.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments
Built with Arduino ecosystem. Inspired by HCI research and maker communities like Hackster.io.

---

*Author: Jaime C. | Student in Computing | Second Semester*  
*Last Updated: [11 / 12 / 25] | Version: v1.0*