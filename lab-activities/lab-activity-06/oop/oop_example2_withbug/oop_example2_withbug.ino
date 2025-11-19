#include "counter.h"


void setup(){
  Serial.begin(9600); 
}

void loop(){
  int x = 0;
  
  Counter* c = new Counter(20);
  Serial.print("stack at: ");
  Serial.print((int)(&x),HEX);
  Serial.print(" heap at: ");
  Serial.println((int)c, HEX);
  // delete c2;
  delay(100);
}
