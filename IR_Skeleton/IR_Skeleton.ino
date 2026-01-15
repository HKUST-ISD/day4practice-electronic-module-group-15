/*Replace ? in the code*/

#include <Arduino.h>

/*
    Reading the output of IR Sensor 
    TODOs:
        1. Print a message to the Serial Monitor to show whether the IR Sensor is detecting an obstacle or not
        2. Turn ON the LED when the IR Sensor detects an obstacle
*/


// Define the GPIO pin to which the IR Sensor is connected
// Using "#define", we can define a constant value that can be used throughout the code 
#define SENSOR_DO_PIN 37 // ESP32 pin connected to DO pin of IR sensor
#define SENSOR_AO_PIN 38 // ESP32 pin connected to AO pin of IR sensor
#define LED 1 // ESP32 pin connected to LED

void setup() {
  
  
    Serial.begin(9600);   // Initialize the Serial Monitor and set baud rate

    /*
        Here, since we are reading IR sensor state 
        We will set the GPIO pin to which the IR Sensor is connected as INPUT of ESP32
        This will allow us to read the state of DO pin of IR sensor using the "digitalRead()" function 
        and read the value of AO pin of IR sensor using the "analogRead()" function 
    */
    pinMode(SENSOR_DO_PIN, INPUT);
    pinMode(SENSOR_AO_PIN, INPUT);
    // set LED pin mode 
    pinMode(LED, OUTPUT);
}

void loop() {
    /*
        Read the state of the IR Sensor
        The "digitalRead()" function is used to read the state of the IR Sensor

        The "digitalRead()" function will return the state of the DO pin, either HIGH or LOW, or 1 or 0
        HIGH or 1 means the pin is at HIGH voltage (3.3V)
        LOW or 0 means the pin is at LOW voltage (0V)

        The "analogRead()" function will return the reading of AO pin, limited to the resolution of the analog to digital converter of ESP32 S3, which is 0-4095 for 12 bits
        We use a variable "state" to store the state of the IR Sensor DO output and value of AO output
    */
    int state = digitalRead(SENSOR_DO_PIN); 
    int value= analogRead(SENSOR_AO_PIN);
    // We will use if-else statement to check the state of the IR Sensor and turn on LED when the IR Sensor detects an obstacle
    // Print a message to the Serial Monitor to show whether the IR Sensor is detecting an obstacle or not
    //Turn ON the LED when the IR Sensor detects an obstacle

    if (state == LOW){
        // If the IR Sensor is detecting an obstacle
        Serial.println("Detected");
        digitalWrite(LED,HIGH);
    }
    else{
        //If the IR Sensor is NOT detecting an obstacle
        Serial.println("Not detected");
        digitalWrite(LED,LOW);

    } 
    //print the reading of AO output
    Serial.print("AO reading:");
    Serial.println(value);
    delay(100); // Delay 0.1s to avoid reading the state too fast

    /* 
        You may adjust the sensitivity of the IR Sensor 
        By using a screwdriver to adjust the potentiometer on the IR Sensor module
    */
}
