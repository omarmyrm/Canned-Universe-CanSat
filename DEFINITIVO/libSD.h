#include <SPI.h>
#include "SD.h"
#define fileName "/log.TXT"

File myFile;
 
bool cardFailed = false;

 
bool initSD(){
    Serial.begin(9600);
    
   
    if(SD.begin(5))
    {  
    myFile = SD.open("/log.txt", FILE_WRITE);
    if(myFile)
      {
        myFile.println("Temperatura\tPresion\n");
        return true;
    }else
    {
      return false;
    } 
   
}
 // changed from void to bool so we can exit the function
bool logToSD (String a, int x,bool f) 
{   
    String data1 = a;
    int data2 = x;
    bool b = f;
         if(!b)
         {
          return false;
          // if the SD card is not working, it wont try to write to it
          // and exit the function          
         }else{ 
              myFile.print(data1);
              myFile.print(data2);
              myFile.println("$");      
              return true;
         }
}
