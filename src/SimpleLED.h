#pragma once

enum {
	SL_WHITE = 0,
	SL_RED = 1,
	SL_GREEN = 2,
	SL_BLUE = 3,
};

struct SL_RGB
{
	byte r, g, b;
};

struct SL_PIN
{
	int r, g, b;
};

class SimpleLED
{
    public:
      SimpleLED(int r, int g, int b);
      void SetColor(byte r, byte g, byte b);
      bool SetDefColor(int num);
      void SetHSVColor(float h, float s, float v);
      SL_RGB GetColor();
      void SetBrightness(float value);
      void Flush();
    private:
      float brightness;
      const SL_RGB defclr[4] = {
	  {255, 255, 255},
	  {255, 0, 0},
          {0, 255, 0},
	  {0, 0, 255},
      };
      SL_PIN pins;
      SL_RGB backcol = {0, 0, 0};
};
