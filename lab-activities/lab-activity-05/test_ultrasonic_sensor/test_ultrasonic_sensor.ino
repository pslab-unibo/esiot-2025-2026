#define SONAR_TRIG_PIN 7
#define SONAR_ECHO_PIN 8
#define NO_OBJECTS -1

/* Supposing to run this test 
   in an environment with 20 °C 
  ì https://en.wikipedia.org/wiki/Speed_of_sound
   */
const float temperature = 20;
const float vs = 331.45 + 0.62*temperature;

void setup()
{
  Serial.begin(115200);
  pinMode(SONAR_TRIG_PIN, OUTPUT);
  pinMode(SONAR_ECHO_PIN, INPUT);  
}

float getDistance()
{
    /* Triggering stage: sending the impulse */

    digitalWrite(SONAR_TRIG_PIN,LOW);
    delayMicroseconds(3);
    digitalWrite(SONAR_TRIG_PIN,HIGH);
    delayMicroseconds(5);
    digitalWrite(SONAR_TRIG_PIN,LOW);
    
    /* Receiving the echo */

    float tUS = pulseIn(SONAR_ECHO_PIN, HIGH);
    if (tUS > 0){
      float t = tUS / 1000.0 / 1000.0 / 2;
      float d = t*vs;
      return d;
    } else {
      return NO_OBJECTS;
    }
}

void loop()
{
  float d = getDistance();
  if (d >= 0) {
    Serial.println(String(d) + " ");
  }
  delay(50); 
}
