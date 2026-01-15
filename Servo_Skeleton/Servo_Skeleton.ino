// replace ?
// Connect the orange wire of the servo to the PWM pin, the red wire to 5V, and the brown wire to GND 

#include <ESP32Servo.h>

Servo servo; // Create servo object
String command; // using string to store the message receive from serial monitor
// Define the pins where the servo are connected
const int PWMpin = 2;

void setup() {
servo.attach(PWMpin); // Servo object servo should be attached to a ESP32 PWM pin
Serial.begin(9600); // Initialize the Serial Monitor and set baudrate
}
    /*in continuous rotation servo servo.write(value) value of 0~180 dictates speed and direction.
      Stop: Send a value near 90 (e.g., servo.write(90);).
      Clockwise (CW): Values below 90 (e.g., servo.write(0); for full speed).
      Counter-Clockwise (CCW): Values above 90 (e.g., servo.write(180); for full speed).
    */
    // set servo speed and direction by sending 0~180 to serial monitor
void loop() {
  //Check if message from serial monitor is available to read
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n'); // Read command until newline
    int sd = command.toInt(); // Get the speed and direction as an integer and store in sd 
    if ( sd < 0 || sd > 180) {
    Serial.println("Error: sd must be between 0 and 180.");
  } else{
    // print the sd in serial monitor
    Serial.println(sd); 
   
    // set servo speed and direction
    servo.write(sd);
  }
}
delay(100); 
}
