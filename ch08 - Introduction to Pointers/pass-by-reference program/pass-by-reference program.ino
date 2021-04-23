#include <stdio.h>

void setup() {
  Serial.begin(9600);
  int number = 10;

  Serial.print("Lvalue for number is ");
  Serial.print((int) &number);                          // memory address
  Serial.print(" Rvalue for number is ");
  Serial.println(number);  
  SquareIt(&number);  
  Serial.print("After call: Rvalue for number is ");  
  Serial.println(number);  
}

void loop() {
}


void SquareIt(int *temp) {  
  Serial.print("In SquareIt(), Lvalue for temp is ");  
  Serial.print((int) &temp);                            // memory address
  Serial.print("  Rvalue for temp is ");  
  Serial.println((int) temp);  
  *temp = *temp * *temp;  
  Serial.print("The new Rvalue for temp is ");  
  Serial.println(*temp);  
}   