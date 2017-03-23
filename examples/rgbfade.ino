#include <SimpleLED.h>

const int led[3] = {3, 5, 6}; // using pin 3 - for red, 5 - for green, 6 - for blue, pins must be digital PWM.
SimpleLED diode(led);
float progress = 0;
float val = 0.025;

void setup() 
{
  diode.SetDefColor(SL_WHITE); // set all colors for maximum
}

void loop() 
{
  diode.SetBrightness(progress); // set new brightness at every iteration
  progress = progress + val;
  if (progress <= 0 || progress >= 255) {
    val = -val;
  }
}