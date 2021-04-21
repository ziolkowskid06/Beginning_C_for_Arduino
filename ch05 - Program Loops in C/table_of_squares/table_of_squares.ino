/*
  Table of Squares
  Print the table of squers for the first 10 numbers.
*/

#define MAXLOOP 10
void setup() {
  int squares[MAXLOOP];
  int counter;
  Serial.begin(9600);

  // Prepare the list
  for (counter = 0; counter < MAXLOOP; counter++) {
    squares[counter] = counter * counter;
  }

  // Display the list
  for (counter = 0; counter < MAXLOOP; counter ++) {
    Serial.println(squares[counter]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
