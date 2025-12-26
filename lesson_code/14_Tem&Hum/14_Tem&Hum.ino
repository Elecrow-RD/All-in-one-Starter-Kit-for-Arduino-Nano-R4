#include "DHT20.h"      // Include DHT20 temperature and humidity sensor library

DHT20 dht;              // Create a DHT20 sensor object

void setup()
{
  Serial.begin(115200); // Initialize serial communication at 115200 baud rate
  Wire.begin();         // Initialize I2C bus (ESP32 default: SDA=21, SCL=22)
  dht.begin();          // Initialize the DHT20 sensor
}

void loop()
{
  // Read temperature and humidity data from DHT20 sensor
  if (dht.read() == DHT20_OK)
  {
    Serial.print("Temperature: ");
    Serial.print(dht.getTemperature(), 1); // Get temperature in Celsius (1 decimal place)
    Serial.print(" °C\t");

    Serial.print("Humidity: ");
    Serial.print(dht.getHumidity(), 1);    // Get relative humidity in percent (1 decimal place)
    Serial.println(" %");
  }
  else
  {
    Serial.println("DHT20 read failed");   // Print error message if sensor read fails
  }

  delay(1000);  // Wait 1 second before the next reading (DHT20 requires sufficient interval)
}
