/*
CANSAT 2021
Equipo Canned Universe
IES Andres de Vandelvira e IES Ramon y Cajal(Albacete)
DATE:25-01-2020
*/


#include "libPressTemp.h"
#include "libGPS.h"
#include "libOLED.h"
#include "libSDcard.h"

long packetsSend = 1;
unsigned long a;// to store millis() 


void setup(){
      Serial.begin(9600);
      initGPS();
      initPressTemp();
      initOLED();
    
      initSD();
}

void loop() {
  
  a = millis();
 
  if( packetsSend > a /1000 )// packetsSend empieza siendo 1
  {
  }else{
      String dataPressTemp = getDataPressTemp();
      float tempOLED = tempForOLED();
      float pressOLED = pressForOLED();
      int metersHigh = gps.altitude.meters();
      Serial.print(dataPressTemp);
      displayGPS();
      logToSD(dataPressTemp,metersHigh);
      Serial.println("$");

      
      displayTemperatura(tempOLED);
      displayPressure(pressOLED);
      displayAltitude(metersHigh);
      delay(100);
      ++packetsSend;
     
    } 
    myFile.close();
  }
