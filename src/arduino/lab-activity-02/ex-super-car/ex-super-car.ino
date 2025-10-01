
#define N_LEDS 4
#define DELAY 100

int led_pins[N_LEDS] = { 3, 4, 5, 6};

int current = 0;
int step = 1;

void test();

void setup() {
  for (int i = 0; i < N_LEDS; i++){
    pinMode(led_pins[i],OUTPUT);
  }
  /* testing */
  // test();
}


void loop() {
  digitalWrite(led_pins[current],HIGH);
  delay(DELAY);
  digitalWrite(led_pins[current],LOW);

  current += step;

  if (current == N_LEDS){
    current = N_LEDS - 2; 
    step = -step;
  } else if (current < 0){
    current = 1;
    step = -step;
  }
}

void test(){
  for (int i = 0; i < N_LEDS; i++){
    digitalWrite(led_pins[i],HIGH);
  }
}

