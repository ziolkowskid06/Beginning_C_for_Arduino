void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  char myName[12] = "Jack ";
  char lastName[] = "Purdum";
  strcat(myName, lastName);     // A standard library function to concatenate
                                // character arrays 
  Serial.println(myName);
}

void loop() {}
