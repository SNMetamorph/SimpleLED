# SimpleLED
This library allows you to control LEDs using Arduino, library includes these functions: defined or manual RGB and HSV color setting, brigthness adjustment. For using it you need have 3 free digital PWM pins (3, 5, 6 for example).

# Using example
```c++
#include <SimpleLED.h>

SimpleLED diode(3, 5, 6); // using pin 3 - for red, 5 - for green, 6 - for blue, pins must be digital PWM.
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
```

# Schematic
You may using this library for LED strips or LEDs group. Also, for controlling LED strips you need to make scheme given below three times for every color channel.<br>
Warning! Use only suitable voltage power supplies, otherwise you risk to burn your LED strip.<br>
Scheme for using with strip:

![Preview](https://github.com/SNMetamorph/SimpleLED/blob/master/mosfetscheme.png?raw=true)

Scheme for using with LEDs group:

![Preview](https://github.com/SNMetamorph/SimpleLED/blob/master/ledscheme.png?raw=true)

# Installation
At first, download this git at .zip (click <a href="https://github.com/SNMetamorph/SimpleLED">this</a> -> click Clone or download -> Download ZIP). Open Arduino IDE -> click "Sketch" menu -> Include Library -> Add .ZIP Library -> find and select downloaded zip-file.<br> Installing completed.

# Functions
<b>void SetColor(byte red, byte green, byte blue)</b> - setting color value for every channel.<br>
<b>void SetHSVColor(float hue, float saturation, float brightness)</b> - setting color for every channel using HSV color model.<br>
<b>bool SetDefColor(int num)</b> - setting defined color (see Defined colors topic).<br>
<b>void SetBrightness(float value)</b> - setting brightness for all color channels.<br>
<b>void Flush()</b> - turn off all color channels, equal to SetColor(0, 0, 0).<br>

# Defined colors
Topic struct: color define name - integer number of color - SetColor() equal.<br>
Example of using defines in code: obj.SetDefColor(SL_GREEN) or obj.SetDefColor(2).<br>
SL_WHITE - 0 - obj.SetColor(255, 255, 255)<br>
SL_RED - 1 - obj.SetColor(255, 0, 0)<br>
SL_GREEN - 2 - obj.SetColor(0, 255, 0)<br>
SL_BLUE - 3 - obj.SetColor(0, 0, 255)<br>

