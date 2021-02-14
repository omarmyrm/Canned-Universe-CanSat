#include <SPI.h>
#include "SD.h"
#define fileName ".TXT"// establecer el nombre del archivo a abrir
File myFile;
 
bool cardFailed = false;

 
void initSD(){
    Serial.begin(9600);
    SD.begin(5);
    myFile = SD.open(fileName, FILE_WRITE);
    myFile.println("inicio escritura de datos\n\n\n");
    myFile.println("Temperatura\tPresion\n");
}
void logToSD (String a, int x)
{
    String data1 = a;
    int data2 = x;
         if(myFile)
         {    
              myFile.print(data1);
              myFile.print(data2);
              myFile.println("$");  
         }
}
