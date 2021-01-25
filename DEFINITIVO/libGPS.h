#include <TinyGPS++.h>
#include <HardwareSerial.h>


#define RXPin 16
#define TXPin 17
#define GPSBaud 9600


TinyGPSPlus gps;
HardwareSerial SerialGPS(1);

void initGPS()
{
	SerialGPS.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin);
}
String getDataGPS()
{
	return String(gps.location.lat())+","+(gps.location.lng())+","+
	(gps.altitude.meters())+","+(gps.time.hour())+","+(gps.time.minute()) +","+(gps.time.second());
}
double altitudeForOLED()
{
	return gps.altitude.meters();
}
