/*
  Ask for Mark
  Program uses Serial object to ask the user to enter a letter betweeen A and F.
  It uses switch cases to print relevant message. 
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enter a letter a-f: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  char c;

  while (true){
    if (Serial.available() > 0) {
      c = Serial.read();
      c = toupper(c);                 // Make it upper case

      switch(c){
        case 'A':
          Serial.println("Great job!");
          break;
        case 'B':                     // Note fall-through here...
        case 'C':
          Serial.println("You passed!");
          break;
        case 'D':
          Serial.println("You are on the edge!");
          break;
        case 'F':
          Serial.println("See you again next semester :(");
          break;
        default:
          Serial.println("You can't even follow instructions?");
          break;
      }
    }
  }
}
