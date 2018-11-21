#ifndef MacRocketry_LED_Diagnostics_h
#define MacRocketry_LED_Diagnostics_h

#define redPin 3
#define bluePin 6
#define greenPin 5

class MacRocketry_LED_Diagnostics {
  public:
    MacRocketry_LED_Diagnostics(void);  //constructor
    void statusCheck(void);
  
  private:
    int err;
  
    void start(void);
    boolean CHECK_GPS(void);
    boolean CHECK_BMP(void); 
    boolean CHECK_SD(void);
    void displayLED(int msg);
};

#endif
