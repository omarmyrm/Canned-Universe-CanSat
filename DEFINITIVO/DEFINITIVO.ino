/*
CANSAT 2021
Equipo Canned Universe
IES Andres de Vandelvira e IES Ramon y Cajal(Albacete)
DATE:25-01-2020
*/

#include "libPressTemp.h"
#include "libGPS.h"
#include "libOLED.h"

void setup() {
  Serial.begin(9600);
  initGPS();
  initPressTemp();
  initOLED();
  // put your setup code here, to run once:

}

void loop() {
  
  Serial.print(getDataPressTemp());
  Serial.print(getDataGPS());
  Serial.print("*");
  displayTemperatura(tempForOLED());
  displayPressure(pressForOLED());
  displayAltitude(altitudeForOLED());
  delay(1000);

}
