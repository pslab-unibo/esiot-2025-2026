#define BUTTON_PIN 6

volatile int count;

void setup()
{
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), inc, RISING); 
  count = 0;
}

void loop()
{
  noInterrupts();
  int current = count;
  interrupts();
  Serial.println(current);
  // delay(1000);
}

/* interrupt handler */

void inc()
{
  count++;
}
