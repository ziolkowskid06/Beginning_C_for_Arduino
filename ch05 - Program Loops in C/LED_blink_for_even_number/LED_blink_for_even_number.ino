/*
  LED Blink for Even Number
  Create the counter to blink the LED for even number.
*/

#define LED 13
#define PAUSE 1000
#define COUNTERNB 10 

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int counter;

  for (counter = 0; counter < COUNTERNB; counter++) {
    if (counter % 2 == 0) {
      digitalWrite(LED, HIGH);
    }
    else {
      digitalWrite(LED, LOW);
    }
    delay(PAUSE);
  }
}
