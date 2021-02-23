#include "FastLED.h"

CRGB leds[1];
void setup_led() {
  FastLED.addLeds<NEOPIXEL, 2>(leds, 1); 
}

void showcolor(String color) {
  if (color == "off") {
    FastLED.showColor(CRGB(0, 0, 0));
  } 
  else if (color == "white") {
    FastLED.showColor(CRGB(255, 255, 255));
  } 
  else if (color == "red") {
    FastLED.showColor(CRGB(255, 0, 0));
  } 
  else if (color == "green") {
    FastLED.showColor(CRGB(0, 255, 0));
  } 
  else if (color == "blue") {
    FastLED.showColor(CRGB(0, 0, 255));
  } 
  else if (color == "yellow") {
    FastLED.showColor(CRGB(255, 255, 0));
  } 
  else if (color == "cyan") {
    FastLED.showColor(CRGB(0, 255, 255));
  } 
  else if (color == "magenta") {
    FastLED.showColor(CRGB(255, 0, 255));
  } 
  else {
    FastLED.showColor(CRGB(0, 0, 0));
  }
}
