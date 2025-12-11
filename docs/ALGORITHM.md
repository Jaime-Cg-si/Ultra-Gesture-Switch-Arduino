# Algorithm Overview: Gesture Detection with HC-SR04

This document outlines the high-level pseudocode for the Ultra Gesture Switch's core algorithm. It focuses on ultrasonic distance measurement, threshold-based gesture detection, and output control. The design emphasizes simplicity, noise filtering, and hysteresis to ensure reliability.

## Key Concepts
- **Ultrasonic Measurement**: Send a pulse and calculate distance from echo time.
- **Gesture Logic**: Proximity (&lt;20cm) = "Activate" (on state); Distance (>25cm) = "Deactivate" (off state). Hysteresis prevents rapid toggling.
- **Noise Handling**: Average multiple readings to filter variations (±2cm typical error).
- **Modularity**: Separate functions for readability (e.g., readDistance(), handleGesture()).
- **Assumptions**: Arduino loop runs at ~50-100ms intervals; speed of sound = 0.034 cm/μs (at room temp).

## Pseudocode Structure

### 1. Initialization (Setup Phase)
DEFINE constants:
trigPin = 9  // Output pin for ultrasonic trigger
echoPin = 10 // Input pin for echo
ledPins = [2, 3, 4, 5, 6]  // Array for 5 LEDs
THRESHOLD_ON = 20  // cm, for activation
THRESHOLD_OFF = 25 // cm, hysteresis for deactivation
NUM_READINGS = 3  // For averaging filter
INITIALIZE variables:
currentState = OFF  // Boolean: track activation state
previousDistance = 0  // For change detection
CONFIGURE pins:
Set trigPin as OUTPUT
Set echoPin as INPUT
For each pin in ledPins: Set as OUTPUT
Initialize Serial for debugging (baud 9600)

### 2. Main Loop (Continuous Detection)
WHILE true:

READ distance:

Call readDistance() function (detailed below)
Store in currentDistance



FILTER noise:

Take NUM_READINGS samples
Compute average: filteredDistance = sum(samples) / NUM_READINGS
If filteredDistance > 400 OR < 2: Set to error value (e.g., 0) and log warning



HANDLE gesture:

Call handleGesture(filteredDistance)
Update currentState based on logic



DEBUG (optional):

Print filteredDistance and currentState to Serial



DELAY 50ms  // For responsiveness without overload


### 3. Function: readDistance()
FUNCTION readDistance():
DigitalWrite(trigPin, LOW) for 2μs  // Clear trigger
DigitalWrite(trigPin, HIGH) for 10μs // Send pulse
DigitalWrite(trigPin, LOW)
duration = pulseIn(echoPin, HIGH, 30000)  // Timeout 30ms for max range
If duration == 0: Return error (no echo)
distance = (duration * 0.034) / 2  // Convert to cm
Return distance

### 4. Function: handleGesture(distance)
FUNCTION handleGesture(distance):

If currentState == OFF AND distance < THRESHOLD_ON:

Set currentState = ON
Activate outputs: turnOnLEDs() 
Print "Gesture: Activated" to Serial



Else If currentState == ON AND distance > THRESHOLD_OFF:

Set currentState = OFF
Deactivate outputs: turnOffLEDs() 
Print "Gesture: Deactivated" to Serial



Else: No change (hold state or noise)


Update previousDistance = distance


### 5. Helper Functions
- **turnOnLEDs()**: For i in 0 to 4: DigitalWrite(ledPins[i], HIGH)  // Progressive lighting (or all at once for v1)
- **turnOffLEDs()**: For i in 0 to 4: DigitalWrite(ledPins[i], LOW)

## Potential Improvements
- **Advanced Filtering**: Implement Kalman filter for smoother readings (future feature).
- **Multi-Gesture**: Detect velocity (e.g., if deltaDistance > 10cm in <500ms = "wave").
- **Error Handling**: Add checks for sensor failure (e.g., retry 3x).
- **Calibration**: Use a button to dynamically set THRESHOLD_ON based on environment.

## Testing Notes
- Simulate gestures: Hand at 10cm (expect ON), 30cm (expect OFF).
- Edge Cases: No target (distance >400cm), rapid movements.
- Expected Performance: >80% accuracy in 20 tests; response time <100ms.

This pseudocode serves as a blueprint for implementation in `src/ultra_gesture_switch.ino`. For circuit details, see [CIRCUIT.md](CIRCUIT.md).