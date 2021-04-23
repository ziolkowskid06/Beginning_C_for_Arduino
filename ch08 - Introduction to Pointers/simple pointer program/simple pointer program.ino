/**
  Program: Simple program to demonstrate using a pointer

  Author: D.Ziolkowski, Apr 22, 2021
**/

#include <stdio.h>

int counter = 0;

void setup() {
  int k;
  int number = 5;
  int *ptrNumber = NULL;

  Serial.begin(9600);
  Serial.print("The lvalue for ptrNumber is: ");  
  Serial.print((long) &ptrNumber, DEC);  
  Serial.print(" and the rvalue is ");  
  Serial.println((long) ptrNumber, DEC);  

  ptrNumber = &number;  
  *ptrNumber = 10;  
  k = *ptrNumber;

  Serial.print("The lvalue for number is: ");  
  Serial.print((long) &number, DEC);  
  Serial.print(" and has an rvalue of ");  
  Serial.println((int) number, DEC);

  Serial.print("The lvalue for k: ");  
  Serial.print((long) &k, DEC);  
  Serial.print(" and has an rvalue of ");  
  Serial.println(k, DEC);

}

void loop() {
  // put your main code here, to run repeatedly:
}
