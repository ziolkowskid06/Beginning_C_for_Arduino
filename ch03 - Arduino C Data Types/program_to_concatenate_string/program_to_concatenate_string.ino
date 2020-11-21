/*
A program to concatenate Strings.
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  String firstName = "Jack ";
  String lastName = "Purdum ";
  String fullName = firstName + lastName;
  Serial.println(fullName);
}

void loop() {}
