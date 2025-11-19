### Embedded Systems and IoT  - ISI LT - a.y. 2025/2026

## Lab Activity #05 - 20251029

v. 1.0.0-20251029
 
**Working with digital sensors**

- **HC-SR04 Ultrasonic sensor** module - [User guide](https://www.handsontec.com/dataspecs/HC-SR04-Ultrasonic.pdf)
  - example in Arduino `test_ultrasonic_sensor`- highlights  
    - `pulseIn` function

- **HCSR501 PIR** module - [Datasheet](https://components101.com/sensors/hc-sr501-pir-sensor)
  - example in Arduino `test_pir` - highlights  
    - calibration time 
  - [Tutorial](https://lastminuteengineers.com/pir-sensor-arduino-tutorial)

**Working with analog sensors**

- **LDR Photo Resistor** - [NORPS-12 Datasheet](https://components101.com/sites/default/files/component_datasheet/LDR%20Datasheet.pdf), [VT90N2 datasheet](https://www.arduino.cc/documents/datasheets/LDR-VT90N2.pdf) 
  - example in Arduino `test_ldr` - highlights
    - introducing a voltage divider – using a 10k Ohm resistor
    - [why do we need a voltage divider]( https://techexplorations.com/guides/arduino/common-circuits/voltage-divider-photoresistor/)

- **Temperature sensors** [**LM35** Datasheet](https://www.ti.com/lit/ds/symlink/lm35.pdf), [**TMP36** Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf)
  - Notes: both sensors have 10mv/C°, but different offsets
  - Exercise
    - given the characteristics of the sensor, buld a program that periodically read the value of the temperature and print its value in celsius degree (on the serial line or the display)
  - Improving the precision using AREF set to EXTERNAL (connected to 3.3V) or INTERNAL (set to 1.1V)

**Work in lab for Assignment #01**






