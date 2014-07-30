/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  for(int i=2;i<=7;i++){
  pinMode(i, OUTPUT);     
  }
}

void loop() {
  for(int i=2;i<=7;i++){
  digitalWrite(i, HIGH);   // set the LED on
          // wait for a second
  } 
  delay(1000);     
  for(int i=2;i<=7;i++){
  digitalWrite(i, LOW);    // set the LED off
 
  }
   delay(1000);              // wait for a second
}
