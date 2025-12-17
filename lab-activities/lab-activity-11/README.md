### Embedded Systems and IoT  - ISI LT - a.y. 2025/2026

## Lab Activity #11 - 20251210

v. 1.1.0-20251217

**Working with ESP in an IoT Perspective**

- Connecting an ESP to a WLAN through **Wi-Fi**
  - [About Wi-Fi](https://en.wikipedia.org/wiki/Wi-Fi) (802.11 standard)
  - Library: `Wifi` - part of the [`ardunino-esp32`](https://github.com/espressif/arduino-esp32/tree/master) libray  
  - Repo example: `esp32/esp-wifi-scan`

- Sending/Receiving data using **MQTT**
  - [About the MQTT protocol](https://mqtt.org/)
  - Available MQTT brokers
    - Online
       - e.g. [broker.mqtt-dashboard.com](http://broker.mqtt-dashboard.com/)
    - Open-source, to be installed
       - e.g. [Eclipse Mosquitto](https://mosquitto.org/)
    - As a server in our programming environment
       - e.g. [Moquette](https://moquette-io.github.io/moquette/)
       - example in the repo: `java/mqtt-backend`, based on Vert.x framework  
  - Library on ESP: [`PubSub`](https://github.com/knolleary/pubsubclient)
  - Repo example
    - ESP32 side: `esp32/esp-mqtt`
    - Java backend using MQTT: `java/mqtt-backend`
      - this is using the public broker `broker.mqtt-dashboard.com`

  






