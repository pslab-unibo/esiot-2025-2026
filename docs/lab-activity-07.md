### Embedded Systems and IoT  - ISI LT - a.y. 2025/2026

## Lab Activity #07 - 20251112

v. 1.0.0-20251111

**Synchronous FSM Architecture - First examples & explorations**

- Ref. theory: module-2.2 - Modelling Embedded Systems with FSMs

- blinkling sync
  - lab-activity-07/blinking_fsm_synch

- button led sync improvable 
  - lab-activity-07/button_led_fsm_synch_first

- button led sync good
  - lab-activity-07/button_led_fsm_synch_improved

**An IDE for complex projects**

- [PlatformIO IDE (+ Visual Studio Code)](https://platformio.org)
- Installation 
  - [instructions](https://platformio.org/install/ide?install=vscode)
  - [first install VS Code](https://code.visualstudio.com/)
- Install PlatformIO Extension
  - [setup](https://docs.platformio.org/en/latest//integration/ide/vscode.html#quick-start)


**Case study in Lab** 

- Consider a system with the following structure and behaviour
  - It has a servo motor, a led and a button
  - When started (initial conditions), the system is idle, the servo motor is at 0° degree, the led is on, waiting for the button to be pressed.
  - When the button is pressed, the servo must start sweeping forward and backward and the led blinking (with period 0.1 sec). In particular:
    - sweeping forward (from 0 to 180 degrees) should be done in 2 seconds
    - sweeping backward (from 180 to 0 degrees) should be done in 1 second
  - The button can be pressed again to stop the system, resetting the initial conditions. In particular:
    - if it is stopped while sweeping forward, sweeping is interrupted.
    - if it is stopped while sweeping backward, sweeping is not interrupted.
- Model the behaviour of the system with a FSM and implement it as a synchronous FSM, choosing the proper period.
  






