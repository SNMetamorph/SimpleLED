#include "Arduino.h"
#include "SimpleLED.h"

SimpleLED::SimpleLED(int r, int g, int b) 
{
	brightness = 255;
	pins = (SL_PIN){r, g, b};
	pinMode(pins.r, OUTPUT);
	pinMode(pins.g, OUTPUT);
	pinMode(pins.b, OUTPUT);
	Flush();
}

void SimpleLED::SetColor(byte r, byte g, byte b)
{
	analogWrite(pins.r, r * (brightness / 255.0));
	analogWrite(pins.g, g * (brightness / 255.0));
	analogWrite(pins.b, b * (brightness / 255.0));
	backcol = (SL_RGB){r, g, b};
}

void SimpleLED::SetHSVColor(float h, float s, float v) 
{
  int i;
  float f, p, q, t;
  byte r, g, b;
  
  h = max(0.0, min(360.0, h));
  s = max(0.0, min(100.0, s));
  v = max(0.0, min(100.0, v));
  
  s /= 100;
  v /= 100;
  
  if(s == 0) {
	r = g = b = round(v*255); // Achromatic (grey) 
    return;
  }

  h /= 60; // sector 0 to 5
  i = floor(h);
  f = h - i; // factorial part of h
  p = v * (1 - s);
  q = v * (1 - s * f);
  t = v * (1 - s * (1 - f));
  switch(i) {
    case 0:
      r = round(255*v);
      g = round(255*t);
      b = round(255*p);
      break;
    case 1:
      r = round(255*q);
      g = round(255*v);
      b = round(255*p);
      break;
    case 2:
      r = round(255*p);
      g = round(255*v);
      b = round(255*t);
      break;
    case 3:
      r = round(255*p);
      g = round(255*q);
      b = round(255*v);
      break;
    case 4:
      r = round(255*t);
      g = round(255*p);
      b = round(255*v);
      break;
    default:
      r = round(255*v);
      g = round(255*p);
      b = round(255*q);
    }
	SetColor(r, g, b);
}

void SimpleLED::SetBrightness(float value) 
{
	brightness = value;
	SetColor(backcol.r, backcol.g, backcol.b);
}

bool SimpleLED::SetDefColor(int num)
{
	SL_RGB def;
	def = defclr[num];
	SetColor(def.r, def.g, def.b);
	return true;
}
