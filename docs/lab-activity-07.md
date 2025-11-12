### Embedded Systems and IoT  - ISI LT - a.y. 2025/2026

## Lab Activity #07 - 20251112

v. 1.0.0-20251111

**Synchronous FSM Architecture - First examples & explorations**

Examples about first implementations of synchronous FSMs.

- blinkling sync
  - `lab-activity-07/blinking_fsm_synch`

- button led sync improvable 
  - `lab-activity-07/button_led_fsm_synch_first`

- button led sync good
  - `lab-activity-07/button_led_fsm_synch_improved`

**An IDE for complex projects**

- [PlatformIO IDE (+ Visual Studio Code)](https://platformio.org)
- Installation 
  - [instructions](https://platformio.org/install/ide?install=vscode)
  - [first install VS Code](https://code.visualstudio.com/)
- Install PlatformIO Extension
  - [setup](https://docs.platformio.org/en/latest//integration/ide/vscode.html#quick-start)


**Case study in Lab** 

- Let's consider a simple system including a **servo motor (SM)**, a **led (L)** and a **button (B)**, with the following behaviour:
  - When started (initial conditions), the **SM** is at 0° degree, **L** is on.
  - When **B** is pressed, **SM** starts sweeping forward and backward, continuously, and **L** starts blinking (with period 0.1 sec). In particular:
    - sweeping forward (from 0° to 180° degrees) should be done in 2 seconds;
    - sweeping backward (from 180° to 0° degrees) should be done in 1 second.
  - **B** can be pressed again to stop sweeping, resetting the initial conditions. 
    - if it is stopped while sweeping forward, sweeping is immediately interrupted, while if it is stopped while sweeping backward, sweeping is not interrupted and the system stops when *SM* reaches 0°.
- The exercise:
  - Model the behaviour of the system with a FSM. 
  - Implement it as a synchronous FSM, choosing the proper period.
  






