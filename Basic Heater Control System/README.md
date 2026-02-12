* Smart Heater Control System (Simulation Project) *

Built with: Arduino Uno · DHT22 · C++ · Wokwi Simulator
Role: Embedded Systems Developer (solo project)
Goal: Simulate a safe, state-driven heater control system with real-time feedback and fail-safes.
_________________________________________________________________________________________________________________________________________________
* Project Highlights *

Real-Time Temperature Monitoring:
Continuously reads temperature & humidity from a DHT22 sensor.

State Machine Control Logic:
Implements 5 well-defined states:
IDLE → HEATING → STABILIZING → TARGET REACHED → OVERHEAT

Actuator Control:

LED = Heater ON/OFF indicator

Buzzer = Overheat alert (triggered at 50 °C)

Serial Logging:
Logs temp, humidity, and current state every 2 seconds.

Tested in Simulation:
Fully simulated in Wokwi (Wokwi.com), adjustable temperature slider to test all states.
___________________________________________________________________________________________________________________________________________________________________________
* What I Demonstrated *

Designing and coding embedded control logic from scratch

Working with sensor data, thresholds, and hysteresis

Implementing safety-oriented feedback (visual + audible)

Writing clean, testable Arduino code with state transitions

Documenting system design clearly for hardware scalability
__________________________________________________________________________________________________________________________________________________________________________________
* System Behavior Summary *
Temperature	State	Heater (LED)	Buzzer
< 39 °C	HEATING	ON	OFF
39–40 °C	STABILIZING	ON	OFF
40–49.9 °C	TARGET REACHED	OFF	OFF
≥ 50 °C	OVERHEAT	OFF	ON
⚙️ Tools & Stack

Board: Arduino Uno (ATmega328P)

Sensor: DHT22 (Digital Temp + Humidity)

Actuators: LED (GPIO 4), Buzzer (GPIO 5)

Language: Arduino C++

Simulation: Wokwi Online Simulator

Libraries: Adafruit DHT sensor library
______________________________________________________________________________________________________________________________________________________________________________
* Try It Yourself *

 Click to Open Wokwi Simulation: https://wokwi.com/projects/439422033010160641

Press Run

Click on the DHT22 sensor

Use the slider to change temperature and observe:

LED turns ON when heating

Buzzer triggers at overheat

Serial Monitor logs real-time system state






