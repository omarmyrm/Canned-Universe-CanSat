/*
programa q genera un rectangulo representando la lata del cansat
y refleja el cambio en la altitud de este


*/

import processing.serial.*;


float localAltitude = 700;
float cansatAltitude = 0;
float maxCansatAltitude = 0;
float convertedAltitude = 0;// altitud mappeada
float ground = 100; //suelo en pixeles pantalla de processing

float xPosRect = 200; //coordenada x del rectángulo
float rectangleWidth = 30;
float rectangleHeight = 50;

//lf es el caracter de retorno de carro, que en ASCII es 10
int lf = 10;
Serial myPort;

void setup() {

  size(400, 800);
  println(Serial.list());//Para localizar el numero de puerto
                         // en mi caso el 32.
  myPort = new Serial(this, Serial.list()[1], 9600);
 
}

void draw() {
  
  while (myPort.available() > 0) {
    String lectura = myPort.readStringUntil(lf);
     
    cansatAltitude = float(lectura);// tomar la altitude real del cansat
   
    
    if(cansatAltitude > maxCansatAltitude)
    {
      maxCansatAltitude = cansatAltitude;
      // si el CanSat está subiendo no mappear, y tb establece el valor máximo de altitud desde elq mappear
    } 
    

    convertedAltitude = map(cansatAltitude,localAltitude, maxCansatAltitude,ground,height);/* https://processing.org/reference/map_.html */
    //  mappear la altitud para q quepa en la pantalla
    if (cansatAltitude + rectangleHeight >= localAltitude + rectangleHeight) {
      background(#86BFFA);// color de fondo de la ventana
      
      text(cansatAltitude, 0, height-(height-50));
      text("Meters",64, height-(height-50));
      fill(#000000);
      
       // testing
      println(cansatAltitude);
      println(convertedAltitude); 
      // end testing
      
      rect(xPosRect, height - convertedAltitude,rectangleWidth,rectangleHeight);
      line(0, height - ground + rectangleHeight, width, height - ground + rectangleHeight);
      //dibujar una linea a "ground" pixeles de la ventana de processing
      //funciona perfecto, NO tocar :)
    }else
    {
      background(#000000);
      fill(#029B00);
      text("NO DATA AVAILABLE",0,100);
    }
  }
}
