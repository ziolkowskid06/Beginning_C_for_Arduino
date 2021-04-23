/**
  Purpose: To illustrate the relationship between two-dimensional arras and pointers.

  Author: D.Ziolkowski, Apr 22, 2021
**/

#define DAYSINWEEK 7  
#define CHARSINDAY 10  

void setup() {  
  Serial.begin(9600);  
}  

void loop() {  
  static char days[DAYSINWEEK][CHARSINDAY] =  
       {"Sunday", "Monday", "Tuesday","Wednesday",  
        "Thursday", "Friday", "Saturday"};  
  int i, j;                                  // Note the dual definitions in one statement  
  char *ptr, *base;                          // Some programmers hate these. Your choice.  
  base = days[0];                            // Different for N-rank arrays where N > 1  
  for (i = 0; i < DAYSINWEEK; i++) {  
    ptr = base + (i * CHARSINDAY);  
    Serial.print((int) ptr);          // Show the lvalue  
    Serial.print(" ");  
      for (j = 0; *ptr; j++) {  
        Serial.print(*ptr++);         // Show one char  
      }  
    Serial.println();  
  }  
  Serial.flush();             
  exit(0);  
}   
