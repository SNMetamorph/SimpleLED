#define SL_WHITE 0
#define SL_RED 1
#define SL_GREEN 2
#define SL_BLUE 3

class SimpleLED 
{
    public:            
      SimpleLED (const int arr[3]);
      void SetColor (int r, int g, int b);
      void SetHSVColor(double H, double S, double V);
      void SetBrightness (float value) ;
      void Flush();
      bool SetDefColor(int num);
	private:
	  int ledarray[3];
      float brightness;
      int backcol[3];
};