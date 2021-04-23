/**
  Program: Blink by Fitzgerald

  Modified by: D.Ziolkowski, Apr 22, 2021
**/

#define LED 13
#define PAUSE 500

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  static int state = HIGH;      // state of LED, (this line is evaluated once only)
  BlinkLED(LED, &state);        // call function
}


/*****
  Purpose: To blink the onboard LED using a pointer

  Parameter list:
    int pin             the pin attached to the LED
    int *whichState     a pointer to the state variable back in loop() 

  Return Value:
    n/a
*****/

void BlinkLED(int pin, int *whichState) {
  digitalWrite(pin, *whichState);           // turn the LED on, (sending Lvalue of state)
  delay(PAUSE);                             // wait for a PAUSE time
  *whichState = !(*whichState);             // change the state (NOT HIGH means LOW)
}