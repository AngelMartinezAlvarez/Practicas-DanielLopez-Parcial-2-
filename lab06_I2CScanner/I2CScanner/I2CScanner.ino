#include <DHT.h>

#define DHTPIN 2       // Pin donde conectaste DATA
#define DHTTYPE DHT22  // Tipo de sensor

DHT dht(DHTPIN, DHTTYPE);

unsigned long ultimaLectura = 0;

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Lab 06 - Sensor DHT22");
  Serial.println("Temp(C) | Humedad(%)");
}

void loop() {
  if (millis() - ultimaLectura >= 3000) {
    ultimaLectura = millis();

    float temp = dht.readTemperature();
    float hum  = dht.readHumidity();

    if (isnan(temp) || isnan(hum)) {
      Serial.println("Error leyendo el sensor");
      return;
    }

    Serial.print(temp);
    Serial.print(" C | ");
    Serial.print(hum);
    Serial.println(" %");
  }
}
void setup() {}
void loop() {}

