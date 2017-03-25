#define SL_WHITE 0
#define SL_RED 1
#define SL_GREEN 2
#define SL_BLUE 3

class SimpleLED 
{
    public:            
      SimpleLED(int arr[3]);
      void SetColor(byte r, byte g, byte b);
      void SetHSVColor(float h, float s, float v);
      void SetBrightness(float value) ;
      void Flush();
      bool SetDefColor(int num);
    private:
      int ledarray[3];
      float brightness;
      byte backcol[3];
};
