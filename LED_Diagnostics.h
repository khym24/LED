#define redPin 3
#define bluePin 6
#define greenPin 5

class LED_Diagnostics
{
public:
  void statusCheck(int fix);
  
private:
  boolean CHECK_BMP(void);
  boolean SD_CHECK(void);
  void displayLED(void);
  
}
