#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP280_ADDR 0x76  //Nuestra direccion I2C
Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();


void initPressTemp() {

  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

String getDataPressTemp() {

  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);
  return String(temp_event.temperature)+","+String(pressure_event.pressure)+",";;

}
float tempForOLED()
{
	sensors_event_t temp_event;
	bmp_temp->getEvent(&temp_event);
	return temp_event.temperature;
}
float pressForOLED()
{
	sensors_event_t pressure_event;
	bmp_pressure->getEvent(&pressure_event);
	return pressure_event.pressure;
	
}
