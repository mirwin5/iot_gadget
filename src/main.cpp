#include <Arduino.h>
#include "sensor_readings.h"
#include "TFT_eSPI.h" // Hardware-specific library
#include "settings.h"

Adafruit_BME280 bme; // I2C

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

uint16_t bg = TFT_BLACK;
uint16_t fg = TFT_WHITE;

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  tft.init();

  tft.setRotation(1);
  tft.setTextColor(fg, bg);
  tft.fillScreen(bg);

  tft.setCursor(0,0);
  tft.println("Hello");
  tft.println("Starting BME Sensor...");
  delay(5000);

  bool status;

  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);

  if (!status)
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1)
      ;
  }

  tft.fillScreen(bg); //Clear the screen
}

void loop()
{
  // put your main code here, to run repeatedly:
  refresh_readings(bme);
  delay(2000);
}
