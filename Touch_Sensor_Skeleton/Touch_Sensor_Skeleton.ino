/*Replace all the ? in the code to read the value touchRead(GPIO pin) returned.*/

#include <Arduino.h>

#define TOUCHPIN 4                    // ***Replace the ? with the GPIO pin you selected as touch pin
#define LED 1                         // ***Replace the ? with the GPIO pin you selected to control LED
#define THRESHOLD 22672               // ***Observe the reading when the pin is touched. Then modify this threshold.***


int touch_reading;

void setup() {
  Serial.begin(9600);        // ***Start the serial communication set baud rate.***
  pinMode(LED, OUTPUT);       // Set pin connected to LED as an output pin
  
}

void loop() { 
  touch_reading = touchRead(TOUCHPIN); // Read the touch sensor
  Serial.println(touch_reading);       // print touch_reading to the Serial monitor
  // The LED can be turned on when the pin is touched.
  if (touch_reading > THRESHOLD)
    digitalWrite(LED, HIGH);   // turn on LED
  else
    digitalWrite(LED, LOW);    // turn off LED
    
  delay(100); // delay 0.1s
}
