/** 
  Program: Illustrate pointer arithmetic

  Author: D.Ziolkowski, Apr 22, 2021
**/

#include <string.h>

void setup() {
  Serial.begin(9600);

  char buffer[50];
  char *ptr;
  int i;
  int length;

  strcpy(buffer, "When in the course of human events");           //  copies the quotation into  buffer
  ptr = buffer;
  length = strlen(buffer);            // how many chars in quote?
  Serial.print("The Lvalue for ptr is: ");
  Serial.print((unsigned int) &ptr);
  Serial.print(" and the Rvalue is ");
  Serial.println((unsigned int) ptr);
  
  while (*ptr) {
    Serial.print(*ptr++);
  }

  ptr = buffer;            // Reset the pointer back to buffer[0]...  
  Serial.println("");      // So the output prints on a new line  

  for (i = 0; i < length; i++) {  
    Serial.print(*(ptr + i));  
  }  
}

void loop() {
}