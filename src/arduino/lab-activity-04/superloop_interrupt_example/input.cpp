#include "input.h"
#include "Arduino.h"
#include "config.h"

#include <EnableInterrupt.h>

#define BOUNCING_TIME 50

// #define __DEBUG__

uint8_t inputPins[NUM_BUTTONS] = {BUT01_PIN, BUT02_PIN};
bool buttonPressed[NUM_BUTTONS] = {false, false};

/* used for debouncing */
long lastButtonPressedTimestamps[NUM_BUTTONS];

void buttonHandler(int i);
void buttonHandler0(){ buttonHandler(0); }
void buttonHandler1(){ buttonHandler(1); }

void (*buttonHandlers[NUM_BUTTONS])() = { buttonHandler0, buttonHandler1 };

void buttonHandler(int i){
  long ts = millis();
  if (ts - lastButtonPressedTimestamps[i] > BOUNCING_TIME){
    lastButtonPressedTimestamps[i] = ts;
    int status = digitalRead(inputPins[i]);
    if (status == HIGH && !buttonPressed[i]) { 
        buttonPressed[i] = true;
    }
  }
}

void initInput(){
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(inputPins[i], INPUT);  
    enableInterrupt(inputPins[i], buttonHandlers[i], CHANGE);       
  }
}

void resetInput(){
  long ts = millis();
  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttonPressed[i] = false;      
    lastButtonPressedTimestamps[i] = ts;    
  }
}
bool isButtonPressed(int buttonIndex){
  return buttonPressed[buttonIndex];
}

bool hasBeenPressed(int index){
  return buttonPressed[index]; 
}




