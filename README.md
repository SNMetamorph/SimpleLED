# SimpleLED
This library allows you to control LEDs, library includes these functions: defined or manual RGB and HSV color setting, brigthness adjustment. For using it you need have 3 free digital PWM pins (3, 5, 6 for example).

# Schematic
You may using this library for LED strips or LEDs group. Also, you need to make scheme given below for controlling LED strips.
Scheme for using with strip:

![Preview](https://github.com/SNMetamorph/SimpleLED/blob/master/mosfetscheme.png?raw=true)

Scheme for using with LEDs group:

![Preview](https://github.com/SNMetamorph/SimpleLED/blob/master/ledscheme.png?raw=true)
# Installation
At first, download this git at .zip

# Functions
<b>void SetColor (int red, int green, int blue)</b> - setting color value for every channel.<br>
<b>void SetHSVColor (double hue, double saturation, double brightness)</b> - setting color for every channel using HSV color model.<br>
<b>bool SetDefColor(int num)</b> - setting defined color (see Color defines topic).<br>
<b>void SetBrightness (float value)</b> - setting brightness for all color channels.<br>
<b>void Flush()</b> - off all color channels, equal to SetColor(0, 0, 0).<br>


