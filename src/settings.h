#ifdef DEBUGLOG
#define DEBUGPRINT(x) Serial.print(x)
#define DEBUGPRINTDEC(x) Serial.print(x, DEC)
#define DEBUGPRINTLN(x) Serial.println(x)
#else
#define DEBUGPRINT(x)
#define DEBUGPRINTDEC(x)
#define DEBUGPRINTLN(x)
#endif

#ifndef SETTINGS_H
#define SETTINGS_H
#define LED_BUILTIN 2 // This is valid for my devkit
#include "TFT_eSPI.h" // ESP32 Hardware-specific library
#include "AdafruitIO_WiFi.h"
#include "network_config.h"
#include "ezTime.h"        // The time and date library
#include "aux_functions.h" // Helpful functions
#include "clock.h"
#include "EEPROM.h"
#include "esp_system.h" // To implement the watchdog
#include "mqtt_controller.h"

#define LED_PIN 17
#define S_OPEN_PIN_OUT 12
#define S_CLOSE_PIN_OUT 16
#define W_OPEN_PIN_OUT 33
#define W_CLOSE_PIN_OUT 25
#define H_LEVEL_PIN_IN 27
#define A_LEVEL_PIN_IN 32 // using pin 32 due to wifi usage
#define IFTTT_PIN 16
#define EEPROM_SIZE 2                           // We'll use 1 byte in the EEPROM to store the max number of POSTs
#define CALIBRATION_FILE "/tft-touch-calData_1" // This file will contain the data from the
                                                // touchscreen calibration process at boot (only needed once)
#endif