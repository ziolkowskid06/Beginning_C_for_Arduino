/**
  Leap Year Program
  Program: find out if the user typed in a leap year. 
           The code assumes the user is not an idiot and only types numbers
           that are a valid year.

  Author: Damian Ziolkowski, Apr. 22, 2021
**/

#define MAXCHARS 10

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {       // get the number of bytes (characters) available for reading from the serial port
    int bufferCount;
    int year;
    char myData[MAXCHARS + 1];        // save room for null

    bufferCount = ReadLine(myData);
    year = atoi(myData);              // convert string to int
    Serial.print("Year: ");
    Serial.print(year);
    Serial.print(" is ");
    if (IsLeapYear(year) == 0) {
      Serial.print("not ");
    }
    Serial.println("a leap year!");
  }
}


/*****  
  Purpose: Determine if a given year is a leap year  
  
  Parameters:  
    int yr              The year to test  

  Return value:  
    int                 1 if the year is a leap year, 0 otherwise  
*****/  

int IsLeapYear(int yr) {
  if (yr % 4 == 0 && yr % 100 != 0 || yr % 400 == 0) {
    return 1;    // a leap year
  }
  else {
    return 0;    // not a leap year
  }
}


/*****  
  Purpose: Read data from serial port until a newline character is read ('\n')  
  
  Parameters:  
    char str[]   character array that will be treated as a null-terminated string  
  
  Return value:  
    int          the number of characters read for the string  
  
  CAUTION:  This method will sit here forever if no input is read from the serial port 
            and no newline character is entered.  
  *****/  

int ReadLine(char str[]) {
  char c;
  int index = 0;

  while (true) {
    if (Serial.available() > 0) {                           // get the number of bytes (characters) available for reading from the serial port
      index = Serial.readBytesUntil('\n', str, MAXCHARS);   // reads characters from the serial buffer into an array.
      str[index] = '\0';                                    // null terminator character
      break;
    }
  }
  return index;
}