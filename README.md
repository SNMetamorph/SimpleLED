# SimpleLED
This library allows you to control LEDs, library includes these functions: defined or manual RGB and HSV color setting, brigthness adjustment. For using it you need have 3 free digital PWM pins (3, 5, 6 for example).

# Schematic
You may using this library for LED strips or LEDs group. Also, for controlling LED strips you need to make scheme given below three times for every color channel.
Warning! Use only suitable voltage power supplies, otherwise you risk to burn your LED strip.
Scheme for using with strip:

![Preview](https://github.com/SNMetamorph/SimpleLED/blob/master/mosfetscheme.png?raw=true)

Scheme for using with LEDs group:

![Preview](https://github.com/SNMetamorph/SimpleLED/blob/master/ledscheme.png?raw=true)

# Installation
At first, download this git at .zip (click <a href="https://github.com/SNMetamorph/SimpleLED">this</a> -> click Clone or download -> Download ZIP). Open Arduino IDE -> click "Sketch" menu -> Include Library -> Add .ZIP Library -> find and select downloaded zip-file. Installing completed.

# Functions
<b>void SetColor (int red, int green, int blue)</b> - setting color value for every channel.<br>
<b>void SetHSVColor (double hue, double saturation, double brightness)</b> - setting color for every channel using HSV color model.<br>
<b>bool SetDefColor(int num)</b> - setting defined color (see Defined colors topic).<br>
<b>void SetBrightness (float value)</b> - setting brightness for all color channels.<br>
<b>void Flush()</b> - off all color channels, equal to SetColor(0, 0, 0).<br>

# Defined colors
Topic struct: color define name - integer number of color - SetColor() equal
Example of using defines in code: obj.SetDefColor(SL_GREEN) or obj.SetDefColor(2)
SL_WHITE - 0 - obj.SetColor(255, 255, 255)
SL_RED - 1 - obj.SetColor(255, 0, 0)
SL_GREEN - 2 - obj.SetColor(0, 255, 0)
SL_BLUE - 3 - obj.SetColor(0, 0, 255)
