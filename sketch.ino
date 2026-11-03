#include <DHT.h>
#define DHTPIN 15       
#define DHTTYPE DHT22   
#define LEDPIN 2        

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  
  Serial.println("==================================");
  Serial.println("IoT Day 1: ESP32 + DHT22 Started!");
  Serial.println("==================================");
  
  dht.begin();
}

void loop() {
  delay(2000); 
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); 

  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error: Failed to read from DHT sensor!");
    return; 
  }

  digitalWrite(LEDPIN, HIGH);
 
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(200);
  digitalWrite(LEDPIN, LOW); 
}
