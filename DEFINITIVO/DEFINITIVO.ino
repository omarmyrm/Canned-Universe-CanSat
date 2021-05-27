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
              String dataPressTemp = getDataPressTemp();// get the data as a string to write it to the SD card and print it on the serial monitor
              float tempOLED = tempForOLED();// get the temp from the sensors to print it in the OLED display
              float pressOLED = pressForOLED();//get the pressure from the sensors to print it in the OLED display
              int metersHigh = gps.altitude.meters();// get the altitude from the GPS to print in the OLED display      
              Serial.print(dataPressTemp);// send the information via radio
              displayGPS();// send the GPS information via radio (*SHOULD CHANGE THE NAME OF THIS*)
              Serial.println("$");//final character of the sequence of information via radio
                
                
              logToSD(dataPressTemp,metersHigh,SDcardWorking);// store in the SD card only the temp,press and altitude data.

        
              //display the data in the OLED display
              displayTemperatura(tempOLED);
              displayPressure(pressOLED);
              displayAltitude(metersHigh);
              //
                
              //delay(100);// we are using a "smart delay" with the ms thing instead of delay
              ++packetsSend;// we have send one packet of information, so we increment the number by 1, 
             
            } 
           
      }
       myFile.close();// everything is inside the setup because it is easier to write to the file when you only close it once. 
      //that is why there is that shitty loop, REMEMBER TO CLOSE the file so it saves it to the SD
}

void loop() {
  }
