### Embedded Systems and IoT  - ISI LT - a.y. 2025/2026

## Lab Activity #06 - 20251105

v. 1.0.0-20251104
 
**OOP in Arduino**

- slides: `[Lab Notes] OOP for Arduino - From Java to C++`
- examples in: `esiot-2025-2026/src/arduino/lab-activity-06/oop` folder

**Working with actuators: servo motors** 

- Key aspect
  - precise control of shaft position, between 0 and 180 degree
- Can be analog or digital
  - Analog one (in the kit): 3 terminals – 2 for power and one for control 
  - Example in the kit: [microservo Hitech HS-53](https://www.servocity.com/hitec-hs-53-servo)
- Control through PWM
  - periodic digital signal with pulses between 1 ms and 2 ms, ~50 Hz frequency (~20 ms period)  
  - duty cycle => angle
     - common behaviour:  ~1ms pulse => servo at one extreme (0 degree, counterclockwise), 1.5ms pulse => 90 degree and 2ms pulse => 180 degree, clockwise
     - different servos => different behaviours – check with the datasheets and empirical tests,
- Physical properties
  - Power
    - voltage level: between 4,5V and 6V 
       - better to use an external powerline, feasible to use the Arduino one
    - "impulse current" => the current needed depends on the load 
       - about ~5-10mA with no load or small load
       - can raise up to ~1A for heavy loads or external forces that try to move the shaft
    - "stall current":  current needed to keep the current position - proportional to the effort/force exerted to keep the position 
  - Drive torque  
    = capability of the servo to move the shaft in spite of the resistance of the load/apparatus which is mechanically bound to it 
    - Computed as radius * force - in Newton * meter (Nm) or Kg meter (Kgm), where 1 Kgm = 9.81 Nm - from 2° principle of dynamics
    - available value depends on the voltage level of the battery 
       - the greater the voltage level is, the greater is the drive torque 
    - when receiving a command to rotate of some angle X, the shaft will actually rotate only if drive torque is capable to overcome the resistance due to the load
  - Rotation speed (or, duration of transition time for reaching the position)
    - duration of rotation = time to reach the position.
    - check datasheets and manuals
      - info typically given considering no load: e.g. - 0,2 sec / 60°
      - with a resistance load => higher

**Servo motor programming**

- [Servo library](https://www.arduino.cc/en/Reference/Servo)
  - API: attach, write, detach
  - Value used for pulses:
    - default: 0,544ms for 0° and 2,400ms for 180°
    - values can be changed (attach parameters)
  - **WARNING** 
    - Servo library uses Timer1 – used also for PWM on pin 9 and 10, so when using this library: 
      - you can't use analogWrite (based on PWM) on pin 9 e 10 
        - either or not attaching a servo on that pin
      - **you can't use Timer1** or other libraries using Timer1 (e.g. **SoftwareSerial**). If you need to use in your project Timer1, you can use other libraries for managing servo not using Timer1, e.g. [**ServoTimer2**]( https://github.com/nabontra/ServoTimer2) **using Timer2**
    - [More about conflicts between Timers and Libs](https://docs.google.com/document/d/15Z2uNTHLBnMWNpC-O-iAICRRTTMQIkW-Xl7RJoGCK0k/edit?usp=sharing)  

  
**Arduino/PC Communication via Serial Port**

- slides: `[Lab Notes] Arduino/PC Serial Communication`
- Material on the repo
  - Java side: `serial/java`
  - Arduino side: `serial/arduino`

- Examples
  - Showing the serial ports
    - Java side (from `serial/java`):

		`java -cp bin:lib/jssc-2.9.4.jar esiot.serial.ShowSerialPorts`

    **NOTE**: the classpath separator (in `bin:lib/jssc-2.9.4.jar`) is `:` in Linux/Mac, `;` in Windows

  - Simple serial monitor
    - Arduino side: running any program sending messages on the serial port
    - Java side:

		`java -cp bin:lib/jssc-2.9.4.jar esiot.serial.SimpleSerialMonitor <serial port>`

		e.g.:
 
		`java -cp bin:lib/jssc-2.9.4.jar esiot.serial.SimpleSerialMonitor COM3`

		`java -cp bin:lib/jssc-2.9.4.jar esiot.serial.SimpleSerialMonitor /dev/tty.usbmodem1412101`
                                                                             

  - Remote Blinking
    - Arduino side: running `serial/arduino/remote_blinking/remote_led_withmsg.ino`)

    - Java side:

      `java -cp bin:lib/jssc-2.9.4.jar esiot.serial.TestRemoteBlinking <serial port>`


  - Test Ping Pong
    - Arduino side: running `serial/arduino/remote_blinking/remote_pingpong.ino`)

    - Java side (being in `serial/java`):
      
      `java -cp bin:lib/jssc-2.9.4.jar esiot.serial.TestPingPong  <serial port>`





