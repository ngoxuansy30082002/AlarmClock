#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <functional>
#include <vector>
#include "mod_gpio.h"
#include "mod_timer.h"
#include "mod_oled.h"

#define PIN_BTN_MODE 0
#define PIN_BTN_UP 1
#define PIN_BTN_DOWN 2
#define PIN_BTN_CHANGE 3
// #define LED_PIN 2
#define PIN_OLED_MOSI 7
#define PIN_OLED_CLK 6
#define PIN_OLED_DC 5
#define PIN_OLED_CS 4
#define PIN_OLED_RESET 8
