# Porsche Brake Shaped Light
02/2026 - Current

A brake rotor and caliper inspired LED wall light that combines mechanical design, embedded systems, and PCB development. This project was heavily inspired by the “Glow Brake X” by 3D Druck Lagune on MakerWorld (https://makerworld.com/en/models/1782379-glow-brake-x#profileId-2048105). I extended the concept by designing the electronics from scratch so the light can be controlled over Wi-Fi (IP based control) and activated locally using a hand wave via a proximity sensor. The result is a complete end to end build that includes mechanical CAD, a custom PCB, soldering, firmware, and system bring up.

## Goal:
The main goal is to get hands on practice with the full workflow. PCB design, CAD, 3D printing, soldering tiny parts, and writing ESP32 firmware that actually interacts with real hardware.

## System Overview:
The system is composed of four tightly integrated subsystems:

**Power System**  <br>
12 V input stepped down to 3.3 V using an on-board buck converter to supply the ESP32 and sensor

**Control System**  <br>
ESP32 handles Wi-Fi communication, device logic, and LED control

**Sensing System**  <br>
Proximity sensor enables gesture-based interaction such as turning the light on or off

**Lighting System** <br>
COB LED driven through a MOSFET for brightness control and dynamic lighting behavior

Mechanical components were designed to house all electronics cleanly while maintaining a realistic brake rotor aesthetic.


## Key Tasks:
- Design a custom PCB integrating an ESP32, proximity sensor, 12 V to 3.3 V buck converter, and COB LED power switching and support circuitry
- Model a brake rotor and caliper housing to mount the COB LED and PCB
- 3D print the rotor and caliper components
-	Assemble, solder, and bring up the full system, then validate power and control functionality



## Lessons Learned (So far):
- I got way more comfortable going from schematic to PCB layout, especially around power delivery, grounding, and designing something that’s realistic to solder
- I learned a lot about integrating sensors and power electronics with an ESP32 without making the system noisy or unstable
- Learned how capacitor selection (ESR, value) affects stability and ripple
- Created some more advanced designs such as the brake caliper in SolidWorks CAD
- I am getting more comfortable soldering 0805, 0603, and 0402 smd components



## Comments: 
- Wow! I did not expect the smd componenet to be so small, so I got some smd practice kits online to practice before soldering the final product






Some datasheet links:


| Item | Link |
| --- | --- |
| Step Down Converter IC | [AP63203WU-7 datasheet](https://datasheet.octopart.com/AP63203WU-7-Diodes-Inc.-datasheet-130008827.pdf?src=supplier=IHS) |
| Proximity Sensor | [VCNL4040 datasheet](https://datasheet.octopart.com/VCNL4040M3OE-Vishay-datasheet-175914715.pdf?src=supplier=IHS) |
| ESP32 DevKitC docs | [Espressif docs](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/esp32-devkitc/index.html) |
| ESP32 DevKitC dimensions | [Dimensions PDF](https://dl.espressif.com/dl/schematics/esp32_devkitc_v4_dimensions.pdf) |
