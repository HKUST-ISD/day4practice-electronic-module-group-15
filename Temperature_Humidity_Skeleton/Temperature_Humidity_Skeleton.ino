/*Replace ? in the code to read the temperature and Humidity */
#include <DHT.h>
#include <Arduino.h>
#define DHT11_PIN  38 // Select a ESP32 pin connected to DHT11 sensor Signal

DHT dht11(DHT11_PIN, DHT11);

void setup() {
  Serial.begin(9600); // ***Start the serial communication (baud rate as 9600).***
  dht11.begin(); // initialize the DHT11 sensor 
}

void loop() {
  /*Do not change below code*/
  // read humidity
  float humi  = dht11.readHumidity();
  // read temperature in Celsius
  float tempC = dht11.readTemperature();
  // read temperature in Fahrenheit
  float tempF = dht11.readTemperature(true);

  // check whether the reading is successful or not
  if ( isnan(tempC) || isnan(tempF) || isnan(humi)) //nan "Not-a-Number" (NaN) value 
  {
    Serial.println("Failed to read from DHT11 sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C  ~  ");
    Serial.print(tempF);
    Serial.println("°F");
  }
  /*Do not change above code*/

 // DHT sensor is very slow getting the readings (the sensor readings may take up to 2 seconds) 
  delay(2000);  // wait 2 seconds between readings delay(ms) The function admits a number of milliseconds to pause
}
