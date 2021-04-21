/***
  Random Number Match
  When the desired value is found blink the LED and send the message.
  Stop the program after 5 recycles.
***/

// define data set and target value
#define MAX 5000L
#define MIN 0L
#define TARGETVALUE 2500L

// define pins, recycles and delay
#define MAXRECYCLES 5
#define FOUNDPIN   10         // green LED
#define RECYCLEPIN  11        // red LED
#define PAUSE 1000

// variables
int foundIt = FOUNDPIN;
int recycle = RECYCLEPIN;
long randomNumber;
int recycleCounter = 0;
int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(foundIt, OUTPUT);
  pinMode(recycle, OUTPUT);
  randomSeed(analogRead(A0));       // this seed the random number generator
}

void loop() {
 while (counter != -1){                        // check for negative values
  randomNumber = generateRandomNumber();
  if (randomNumber == TARGETVALUE){
    Serial.print("Counter = ");
    Serial.print(counter, DEC);
    Serial.print(" recycleCounter = ");
    Serial.println(recycleCounter, DEC);
    ToggleLED(foundIt, PAUSE);
  }

  counter++;
  if (counter < 0) {                           // you have overflowed an int
    counter = 0;
    recycleCounter++;
    Serial.print("recycleCounter = ");
    Serial.println(recycleCounter, DEC);
    ToggleLED(recycle, PAUSE);
  }

  if (recycleCounter == MAXRECYCLES) {
    FakeAnEnd();                               // end program
  }
 }
}

// generateRandomNumber definition
long generateRandomNumber() {
  return random(MIN, MAX);             // generate random number between 0 and 5000
}

// FakeAnEne() definition
void FakeAnEnd() {                    // fake the end of the program
  while (true) {
    ;
  }
}

// ToggleLED() definition
void ToggleLED(int whichLED, int howLong) {
  digitalWrite(whichLED, HIGH);
  delay(howLong);
  digitalWrite(whichLED, LOW);
}