#include <DHT.h>

#include <Adafruit_Sensor.h>

#define DHTPIN 32

#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

void setup(){
  Serial.begin(115200);
  Serial.println(F("DHTxx Test"));

  dht.begin();
}

void loop(){
  delay((2000));

  float h = dht.readHumidity();

  float t = dht.readTemperature(false);
  float f = dht.readTemperature(true);

  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F("Faled to read "));
    return;
  }
  float heatIndexC = dht.computeHeatIndex(t, h,false);
  float heatIndexF = dht.computeHeatIndex(f, h,true);

  // Print results
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" °C");

  Serial.print("Temperature: ");
  Serial.print(f);
  Serial.println(" °F");

  Serial.print("Heat Index: ");
  Serial.print(heatIndexC);
  Serial.println(" °C");

  Serial.print("Heat Index: ");
  Serial.print(heatIndexF);
  Serial.println(" °F");

  Serial.println("--------------------");
}
