#include <Arduino.h>
#include "sensor_readings.h"
#include "settings.h"

Adafruit_BME280 bme; // I2C

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  bool status;

  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);

  if (!status)
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1)
      ;
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  refresh_readings(bme);
  delay(2000);
}
