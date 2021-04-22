/**
  Statement Block Scope Program
  Program: Demonstrate the concept of statement block scope

  Author: D.Ziolkowski, Apr. 22, 2021
**/

#define MAXVAL 1000

int k = 0;

void setup() {
  int x = 5;
  Serial.begin(9600);

  if (x < MAXVAL) {
    int temp;
    temp = x * 100;
    Serial.print("The Lvalue for temp is: ");
    Serial.println((long) &temp);
    Serial.print("The Rvalue for temp is: ");
    Serial.println((long) temp);
  }

  int temp;
  Serial.print("The Lvalue for 2nd temp is: ");
  Serial.println((long) &temp);
  Serial.print("The Rvalue for 2nd temp is: ");
  Serial.println((long) temp);
}

void loop() {
}
