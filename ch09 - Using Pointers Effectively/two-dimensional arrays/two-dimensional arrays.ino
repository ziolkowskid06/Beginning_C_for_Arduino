/**
  Purpose: To illustrate the relationship between two-dimensional arras and pointers.

  Author: D.Ziolkowski, Apr 22, 2021
**/

#define DAYSINWEEK 7  
#define CHARSINDAY 10  

static char days[DAYSINWEEK][CHARSINDAY] =  
       {"Sunday", "Monday", "Tuesday","Wednesday",  
        "Thursday", "Friday", "Saturday"};  
void setup() {  
  int i, j;  
  Serial.begin(9600);                   // Serial link to PC  
  for (i = 0; i < DAYSINWEEK; i++) {  
    Serial.print((int) &days[i][0]);    // Show the lvalue  
    Serial.print(" ");  
      for (j = 0; days[i][j]; j++) {  
        Serial.print(days[i][j]);       // Show each char  
      }  
    Serial.println();  
  }  
}  

void loop() {
}   