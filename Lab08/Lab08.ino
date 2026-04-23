#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>
#include <DHT.h>

// TFT (Arduino UNO)
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// DHT22
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  tft.begin();
  dht.begin();

  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);

  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 20);
  tft.println("LAB 08 UNO");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  tft.fillRect(0, 60, 320, 180, ILI9341_BLACK);

  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.setCursor(20, 80);
  tft.print("Temp: ");
  tft.print(temp);
  tft.println(" C");

  tft.setTextColor(ILI9341_GREEN);
  tft.setCursor(20, 140);
  tft.print("Hum: ");
  tft.print(hum);
  tft.println(" %");

  delay(2000);
}