#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <functional>
#include <vector>
#include <ModbusMaster.h>
#include <RTClib.h>
#include "mod_gpio.h"
#include "mod_timer.h"
#include "mod_oled.h"
#include "mod_modbusRTU.h"
#include "mod_RTC.h"
#include "dimming_led.h"
#include "mod_adc.h"

#define PIN_BTN_MODE 10
#define PIN_BTN_UP 1
#define PIN_BTN_DOWN 8
#define PIN_BTN_CHANGE 3
#define PIN_OLED_MOSI 7
#define PIN_OLED_CLK 6
#define PIN_OLED_DC 4
#define PIN_OLED_CS 5
#define PIN_OLED_RESET -1
#define PIN_MBRTU_TRIS 9
#define PIN_RTC_SDA 18
#define PIN_RTC_SCL 19
#define PIN_DIMM_LED 0
#define PIN_ADC_MEASURE 2
