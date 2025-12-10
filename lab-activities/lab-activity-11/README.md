### Embedded Systems and IoT  - ISI LT - a.y. 2025/2026

## Lab Activity #11 - 20251210

v. 1.0.0-20251209

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

- Sending/Receiving data using **HTTP**
  - [About the HTTP protocol](https://en.wikipedia.org/wiki/HTTP)
  - Library: `HTTPClient`] - part of the [`arduino-esp32`](https://github.com/espressif/arduino-esp32/tree/master) libray 
  - Repo examples
    - simple `GET`: `esp32/esp-http-get`
    - full client/server REST-based example
      - ESP32 side: `esp32/esp-http-get-json-basic`, `esp32/esp-http-post-json-basic`
      - Java server: `java/http-backend`
  - Using tunnelling tools
    - if both client and service are connected to the same LAN, with no firewalls or port blocked, no problem
    - if instead the server/service has not a public IP (e.g. being connected to a hotspot – smartphone + Tethering), then we need to use a [tool for tunnelling](https://alternativeto.net/software/ngrok/). 
    - A main example is [ngrok](http://ngrok.com). By spawning the tool, one gets a public IP, to be used in client programs.  One can specify which web protocol to assume (http or https) - default is https, to force http the option `–scheme http` must be used 
    - Example: setting up a public IP address reachable through http, forwarding to a local http server on port 8080: 

        `ngrok http 8080 --scheme http,https`
        
        where `8080` is the local port where we want to forward the stream

    - An example of dynamically assigned IP: http://c037-137-204-20-125.ngrok-free.app 

         


    

  






