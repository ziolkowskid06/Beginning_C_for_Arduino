/**
  Purpose: Display a character array using array indexes

  Author: D.Ziolkowski, Apr 22, 2021
**/

void setup() {
  char greet[6];
  char *ptr;
  int i;
  
  Serial.begin(9600);

  greet[0] = 'H';     // initialize the array with some characters
  greet[1] = 'e';
  greet[2] = 'l';
  greet[3] = 'l';
  greet[4] = 'o';
  greet[5] = '\o';    // null termination character

  Serial.print("Using 'Serial.print(greet[i]);'   ");  
    for (i = 0; i < 5; i++) {  
       Serial.print(greet[i]);                             //  Flavor #1  
    }  
  Serial.println();  

  Serial.print("Using 'Serial.print(*(greet + i));'   ");  
    for (i = 0; i < 5; i++) {  
      Serial.print(*(greet + i));                          //  Flavor #2  
    }  
  Serial.println();  

  Serial.print("Using 'Serial.print(*ptr++);'   ");  
    ptr = greet;                                           // initialize the pointer
    for (i = 0; i < 5; i++) {  
      Serial.print(*ptr++);                                //  Flavor #3  
    }  
}

void loop() {
}