/**
  Program: Calls a function to acquire a single-digit number from the user in order to manipulate two LEDs.
           0 = no LEDs lit  
           1 = LED1 lit  
           2 = LED2 lit  
           3 = both LED1 and LED2 lit      

  Author: D.Ziolkowski, Apr 22, 2021
**/

#define LED1 11             // Which I/O pins are we using  
#define LED2 10  

void setup() {
  Serial.begin(9600);       // Serial object set with "No Line Ending"  
  pinMode(LED1, OUTPUT);  
  pinMode(LED2, OUTPUT);  
}

void loop() {
  int goodBadFlag;                      // Was the input good or bad?  
  int LEDValue;  
  Serial.println();  
  goodBadFlag = GetInput(&LEDValue);  
  Serial.print("flag = ");  
  Serial.print(goodBadFlag);  
  Serial.print("   LEDValue = ");  
  Serial.print(LEDValue);  
  LightLEDs(LEDValue);  
}


/*****  
  Purpose: This function is used to get a numeric value from the user via the Serial monitor. 
           Valid input are the values 0 - 3.  
  
  Argument list:  
    int     *which            the value entered by the user  
    
  Return value:  
    int     0                 if the value is bad, 1 if good  
 *****/  

int GetInput(int *which) {    
  char c;  
  int temp = -1;  
  *which = temp;  
  while (true) {  
    if (Serial.available() > 0) {  
      c = Serial.read();  
      if (isdigit(c)) {                 // If they entered a digit character  
        temp = c - '0';                 // Subtract ASCII zero from the digit character  
        if (temp >= 0 && temp < 4) {    // Is the value within range?  
          *which = temp;  
          return 1;                     // Yep, it's good  
        }  
      }  
    return 0;                           // If we get here, it's bad input  
    }  
  }  
}  


/*****  
  Purpose: This function is used to illuminate the correct combinations of LED  
           according to the value of which  
  
  Argument list:  
    int   combo         key for lighting LEDs: 0=none, 1=LED1, 2=LED2, 3=both  
  
  Return value:  
    void  
*****/ 

void LightLEDs(int combo) {
  switch(combo) {  
    case 0:                       // both off  
      digitalWrite(LED1, LOW);  
      digitalWrite(LED2, LOW);  
      break;  
    case 1:                       // 1 on, 2 off  
      digitalWrite(LED1, HIGH);  
      digitalWrite(LED2, LOW);  
      break;  
    case 2:                       // 1 off, 2 on  
      digitalWrite(LED1, LOW);  
      digitalWrite(LED2, HIGH);  
      break;  
    case 3:                       // both on  
      digitalWrite(LED1, HIGH);  
      digitalWrite(LED2, HIGH);  
      break;  
    default:  
      Serial.println("Control should never get here");  
      break;  
  }  
}  