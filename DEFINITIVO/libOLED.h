#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1// pin used to reset, if there is not an specific pin its value is -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,&Wire, OLED_RESET);

void initOLED()
{
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	
}
void bootScreen()
{
  display.clearDisplay();
 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,16);
  display.println("retrieving information");
  
  display.display();
  delay(2000);//display for 2 seconds, REMOVE AFTER TESTING
}
void displayTemperatura(float x)
{     
      float temp = x;
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.print("Temp:");
      display.setCursor(0,16);
      display.setTextSize(1);
      display.print(temp);
      display.cp437(true);
      display.write(167);
      display.setTextSize(1); 
      display.println("C");
      
      display.display();
}
void displayPressure(float y)
{
      float presion = y;
      
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(64,0);
      display.print("Press:");
      display.setCursor(64,16);
      display.print(presion);
      display.setTextSize(1);
      display.println("hPa");

      display.display();
}
void displayAltitude(double m)
{
      double metersHigh = m;
      
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,32);
      display.print("Altitud:");
      display.setCursor(0,48);
      display.print(metersHigh);
      display.setTextSize(1);
      display.println("m");

      display.display();
}

