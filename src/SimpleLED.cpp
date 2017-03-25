#include "Arduino.h"
#include "SimpleLED.h"

SimpleLED::SimpleLED(int arr[3]) 
{
	this->brightness = 255;
	for (register int i = 0; i < 3; i++)
		this->backcol[i] = 0;
	memcpy(this->ledarray, arr, sizeof(arr) * 3);
	for (register int i = 0; i < 3; i++)
	   pinMode(arr[i], OUTPUT);
	this->Flush();
}

void SimpleLED::SetColor(byte r, byte g, byte b)
{
	byte arr[3] = {r, g, b};
	for (register int i = 0; i < 3; i++)
	{
	  analogWrite(this->ledarray[i], arr[i] * (brightness / 255.0));
	}
	memcpy(this->backcol, arr, sizeof(arr) * 3);
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
	this->SetColor(r, g, b);
}

void SimpleLED::SetBrightness(float value) 
{
	this->brightness = value;
	this->SetColor(backcol[0], backcol[1], backcol[2]);
}

void SimpleLED::Flush()
{
	this->SetColor(0, 0, 0);
}

bool SimpleLED::SetDefColor(int num)
{
	byte clrarr[3];
	switch(num) 
	{
	  case 0: 
	  {
		clrarr[0] = 255;
		clrarr[1] = 255;
		clrarr[2] = 255;
		break;
	  }
	  
	  case 1:
	  {
		clrarr[0] = 255;
		clrarr[1] = 0;
		clrarr[2] = 0;
		break;
	  }
	  
	  case 2:
	  {
		clrarr[0] = 0;
		clrarr[1] = 255;
		clrarr[2] = 0;
		break;
	  }
	  
	  case 3:
	  {
		clrarr[0] = 0;
		clrarr[1] = 0;
		clrarr[2] = 255;
		break;
	  }
	  default: 
	  {
		return false;
		break;
	  }
	}
	this->SetColor(clrarr[0], clrarr[1], clrarr[2]);
	return true;
}
