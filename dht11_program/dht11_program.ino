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

  float kelembapan = dht.readHumidity();
  float celsius = dht.readTemperature();
  float fahrenheit = (dht.readTemperature() *9/5) + 32;

  // Untuk memeriksa apakah pembacaan data gagal atau berhasil
  if (isnan(kelembapan) || isnan(celsius) || isnan(fahrenheit)) {
    Serial.println("Gagal membaca dari sensor!");
    return;
  }

  Serial.print("Kelembapan: ");
  Serial.print(kelembapan);
  Serial.print("%  Suhu: ");
  Serial.print(celsius);
  Serial.print("°C  ");
  Serial.print(fahrenheit);
  Serial.println("°F");
}