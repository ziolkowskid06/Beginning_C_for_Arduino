/**
  Program: Print the meesage about the temperature, humidity and time.

  Author: D.Ziolkowski, Apr 22, 2021
**/

void setup() {
  char message[] = "70.0,95,15:00";

  int index;
  int holdIndex = 0;
  int temperature;
  int humidity;

  Serial.begin(9600);

  index = FindCharacter(message, ',');
  if (index > 0) {                      // found a comma
    message[index] = '\0';              // make it a string
    temperature = atoi(message);
    holdIndex += index + 1;              // look past the null for next pass
  }

  index = FindCharacter(message + holdIndex, ',');
  if (index > 0) {
    message[index] = '\0';
    humidity = atoi(&message[holdIndex]);
    holdIndex += index + 1;
  }
  
  Serial.print("The temperature is = ");  
  Serial.print(temperature);  
  Serial.print(" with humidity = ");  
  Serial.print(humidity);  
  Serial.print(" at ");  
  Serial.print(&message[holdIndex]);  
}

void loop() {
}


/*****  
  This method looks for a specific character in a string  
  
  Parameter list:  
    char msg[]    an array of characters, null terminated  
    char c        the char to find  
  
  return value:  
    int           the position in the string where found or  
                  0 if no match  
*****/  
int FindCharacter(char msg[], char c) {  
  int i = 0;  
  while (msg) {  
    if (msg[i] == c) {  
      return i;  
    }
    else {  
      i++;  
    }  
  }  
  return 0;  
}  