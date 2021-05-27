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

unsigned double packetsSend = 1;// change data type from long to double, to avoid errors in a later division
unsigned long double a;// to store millis() as a double, to avoid losing information in a later division
bool SDcardWorking = false;// this is then set to true when the SDcard starts working, we assume it doesn't stop working during the program.


void setup(){
      Serial.begin(9600);
      initGPS();// starts the GPS from its .h file
      initPressTemp();// starts the BMP180 from its .h file
      initOLED();// starts the display from the .h file
      SDcardWorking = initSD();// start the SD and check if it's working or not

      while(packetsSend<100){// ONLY SENDS 100 PACKETS, controls the execution of the program. CHANGE THIS to a GOOD condition to stop the program
         a = millis();// number of ms since the start of the program
 
          if( packetsSend > a /1000 )// *trick* for ONLY sending the data once every second
          {
          }else{
              String dataPressTemp = getDataPressTemp();
              float tempOLED = tempForOLED();
              float pressOLED = pressForOLED();
              int metersHigh = gps.altitude.meters();
              Serial.print(dataPressTemp);
              displayGPS();
              logToSD(dataPressTemp,metersHigh,SDcardWorking);
              Serial.println("$");
        
              
              displayTemperatura(tempOLED);
              displayPressure(pressOLED);
              displayAltitude(metersHigh);
              //delay(100);// we are using a "smart delay" with the ms thing instead of delay
              ++packetsSend;
             
            } 
           
      }
       myFile.close();
}

void loop() {
  }
