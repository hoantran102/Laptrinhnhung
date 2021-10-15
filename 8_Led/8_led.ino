#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHTTYPE);
void setup(){
Serial.begin(9600);
  delay(500);
  Serial.println("Welcome to Microdigisoftn");
  delay(500);
  Serial.println("DHT11 Humidity & temperature Sensornn");
  delay(1000);//Wait before accessing Sensor
 }
void loop(){
   float t= dht.readHumidity();
   float x= dht.readTemperature();
   Serial.print("Humidity = ");
    Serial.print(t);
    Serial.println("%  ");
    Serial.print("Temperature = ");
    Serial.print(x); 
    Serial.println("C  ");
    Serial.println("");
delay(2000);   
 }
