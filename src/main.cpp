#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

void refresh_readings(); // Declare in the header so that the compiler knows about it before it is called in loop()

#ifndef LED_BUILTIN
#define LED_BUILTIN 2 // This is valid for my devkit
#endif

#define SEALEVELPRESSURE_HPA (1013.25)
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
  refresh_readings();
  delay(2000);
}

