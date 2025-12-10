### Embedded Systems and IoT  - ISI LT - a.y. 2025/2026

## Assignment #03 - *Smart Tank Monitoring System* 

v1.0.0-20251112
 
We want to realise an IoT system monitoring the rainwater level of a tank.  The system is composed of 4 subsystems: 

![layout](assignment-03-sketch.png)

### Description 

#### Components

The system is composed by four subsystems:

- **Tank Monitoring subsystem (TMS)** - based on ESP
  - embedded system to monitor the rainwater level in the tank
  - It interacts with the Control Room subsystem (CUS) via MQTT
- **Control Unit subsystem (CUS)**  - Back-end, running on a PC 
  - main subsystem, governing and coordinating  the whole system
  - It interacts via MQTT with the Tank Monitoring Subsystem (TMS)  
  - It interacts through the serial line with the Water Channels Subsystem (WCS)  
  - It interacts via HTTP with the Dashboard Subsystem (DBS) 
- **Water Channel Subsystem (WCS)** - based on Arduino
  - Embedded system controlling the water channel connecting the tank with the water channel network. 
  - It interacts via serial line with the Control Unit Subsystem (CUS).
  - It provides a panel for human operators to interact in place.
- **Dashboard subsystem (DBS)** - Frontend/web app, running on the PC or any device
  - Front-end for remote operators to visualise data and interact with the system.
  - it interacts via HTTP with the Control Unit Subsystem.

#### Hardware components 

- **TMS**
  - SoC ESP32 board (or ESP8266) including:
  - 1 sonar
  - 1 green led 
  - 1 red led
- **WCS**
  - Microcontroller Arduino UNO board including:
  - 1 servo motor
  - 1 potentiometer
  - 1 tactile button
  - 1 LCD display


#### Description of the behaviour

The system is meant to monitor the rainwater level inside the tank, and - depending on values - controlling the opening of a water channel connecting the tank to a network of water channers.   The overall system can be in two different modes: `AUTOMATIC` or `MANUAL`. In `AUTOMATIC` mode, the system automatically controls the opening of the water channel, depending on the current rainwater level in the tank. In `MANUAL` mode, the opening is controlled manually by an operator. The starting mode when booting is `AUTOMATIC`. 

*Details*

- The **TMS** is responsible for continuously monitoring the level of the rainwater level, by means of proper sensors (e.g. a sonar). 
  - The rainwater level are sampled at frequency F and sent to the **CUS** subsystem.
  - When the system is working correctly (network ok, sending data ok)  the green led is on and the red is off; otherwise – in the case of network problems – the red led should be on and the green led off.
- The **WCS** subsystem is responsible for controlling a valve (with a motor) opening/closing a water channel draining water from the tank to the water channel network.
  - The opening range is in percentage: from 0% = channel closed (motor position 0 degree), up to 100% = channel full open (motor position 90° degree).
  - The water channel opening level depends on the state of the system, established by the **CUS** subsystem (see later). 
  - The **WCS** includes a button to enable the `MANUAL` mode, in particular:
    - When the button is pressed, the system enters in `MANUAL` mode, so that the water channel opening level can be manually controlled by operators using a potentiometer. 
    - To exit from the `MANUAL` model, the button must be pressed again.  
  - The **WCS** subsystem is equipped also with an LCD display reporting: 
    - the current valve opening level of the water channel.
    - the current mode (`AUTOMATIC` or `MANUAL`), or `UNCONNECTED` (see later).
- The **CUS** subsystem is in charge of the policy governing the behaviour of the system. In particular:
  - Rainwater level monitoring
    - When the rainwater level exceeds the level L<sub>1</sub> (but below L<sub>2</sub>, with L<sub>1</sub> < L<sub>2</sub>) for more than T<sub>1</sub> time, the water channel is opened at 50% until the rainwater level is below L<sub>1</sub>.
    - If the the rainwater level exceeds the level L<sub>2</sub>, the water channel is immediately opened at 100%, until the value is below L<sub>2</sub>.

  If the **CUS** is not receiving data for more than T<sub>2</sub>  time units from the **TMS** (because of network problems), then the system enters into an `UNCONNECTED` state, which is restored to a normal state only if/when the network problems are solved.

- The **DBS** subsystem is a dashboard for visualising the state of the Tank Monitoring system, including:
  - A graph of the rainwater level, considering the last N measurements.
  - The current value of the valve opening percentage.
  - The state of the system:  `MANUAL`, `AUTOMATIC`, `UNCONNECTED` or `NOT AVAILABLE`. 
    - the state is labelled as `NOT AVAILABLE` when the **CUS** is not reachable, for any reason.
    
  Besides, it includes: 
  - a GUI button to switch the modality (`MANUAL`, `AUTOMATIC`).
  - a GUI widget to control the opening level of the valve in the **WCS** (when in `MANUAL` mode).


### The assignment

Design and develop a prototype of the Tank Monitoring system, considering as further  requirements:
- About the **TMS** subsystem:
  - it must run on an ESP32 (or an equivalent SoC board).
  - The control logic must be designed and implemented using finite state machines (synchronous or asynchronous) and (possibly, if useful) task-based architectures, exploiting the RTOS.
  - Must use MQTT to communicate with the **CUS** subsystem.
- About the **WCS** subsystem:
  - It must run on an Arduino (or an equivalent MCU board).
  - The control logic must be designed and implemented using finite state machines (synchronous or asynchronous) and  (possibly, if useful) task-based architectures.
  - It must communicate with the **CUS** subsystem via serial line.
- About the **CUS** subsystem: 
  - It must run on a PC, as a server/back-end.
  - No specific constraints about the programming/sw technology to be used.
  - It must use:
    - MQTT to communicate with the **TMS** subsystem.
    - HTTP to communicate  with the **DBS** subsystem. 
    - the serial line to interact with the **WCS**.
- About the **DBS** subsystem
  - It must run on a PC
  - No specific constraints about the programming/sw technology to be used.
  - It must use HTTP to interact with the **CUS** subsystem.

For any aspect not specified, you are free to choose the approach you consider more useful or valuable.

**The Deliverable**

The deliverable consists in a zipped folder assignment-03.zip including 4 subdirectories - one for each subsystem: `tms`,`cus`, `wcs`,`DBS`) - and a `doc` subdirectory, including the report. The report must be in PDF or MD (`report.pdf` or `report.md`) must include a high-level description of the behaviour of subsystems (using FSMs), a representation of the schema/breadboard and the link to a short video demonstrating the system.



