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
    }else
    {
       return false;
    }
}
void logToSD (String a, int x,bool f)
{   
 
 
    String data1 = a;
    int data2 = x;
    bool b = f;
         if(!b)
         {
         }else{ 
              myFile.print(data1);
              myFile.print(data2);
              myFile.println("$");      
         }
}
