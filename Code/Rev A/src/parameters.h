#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <Arduino.h>
#include <FastLED.h>
#include <buttons.h>

#define NUM_PROGRAMS 3

// Buttons
#define BUTTON1 1 // "Pin 1" in Arduino is chip pin #6
#define BUTTON2 3 // "Pin 3" in Arduino is chip pin #2
#define BUTTON3 4 // "Pin 4" in Arduino is chip pin #3
#define DEBOUNCEDELAY 300

#define BRIGHTNESS_COUNT 10 // Number of brightness levels

// FastLED stuff
#define NUMPIXELS 1     // Number of LEDs in strig
#define CLOCK_PIN 2     // "Pin 2" in Arduino is chip pin #7
#define DATA_PIN 0      // "Pin 0" in Arduino is chip pin #5
#define COLOR_ORDER BGR // my strip is BGR
#define CORRECTION TypicalLEDStrip
//#define CORRECTION UncorrectedColor

// General variables
extern uint8_t counter;
extern uint32_t timer;
extern uint8_t counter_every_10_8;

// Button variables
extern uint8_t button1state;
extern uint8_t button2state;
extern uint8_t button3state;
extern uint8_t button1prevstate;
extern uint8_t button2prevstate;
extern uint8_t button3prevstate;

extern unsigned long timeNowButton1;
extern unsigned long timeNowButton2;
extern unsigned long timeNowButton3;
extern unsigned long lastTimePressedButton1;
extern unsigned long lastTimePressedButton2;
extern unsigned long lastTimePressedButton3;

extern bool firstRun;

extern uint8_t brightnessIndex;
extern uint8_t brightness[BRIGHTNESS_COUNT];

extern uint8_t programIndex; // start at 1

// FastLED/Dotstar/APA102C variables
// extern uint32_t color;
extern CRGB color;
extern CRGB leds[NUMPIXELS];

#endif
