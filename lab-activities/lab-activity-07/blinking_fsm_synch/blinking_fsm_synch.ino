#include "Led.h"
#include "Timer.h"

#define LED_PIN 13
#define TIME_IN_OFF_STATE 200 
#define TIME_IN_ON_STATE 1000 
#define FSM_PERIOD 200

Light* led;
Timer timer;

enum { ON, OFF} state;
int count;

void setup(){
  Serial.begin(9600);
  led = new Led(LED_PIN); 
  state = OFF;
  count = 0;
  timer.setupPeriod(FSM_PERIOD);
}

void step(){

  switch (state){
    case OFF:
      count++;
      /* if 200ms elapsed, then move to ON state */
      if (count == TIME_IN_OFF_STATE/FSM_PERIOD){
        led->switchOn();
        Serial.println("ON");
        count = 0;
        state = ON;
      }
      break;
    case ON:
      count++;
      /* if 1000ms elapsed, then move to OFF state */
      if (count == TIME_IN_ON_STATE/FSM_PERIOD){
        led->switchOff();
        Serial.println("OFF");
        count = 0;
        state = OFF;
      }
      break;
  }
}

void loop(){
  timer.waitForNextTick();
  step();
};
