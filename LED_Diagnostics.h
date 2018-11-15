#define redPin 3
#define bluePin 6
#define greenPin 5

class LED_Diagnostics
{
public:
  void statusCheck(int fix);
  // led object takes parameters that indicate the readiness of:
  // GPS satellite & communication: fix
  // BMP: wip...
  // SD: ...
  
private:
  boolean CHECK_BMP(void);    // check functions, wip, might not even need
  boolean SD_CHECK(void);
  void displayLED(void);      // outputs the colours
  
}
