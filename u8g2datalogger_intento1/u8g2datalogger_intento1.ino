
//preuba OLED u8g2
//CANNED UNIVERSE V0.2
////////////WIRING//////////////
/*
  OLED: SDA y SCL por defecto y 3v3
  DS18b20: 5 y 5v
  
  SD card adapter:
  VCC: 5V
  GND: GND
  MOSI: 11
  MISO: 12
  SCK: 13
  CS: 4

  baromentro+temp+giro
  SCL, SDA (A5,A4) 3.3V
*/
///////////////////////////////

//OLED u8g2 libraries
#include <U8g2lib.h>

//BMP280
#include <Adafruit_BMP280.h>


//OLED+dallas libraries
#include <Wire.h>   // libreria para bus I2C
#include <DallasTemperature.h>

//SD LIBRARIES
#include <SPI.h>
#include <SD.h>

//OLED
//#include <Arduino.h>
//#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // Adafruit Feather ESP8266/32u4 Boards + FeatherWing OLED
//float numero = 0.0;
//TEMPERATURA

//const int oneWirePin = 5;
//OneWire oneWireBus(oneWirePin);
OneWire oneWireBus(5);
DallasTemperature sensor(&oneWireBus);

//SD
const int chipSelect = 4;

//BMP280
Adafruit_BMP280 bmp;



void setup() {
  //OLED setup
  //u8g2.begin();
  //setup SD
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  //  while (!Serial) {
  //    ;      // wait for serial port to connect. Needed for native USB port only
  //  }


  Serial.print("Initi. SD");


  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println(F("Card failed"));
    
    // don't do anything more:
    while (1);


  }
  Serial.println(F("sd ok"));


  //Temperatura setup
  sensor.begin();

                                                                              
  // BMP280
  if (!bmp.begin()) {
    Serial.println(F("bmp280 error"));
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  
  
}

void loop() {
  //TEMPERATURA
  // Serial.println("Leyendo temperaturas: ");
  sensor.requestTemperatures();

  Serial.print(F("DS18b20: "));
  Serial.print(sensor.getTempCByIndex(0));
  Serial.println(F(" ºC"));
  delay(500);

  //bmp280
Serial.print(bmp.readTemperature());
Serial.print(", ");
Serial.println(bmp.readPressure());
 delay (200);

  //SD


  // make a string for assembling the data to log:
  String dataString = "";
  dataString += String(millis());
  dataString += ";";
  dataString += String(sensor.getTempCByIndex(0));
  dataString += ";";
  dataString += String(bmp.readTemperature());
  dataString += ";";
  dataString += String(bmp.readPressure());
  //dataString += ";";
  //dataString += String(bmp.readAltitude(1013.25));
  delay (300);
  Serial.println(dataString);

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.csv", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(F("saved"));
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println(F("error opening datalog.csv"));
  }

  delay(200);


//OLED
//  u8g2.clearBuffer();          // clear the internal memory
//  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
//  u8g2.setCursor(0, 10);
//  u8g2.print(dataString);
//  u8g2.sendBuffer();          // transfer internal memory to the display
//  delay(100);

}
