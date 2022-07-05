#include "max6675.h" 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
 
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
// Temperature Sensor1
int thermo1D0 = 4; // so
int thermo1CS = 5; 
int thermo1CLK = 6; // sck
float temp1 = 0; 
MAX6675 thermocouple1(thermo1CLK, thermo1CS, thermo1D0); 
 
void setup()
{
  Serial.begin(9600); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);
    display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop()
{
  temp1 = thermocouple1.readCelsius(); 
  delay(250);

    //clear display
  display.clearDisplay();


 // display.setTextSize(1);
 // display.setCursor(0,0);
 // display.print("Temp1: ");
  display.setTextSize(4);
  display.setCursor(0,0);
  display.print(temp1);
  display.setTextSize(1);
  display.print("C");

 display.display();
  
}
