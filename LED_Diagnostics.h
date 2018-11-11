#define redPin 3
#define bluePin 6
#define greenPin 5

class LED_Diagnostics
{
public:
  void statusCheck(void);
  
private:
  boolean GPS_COM_CHECK(void);
  boolean GPS_SAT_CHECK(void);
  boolean CHECK_BMP(void);
  boolean SD_CHECK(void);
  void displayLED(void);
  
}
