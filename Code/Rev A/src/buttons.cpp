#include <buttons.h>
#include <parameters.h>

uint8_t button1state;
uint8_t button2state;
uint8_t button3state;
uint8_t button1prevstate;
uint8_t button2prevstate;
uint8_t button3prevstate;

unsigned long timeNowButton1 = 0;
unsigned long timeNowButton2 = 0;
unsigned long timeNowButton3 = 0;
unsigned long lastTimePressedButton1 = 0;
unsigned long lastTimePressedButton2 = 0;
unsigned long lastTimePressedButton3 = 0;

uint8_t brightnessIndex = 0;
// Make sure there are BRIGHTNESS_COUNT elements in the array.
uint8_t brightness[BRIGHTNESS_COUNT] = {10,  15,  20,  40,  60,
                                        100, 140, 180, 220, 240};

uint8_t programIndex = 1; // start at 1

bool firstRun = 1;

void button1PressAction(void)
{
  leds[NUMPIXELS - 1] = CRGB(128, 0, 0);
  FastLED.show();
  /*
  if (programIndex++ >= NUM_PROGRAMS)
  {
    programIndex = 1;
  }
  */
}

void button2PressAction(void)
{

  leds[NUMPIXELS - 1] = CRGB(0, 128, 0);
  FastLED.show();
  /*
  if (brightnessIndex++ >= BRIGHTNESS_COUNT - 1)
  {
    brightnessIndex = 0;
  }
  FastLED.setBrightness(brightness[brightnessIndex]);
  FastLED.show();
  */
}

void button3PressAction(void)
{

  leds[NUMPIXELS - 1] = CRGB(0, 0, 128);
  FastLED.show();
  /*
  if (brightnessIndex++ >= BRIGHTNESS_COUNT - 1)
  {
    brightnessIndex = 0;
  }
  FastLED.setBrightness(brightness[brightnessIndex]);
  FastLED.show();
  */
}

void checkButton1(void)
{
  bool buttonState = digitalRead(BUTTON1);
  if (buttonState == 0) // pressed
  {
    timeNowButton1 = millis();
    if (timeNowButton1 - lastTimePressedButton1 > DEBOUNCEDELAY)
    {
      button1PressAction();
      lastTimePressedButton1 = timeNowButton1;
    }
  }
}

void checkButton2(void)
{
  bool buttonState = digitalRead(BUTTON2);
  if (buttonState == 0) // pressed
  {
    timeNowButton2 = millis();
    if (timeNowButton2 - lastTimePressedButton2 > DEBOUNCEDELAY)
    {
      button2PressAction();
      lastTimePressedButton2 = timeNowButton2;
    }
  }
}

void checkButton3(void)
{
  bool buttonState = digitalRead(BUTTON3);
  if (buttonState == 0) // pressed
  {
    timeNowButton3 = millis();
    if (timeNowButton3 - lastTimePressedButton3 > DEBOUNCEDELAY)
    {
      button3PressAction();
      lastTimePressedButton3 = timeNowButton3;
    }
  }
}
