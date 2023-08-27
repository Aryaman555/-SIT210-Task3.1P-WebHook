#include <DHT.h>

#define DHTPIN 2       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22  // DHT 22 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Reading temperature takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (slow sensor)
  
  float temperature = dht.readTemperature();  // Read temperature in Celsius

  if (isnan(temperature)) {
    Serial.println("Failed to read temperature from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(2000);  // Wait for a few seconds before taking the next reading
}
