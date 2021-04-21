/*
  Heads or Tails
  Turns on an LED which represents head or tail.
  The LED remains on for about 3 seconds and the cycle repeats.
*/

#define HEADPIN   11    // which I/O pins are you using?
#define TAILPIN   10

#define PAUSE     100   // how long to delay?

int headsCounter;       // heads/tails conter
int tailsCounter;

long loopCounter;
long randomNumber = 0L;  // 'L' tells compiler it's a long data type, not an int

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);
  headsCounter = 0;
  tailsCounter = 0;
  loopCounter = 0;

  pinMode(HEADPIN, OUTPUT);
  pinMode(TAILPIN, OUTPUT);
  randomSeed(analogRead(A0));     //this seeds the random number generator
}

void loop() {
  
  randomNumber = generateRandomNumber();    // turn both LED's off
  digitalWrite(HEADPIN, LOW);
  digitalWrite(TAILPIN, LOW);

  delay(PAUSE);                             // let them see both are off for a time slice

  if (randomNumber % 2 == 1) {              // treat odd numbers as a head
    digitalWrite(HEADPIN, HIGH);
    headsCounter++;
  }
  else{                                     // even numbers are a tails
    digitalWrite(TAILPIN, HIGH);
    tailsCounter++;
  }
  loopCounter++;

  if (loopCounter % 100 == 0) {             // see how things are every 100 flips
    Serial.print("After ");
    Serial.print(loopCounter);
    Serial.print(" coin flips, heads = ");
    Serial.print(headsCounter);
    Serial.print(" and tails = ");
    Serial.print(tailsCounter);
  }
  delay(PAUSE);
}

// generateRandomNumber() definition
long generateRandomNumber(){
  return random (0, 1000000);               // random number between 0 and 1 million
}


