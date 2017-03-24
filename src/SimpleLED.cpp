#include "Arduino.h"
#include "SimpleLED.h"

SimpleLED::SimpleLED(const int arr[3]) 
{
	this->brightness = 255;
	for (int i = 0; i < 3; i++)
		this->backcol[i] = 0;
	memcpy(this->ledarray, arr, sizeof(arr) * 3);
	for (int i = 0; i < 3; i++) 
	{
	   pinMode(arr[i], OUTPUT);     
	}
	this->Flush();
}

void SimpleLED::SetColor(int r, int g, int b)
{
	int arr[3] = {r, g, b};
	for (int i = 0; i < 3; i++)
	{
	  analogWrite(this->ledarray[i], (int)(arr[i] * (brightness / 255.0)));
	}
	memcpy(this->backcol, arr, sizeof(arr) * 3);
}

void SimpleLED::SetHSVColor(double H, double S, double V)
{
  double P, Q, T, fract;
  float R, G, B;

  (H == 360.)?(H = 0.):(H /= 60.);
  fract = H - floor(H);

  P = V*(1. - S);
  Q = V*(1. - S*fract);
  T = V*(1. - S*(1. - fract));

  if (0. <= H && H < 1.) {
	R = V; 
	G = T; 
	B = P;
  }
  else if (1. <= H && H < 2.) {
	R = Q; 
	G = V; 
	B = P;
  }
  else if (2. <= H && H < 3.) {
	R = P; 
	G = V; 
	B = T;
  }
  else if (3. <= H && H < 4.) {
	R = P; 
	G = Q; 
	B = V;
  }
  else if (4. <= H && H < 5.) {
	R = T;
	G = P;
	B = V;
  }
  else if (5. <= H && H < 6.) {
	R = V; 
	G = P; 
	B = Q;
  }
  else {
	R = 0.0;
	G = 0.0;
	B = 0.0;
  }
  this->SetColor((int)(R * 255.0), (int)(G * 255.0), (int)(B * 255.0));
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
	int clrarr[3];
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
