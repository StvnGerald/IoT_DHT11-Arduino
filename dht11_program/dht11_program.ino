#include "DHT.h"

#define DHTPIN 2     // Line pin data (out) sensor, pada kasus ini di pin 2/D2
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("Memulai pembacaan sensor...");
  dht.begin();
}

void loop() {
  delay(2000); // Ini jeda refresh data pada layar, muncul tiap 2 detik

  float humidity = dht.readHumidity();
  float celsius = dht.readTemperature();
  float fahrenheit = (dht.readTemperature() *9.0/5.0) + 32;


  // Untuk memeriksa apakah pembacaan data gagal atau berhasil
  if (isnan(humidity) || isnan(celsius) || isnan(fahrenheit)) {
    Serial.println("Gagal membaca dari sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(fahrenheit, humidity);

  Serial.print("Kelembapan: ");
  Serial.print(humidity);
  Serial.print("%  Suhu: ");
  Serial.print(celsius);
  Serial.print("°C  ");
  Serial.print(fahrenheit);
  Serial.print("°F  ");
  Serial.print(F("|  Indeks Panas: "));
  Serial.print(hif);
  Serial.println(F("°F"));
}