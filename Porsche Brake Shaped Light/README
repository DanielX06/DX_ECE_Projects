# Porsche Brake Shaped Light
02/2026 - Current

A brake rotor and caliper inspired LED wall light that combines mechanical design, embedded systems, and PCB development. This project was heavily inspired by the “Glow Brake X” by 3D Druck Lagune on MakerWorld (https://makerworld.com/en/models/1782379-glow-brake-x#profileId-2048105). I extended the concept by designing the electronics from scratch so the light can be controlled over Wi-Fi (IP based control) and activated locally using a hand wave via a proximity sensor. The result is a complete end to end build that includes mechanical CAD, a custom PCB, soldering, firmware, and system bring up.

Goal:
The main goal is to get hands on practice with the full workflow. PCB design, CAD, 3D printing, soldering tiny parts, and writing ESP32 firmware that actually interacts with real hardware.

System Overview:
- Power comes in at 12 V and gets stepped down to 3.3 V on the PCB for the ESP32 and sensor
- The ESP32 handles the Wi-Fi control side and the main logic
- A proximity sensor is used for gesture style input like turning it on or switching modes
- The COBB LED is driven by a mosfet to the PCB so I can do different lighting behaviors (brightness, etc.)
- The rotor and caliper are custom modeled so everything mounts cleanly and the wiring stays hidden

Key Tasks:
- Design a custom PCB integrating an ESP32, proximity sensor, 12 V to 3.3 V buck converter, and COB LED power switching and support circuitry
- Model a brake rotor and caliper housing to mount the COB LED and PCB
- 3D print the rotor and caliper components
-	Assemble, solder, and bring up the full system, then validate power and control functionality



Learning Outcomes (So far):
- I got way more comfortable going from schematic to PCB layout, especially around power delivery, grounding, and designing something that’s realistic to solder
- I learned a lot about integrating sensors and power electronics with an ESP32 without making the system noisy or unstable






Some datasheet links:


  Step Down Converter IC:  https://datasheet.octopart.com/AP63203WU-7-Diodes-Inc.-datasheet-130008827.pdf?src-supplier=IHS

  Proximity Sensor:        https://datasheet.octopart.com/VCNL4040M3OE-Vishay-datasheet-175914715.pdf?src-supplier=IHS

  ESP32:                   https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/esp32-devkitc/index.html
                           https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/_images/esp32_devkitC_v4_pinlayout.png
                           https://dl.espressif.com/dl/schematics/esp32_devkitc_v4_dimensions.pdf
