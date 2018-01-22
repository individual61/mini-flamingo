#include <Arduino.h>
#include <FastLED.h>
#include <buttons.h>
#include <parameters.h>
/*
ICSP header is, looking down on pins (not looking into female cable):

1  MISO    2 VCC
3 SCK      4 MOSI
5 RST      6 GND

ATTiny85:

1 RST   5 VCC
2 NC    6 SCK
3 NC    7 MISO
4 GND   8 MOSI

*/

CRGB leds[NUMPIXELS];

void setup()
{
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);

  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUMPIXELS)
      .setCorrection(CORRECTION);

  leds[NUMPIXELS - 1] = CHSV(128, 0, 128);
  FastLED.show();
  // put your setup code here, to run once:
}

void loop()
{

  // Buttons
  checkButton1();
  checkButton2();
  checkButton3();
}
